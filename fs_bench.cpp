
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cstdint>
#include <random>
#include <chrono>
#include <thread>
#include <sstream>
#include <climits>
#include <algorithm>
#include <functional>
#include <fstream>

#if defined(_WIN32) || defined(WIN32)
#include "fs_bench_os_windows.hpp"
#else
#include "fs_bench_os_linux.hpp"
#endif

#define DIE(code, msg_content) std::cerr << msg_content << std::endl; return code
#define VARDUMP(var) std::cout << #var "=" << var << std::endl
// we'd like to use std::byte, but templates can't peer past the definition -_-
#define BYTE_T unsigned char


int main(int argc, char** argv) {
  // Read args + initialize test preconditions
  if (argc < 2) {
    DIE(1, "ARG1 should be a filesystem path to an empty folder which will be populated with test I/O activity.");
  }
  const std::filesystem::path test_folder = argv[1];
  VARDUMP(test_folder);

  const std::string folder_device_path = get_device_path(test_folder);
  VARDUMP(folder_device_path);

  bool test_is_anomalous = false;

  // Clean up any test artifacts by deleting the folder and re-creating it
  if (std::filesystem::exists(test_folder)) {
    std::filesystem::remove_all(test_folder);
  }

  while (std::filesystem::exists(test_folder)) {
    std::cout << "WARNING: We attempted to delete " << test_folder << " before the test but were somehow unsuccessful. Waiting for OS to complete folder deletion..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  if (!std::filesystem::exists(test_folder)) {
    std::filesystem::create_directories(test_folder);
  }
  else {
    test_is_anomalous = true;
    std::cout << "WARNING: We attempted to delete " << test_folder << " before the test but were somehow unsuccessful. Test will continue but results are now uncomparable to other tests." << std::endl;
  }

  std::random_device rand;
  std::default_random_engine rand_engine(rand());
  std::uniform_int_distribution<int_fast32_t> uniform_dist_bignums(0, INT_FAST32_MAX);
  std::independent_bits_engine<std::default_random_engine, CHAR_BIT, BYTE_T> random_bytes_engine;

  const int_fast32_t num_folders = 100;
  const int_fast32_t num_files_in_folder = 1000;
  const int_fast32_t file_content_length_bytes = 64 * 1024;
  std::string file_extensions[] = {
    ".exe", ".dll", ".txt", ".json", ".so", ".bin"
  };
  const int_fast64_t total_bytes_written = num_folders * num_files_in_folder * file_content_length_bytes;

  std::uniform_int_distribution<int_fast32_t> uniform_dist_file_extensions(0, std::size(file_extensions)-1);

  std::vector<std::filesystem::path> folder_paths;

  std::vector<std::string> file_names;
  std::vector<int_fast32_t> file_extension_idx; // For each file_names[i] points to the extension index in file_extensions[]
  std::vector<std::vector<BYTE_T>> file_contents;

  int_fast32_t file_ext_count[std::size(file_extensions)];
  for (int_fast32_t i=0; i<std::size(file_extensions); i+=1) {
    file_ext_count[i] = 0;
  }

  for (int_fast32_t folder_i=0; folder_i < num_folders; folder_i += 1) {
    std::stringstream ss;
    ss << std::hex << uniform_dist_bignums(rand_engine);
    folder_paths.push_back( test_folder / ss.str() );
  }

  for (int_fast32_t file_i=0; file_i < num_files_in_folder; file_i += 1) {
    std::stringstream ss;
    int_fast32_t file_extension_i = uniform_dist_file_extensions(rand_engine);
    ss << std::hex << uniform_dist_bignums(rand_engine) << file_extensions[file_extension_i];

    std::vector<BYTE_T> contents(file_content_length_bytes);
    std::generate(std::begin(contents), std::end(contents), std::ref(random_bytes_engine));

    file_names.push_back( ss.str() );
    file_extension_idx.push_back( file_extension_i );
    file_contents.push_back( contents );
    file_ext_count[file_extension_i] += 1;
  }

  // Now that we have the file names + contents prepped, perform the actual I/O operations for the test.

  // we record for each file type create + write durations
  std::vector<std::chrono::high_resolution_clock::duration> per_file_ext_durations[std::size(file_extensions)];
  for (int_fast32_t i=0; i<std::size(file_extensions); i+=1) {
    per_file_ext_durations[i].reserve( num_folders * num_files_in_folder / (std::size(file_extensions)/2) );
  }

  auto start = std::chrono::high_resolution_clock::now();

  for (int_fast32_t folder_i=0; folder_i < num_folders; folder_i += 1) {
    std::filesystem::create_directories(folder_paths[folder_i]);

    for (int_fast32_t file_i=0; file_i < num_files_in_folder; file_i += 1) {
      auto file_start = std::chrono::high_resolution_clock::now();

      std::filesystem::path file_path = folder_paths[folder_i] / file_names[file_i];
      {
        std::ofstream outfile(file_path, std::ios::out | std::ios::binary);
        outfile.write((const char*) file_contents[file_i].data(), file_contents[file_i].size());
        outfile.flush();
      }

      // Now delete the file and ensure it is deleted
      std::filesystem::remove(file_path);

      if (std::filesystem::exists(file_path)) {
        std::cout << "WARNING: We attempted to delete " << file_path << " but were somehow unsuccessful. Waiting for OS to complete file deletion..." << std::endl;
        test_is_anomalous = true;
        while (std::filesystem::exists(file_path)) {
          // We aren't sleeping at all because that will mess up timing numbers; we want as CLOSE AS POSSIBLE to ground truth from the operating system.
        }
      }

      // And finally write a 2nd time
      {
        std::ofstream outfile(file_path, std::ios::out | std::ios::binary);
        outfile.write((const char*) file_contents[file_i].data(), file_contents[file_i].size());
        outfile.flush();
      }

      auto file_elapsed = std::chrono::high_resolution_clock::now() - file_start;
      per_file_ext_durations[file_extension_idx[file_i]].push_back(file_elapsed);

    }
  }

  auto elapsed = std::chrono::high_resolution_clock::now() - start;

  // Test DONE, compute statistics

  std::chrono::high_resolution_clock::duration per_file_ext_duration_sums[std::size(file_extensions)] = {
    std::chrono::high_resolution_clock::duration::zero()
  };

  // we record for each file type create + write MAX
  std::chrono::high_resolution_clock::duration per_file_ext_duration_max[std::size(file_extensions)] = {
    std::chrono::high_resolution_clock::duration::zero()
  };
  // we record for each file type create + write MIN
  std::chrono::high_resolution_clock::duration per_file_ext_duration_min[std::size(file_extensions)] = {
    std::chrono::high_resolution_clock::duration::max()
  };

  std::chrono::high_resolution_clock::duration per_file_ext_duration_sums_ten_perc[std::size(file_extensions)] = {
    std::chrono::high_resolution_clock::duration::zero()
  };

  std::chrono::high_resolution_clock::duration per_file_ext_duration_max_ten_perc[std::size(file_extensions)] = {
    std::chrono::high_resolution_clock::duration::zero()
  };
  std::chrono::high_resolution_clock::duration per_file_ext_duration_min_ten_perc[std::size(file_extensions)] = {
    std::chrono::high_resolution_clock::duration::max()
  };

  for (int_fast32_t i=0; i<std::size(file_extensions); i+=1) {
    // Each of per_file_ext_durations[i] will be sorted MIN -> MAX
    std::sort(per_file_ext_durations[i].begin(), per_file_ext_durations[i].end());

    for (auto file_elapsed : per_file_ext_durations[i]) {
      per_file_ext_duration_sums[i] += file_elapsed;
    }

    if (per_file_ext_durations[i].size() > 0) {
      per_file_ext_duration_max[i] = per_file_ext_durations[i][per_file_ext_durations[i].size()-1];
      per_file_ext_duration_min[i] = per_file_ext_durations[i][0];

      per_file_ext_duration_max_ten_perc[i] = per_file_ext_durations[i][ ((per_file_ext_durations[i].size()-1) * 9)/10 ];
      per_file_ext_duration_min_ten_perc[i] = per_file_ext_durations[i][ ((per_file_ext_durations[i].size()) * 1)/10 ];
      for (int_fast32_t j=((per_file_ext_durations[i].size()) * 1)/10; j < ((per_file_ext_durations[i].size()-1) * 9)/10 ; j+=1) {
          per_file_ext_duration_sums_ten_perc[i] += per_file_ext_durations[i][j];
      }

    }

  }

  long long total_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

  long m = total_microseconds / (60 * 1000 * 1000);
  long s = (total_microseconds - (m * 60 * 1000 * 1000)) / (1000 * 1000);
  double ms = ((double) ((total_microseconds - (m * 60 * 1000 * 1000)) - (s * 1000 * 1000))) / 1000.0;

  // Write out test report

  std::cout.imbue(std::locale(""));
  std::cout << "Completed writing " << std::fixed << std::showpoint << std::setprecision(1) << ((double) total_bytes_written / (1024.0 * 1024.0)) << " GB of data to " << std::fixed << (num_folders * num_files_in_folder) << " files." << std::endl;
  std::cout << "Test took " << m << "m " << s << "s " << ms << "ms" << std::endl;

  std::cout << "= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =" << std::endl;
  for (int_fast32_t i=0; i<std::size(file_extensions); i+=1) {
    long long ext_total_microseconds_sum = std::chrono::duration_cast<std::chrono::microseconds>(per_file_ext_duration_sums[i]).count();
    long long ext_total_microseconds = ext_total_microseconds_sum / std::max((int_fast32_t) 1, num_folders*file_ext_count[i]);
    double ext_ms = ((double) ext_total_microseconds) / 1000.0;
    double total_ext_bytes_written = (double) file_content_length_bytes * file_ext_count[i];
    double bytes_per_second = total_ext_bytes_written / std::max(0.0001, ((double) ext_total_microseconds / (1000.0 * 1000.0)));

    double max_ext_ms = ((double) std::chrono::duration_cast<std::chrono::microseconds>(per_file_ext_duration_max[i]).count() ) / 1000.0;
    double min_ext_ms = ((double) std::chrono::duration_cast<std::chrono::microseconds>(per_file_ext_duration_min[i]).count() ) / 1000.0;
    double deviation_ms = max_ext_ms - min_ext_ms;

    std::cout << std::setw(5) << file_extensions[i] << " files averaged " <<
        std::setprecision(5) << ext_ms << "ms " <<
        "(max " << max_ext_ms <<"ms min " << min_ext_ms << "ms deviation of " << deviation_ms << "ms) " <<
        "to complete write+delete+write data (" << (bytes_per_second/(1024.0 * 1024.0)) << " megabytes per second, "<< (num_folders*file_ext_count[i]) <<" files tested)" << std::endl;
  }

  std::cout << "= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =" << std::endl;
  for (int_fast32_t i=0; i<std::size(file_extensions); i+=1) {
    long long ext_total_microseconds_sum = std::chrono::duration_cast<std::chrono::microseconds>(per_file_ext_duration_sums_ten_perc[i]).count();
    long long ext_total_microseconds = ext_total_microseconds_sum / std::max((int_fast32_t) 1, num_folders*file_ext_count[i]);
    double ext_ms = ((double) ext_total_microseconds) / 1000.0;
    double total_ext_bytes_written = (double) file_content_length_bytes * file_ext_count[i];
    double bytes_per_second = total_ext_bytes_written / std::max(0.0001, ((double) ext_total_microseconds / (1000.0 * 1000.0)));

    double max_ext_ms = ((double) std::chrono::duration_cast<std::chrono::microseconds>(per_file_ext_duration_max_ten_perc[i]).count() ) / 1000.0;
    double min_ext_ms = ((double) std::chrono::duration_cast<std::chrono::microseconds>(per_file_ext_duration_min_ten_perc[i]).count() ) / 1000.0;
    double deviation_ms = max_ext_ms - min_ext_ms;

    std::cout << std::setw(5) << file_extensions[i] << " files averaged " <<
        std::setprecision(5) << ext_ms << "ms " <<
        "(max " << max_ext_ms <<"ms min " << min_ext_ms << "ms deviation of " << deviation_ms << "ms) " <<
        "to complete write+delete+write data (" << (bytes_per_second/(1024.0 * 1024.0)) << " megabytes per second, "<< (num_folders*file_ext_count[i]) <<" files tested)" << std::endl;
  }

  std::cout << std::boolalpha;
  VARDUMP(test_is_anomalous);

  return 0;
}

