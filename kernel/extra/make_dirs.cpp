#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "make_dirs.h"
#include "logger.h"
namespace fs = std::filesystem;

void make_dirs(int argc, char* argv[]) {
   
     std::cout << "[Check] For System Directorys\n";
    log_info("make_dirs: checking system directories");
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
        binary_dir / "filesystem/var/log",
        binary_dir / "filesystem/etc",
    };

    for (const auto& path : directories) {
        if (!fs::exists(path)) {
            log_warn("missing " + path.string() + " — regenerating");
            if (fs::create_directories(path)) {
                std::cout << "[CREATED]   " << path << '\n';
                log_info("regenerated " + path.string());
            } else {
                std::cerr << "[FAILED]    Could not create " << path << '\n';
                log_error("failed to create " + path.string());
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
    std::vector<std::string> binaries = {
        "filesystem/bin/push",
        "filesystem/bin/calculator",
        "filesystem/bin/cat",
        "filesystem/bin/ls",
        "filesystem/bin/echo",
    };
    for (const auto& bin : binaries) {
        if (!fs::exists(bin)) {
            std::ofstream binary(bin);
        }
    }
    log_info("make_dirs: proc files and binaries generated");
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
    std::string meminfo_path = "filesystem/proc/meminfo";
    if (!fs::exists(meminfo_path)) {
        std::ofstream meminfo(meminfo_path);
        meminfo << "---------------------------------\n"
                << "            MEM INFO             \n"
                << "---------------------------------\n"
                << "MemTotal     | 64 GB\n"
                << "MemFree      | 52 GB\n"
                << "MemAvailable | 55 GB\n"
                << "Buffers      | 1.2 GB\n"
                << "Cached       | 8.5 GB\n"
                << "SwapTotal    | 16 GB\n"
                << "SwapFree     | 16 GB\n"
                << "Memory Type  | DDR5\n"
                << "Speed        | 7200 MT/S\n";
    }
}
