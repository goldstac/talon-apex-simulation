#include "initramfs.h"
#include <fstream>

extern "C" {

void create_file_initramfs(const char* filepath) {
    std::ofstream file(filepath);
}

}

void create_tmpfs_initramfs() {
    create_file_initramfs("filesystem/tmpfs/initramfs_uncompressed.img");
    create_file_initramfs("filesystem/boot/initramfs.img");
}