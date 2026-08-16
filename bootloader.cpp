#include <iostream>
#include <string>
#include <cstdlib>
#include "kernel/kernel.h"
#include "kernel/extra/initramfs.h"
#include "kernel/extra/make_dirs.h"
void bootloader(int argc, char* argv[]){
    std::string boot_option;
    std::cout << "Flash Bootloader\n";
    std::cout << "Talon : [1]\n";
    std::cout << "Enter Boot Option \n --> ";
    std::getline(std::cin, boot_option);
    if (boot_option != "1"){
        std::cout << "Invalid boot option. Only [1] is supported.\n";
        std::exit(0);
    }
    make_dirs(argc,argv);
    create_tmpfs_initramfs();
    kernel();
}