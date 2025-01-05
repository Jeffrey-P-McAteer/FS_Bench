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


std::string get_device_path(const std::filesystem::path folder) {
  std::string device_path;
  std::ifstream mountInfo("/proc/mounts");
  while (!mountInfo.eof()) {
      Mount each;
      mountInfo >> each.device >> each.destination >> each.fstype >> each.options >> each.dump >> each.pass;
      std::cout << each << std::endl;
  }
  return device_path;
}

