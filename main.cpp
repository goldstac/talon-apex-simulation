#include "bootloader.h"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
int main() {
  std::string version = "1.0.1";
  std::string status = "";
  std::string shell;
  std::string home_dir = "filesystem/home/admin/Desktop";
  std::string cache_dir = "filesystem/home/admin/.cache";
  std::string config_dir = "filesystem/home/admin/.config";
  bootloader();
  while (1) {
    std::cout << "admin@talon [~/Desktop] [ " << version << " " << status
              << " ] \n > ";
    std::getline(std::cin, shell);
    if (shell == "exit") {
      break;
    } else if (shell == "t!ping") {
      std::cout << "Pong!\n";
    } else if (shell == "t!-v") {
      std::cout << version << " " << status << "\n";
    } else if (shell == "clear") {
      std::system("clear");
    } else if (shell == "date") {
      std::system("date");
    } else if (shell == "cat /dev/urandom") {
      // nothing for now
    }
  }
}
