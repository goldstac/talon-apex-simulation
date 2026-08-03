#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "make_dirs.h"
namespace fs = std::filesystem;

void make_dirs(int argc, char* argv[]) {
   
     std::cout << "[Check] For System Directorys\n";
    fs::path binary_dir = fs::absolute(argv[0]).parent_path();

    
    std::vector<fs::path> directories = {
        binary_dir / "filesystem/home/admin/Desktop",
        binary_dir / "filesystem/home/admin/.cache",
        binary_dir / "filesystem/bin",
        binary_dir / "filesystem/rootfs",
        binary_dir / "filesystem/boot",
        binary_dir / "filesystem/proc",
        binary_dir / "filesystem/tmpfs",
        binary_dir / "filesystem/home/admin/.config",
        binary_dir / "filesystem/home/admin/.config/browser",
    };

    for (const auto& path : directories) {
        if (!fs::exists(path)) {
            if (fs::create_directories(path)) {
                std::cout << "[CREATED]   " << path << '\n';
            } else {
                std::cerr << "[FAILED]    Could not create " << path << '\n';
            }
        } else {
            std::cout << "[EXISTS]    " << path << '\n';
        }
    }
 std::string filename_browser = "filesystem/home/admin/.config/browser/browser.conf";
    if (!fs::exists(filename_browser)){
     std::ofstream outfile(filename_browser);
    }
    else{
        // chill they exist
    }
    
}