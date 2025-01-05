struct Mount {
    std::string device;
    std::string destination;
    std::string fstype;
    std::string options;
    int dump;
    int pass;
};

std::ostream& operator<<(std::ostream& stream, const Mount& mount) {
    return stream << mount.fstype <<" device \""<<mount.device<<"\", mounted on \""<<mount.destination<<"\". Options: "<<mount.options<<". Dump:"<<mount.dump<<" Pass:"<<mount.pass;
}

int_fast16_t num_matching_prefix_chars(std::string& a, std::string& b) {
  int_fast16_t num_matching = 0;
  int_fast16_t until = std::min(a.length(), b.length());
  for (int_fast16_t i=0; i<until; i+=1) {
    if ((char) a[i] != (char) b[i]) {
      break;
    }
    num_matching = i+1;
  }
  return num_matching;
}

std::string get_device_path(const std::filesystem::path folder) {
  std::ifstream mountInfo("/proc/mounts");
  std::string folder_as_string = folder.string();
  Mount closest_match;
  // sum of (MATCH_CHARS/this_row.destination) and (MATCH_CHARS/folder_as_string)
  // This handles the "/"-mounted partition well, because we will have 1.0 when the match signal is very weak.
  // We will also get a 1.0 + > match for sub-partitions, so the highest score here will always be the best logical match.
  float closest_matching_score = 0.0;
  while (!mountInfo.eof()) {
      Mount this_row;
      mountInfo >> this_row.device >> this_row.destination >> this_row.fstype >> this_row.options >> this_row.dump >> this_row.pass;
      int_fast16_t this_row_matching_chars = num_matching_prefix_chars(this_row.destination, folder_as_string);
      float this_matching_score = ((float)this_row_matching_chars / (float) std::max((int_fast16_t)1, (int_fast16_t)this_row.destination.length())) +
                                  ((float)this_row_matching_chars / (float) std::max((int_fast16_t)1, (int_fast16_t)folder_as_string.length() ));
      if (this_matching_score > closest_matching_score) {
        closest_match = this_row;
        closest_matching_score = this_matching_score;
      }
  }
  return closest_match.device;
}


