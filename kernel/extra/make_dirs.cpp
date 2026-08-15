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
    std::string cpuinfo_path = "filesystem/proc/cpuinfo";
    if (!fs::exists(cpuinfo_path)) {
        std::ofstream cpuinfo(cpuinfo_path);
        cpuinfo << "---------------------------------\n"
                << "            CPU INFO             \n"
                << "---------------------------------\n"
                << "Name      | Intel Core Ultra 9 285K\n"
                << "Cores     | 24\n"
                << "Threads   | 24\n"
                << "L2 Cache  | 40MB\n"
                << "L3 Cache  | 36MB\n"
                << "Max Speed | 5.7 GHz\n";
    }
    std::string gpuinfo_path = "filesystem/proc/gpuinfo";
    if (!fs::exists(gpuinfo_path)) {
        std::ofstream gpuinfo(gpuinfo_path);
        gpuinfo << "----------------------------------------\n"
                << "               GPU INFO\n"
                << "----------------------------------------\n"
                << "Name              |Nvidia GeForce RTX 5090\n"
                << "VRAM              |32 GB\n"
                << "CUDA Cores        |21760\n"
                << "RAM Type          |GDDR7\n"
                << "Architecture      |Blackwell\n"
                << "Interface         |PCIE 5.0 X16 Slot\n"
                << "Memory Bus        |512-Bit\n"
                << "Memory Bandwith   |1.79 TB/S\n";
    }
}