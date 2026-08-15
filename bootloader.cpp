#include <iostream>
#include "kernel/kernel.h"
#include "kernel/extra/initramfs.h"
#include "kernel/extra/make_dirs.h"
void bootloader(int argc, char* argv[]){
    int boot_option;
    std::cout << "Flash Bootloader\n";
    std::cout << "Talon : [1]\n";
    std::cout << "Enter Boot Option \n --> ";
    std::cin >> boot_option;
    std::cin.ignore();
    if (boot_option == 1){
        make_dirs(argc,argv);
        create_tmpfs_initramfs();
        kernel();
    }
}
