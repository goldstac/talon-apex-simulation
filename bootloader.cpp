#include <iostream>
#include "kernel/kernel.h"
#include "kernel/extra/initramfs.h"
#include "kernel/extra/make_dirs.h"
#include <filesystem>
void bootloader(int argc, char* argv[]){
    std::string boot_option;
    std::cout << "Flash Bootloader\n";
    std::cout << "Talon : [1]\n";
    std::cout << "Enter Boot Option \n --> ";
    std::cin >> boot_option;
}