#include "initramfs.h"
#include "logger.h"
#include <fstream>

extern "C" {

void create_file_initramfs(const char* filepath) {
    std::ofstream file(filepath);
}

void create_tmpfs_initramfs() {
    log_info("initramfs: generating initramfs images");
    create_file_initramfs("filesystem/tmpfs/initramfs_uncompressed.img");
    create_file_initramfs("filesystem/boot/initramfs.img");
    log_info("initramfs: images generated");
}

}