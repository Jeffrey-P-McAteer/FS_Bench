
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cstdint>

#if defined(_WIN32) || defined(WIN32)
#include "fs_bench_os_windows.hpp"
#else
#include "fs_bench_os_linux.hpp"
#endif

#define DIE(code, msg_content) std::cerr << msg_content << std::endl; return code
#define VARDUMP(var) std::cout << #var "=" << var << std::endl

int main(int argc, char** argv) {
  if (argc < 2) {
    DIE(1, "ARG1 should be a filesystem path to an empty folder which will be populated with test I/O activity.");
  }
  const std::filesystem::path test_folder = argv[1];
  VARDUMP(test_folder);

  const std::string folder_device_path = get_device_path(test_folder);
  VARDUMP(folder_device_path);


  return 0;
}

