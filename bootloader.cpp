#include <iostream>
#include <string>
#include <cstdlib>
#include "kernel/kernel.h"
#include "kernel/extra/initramfs.h"
#include "kernel/extra/make_dirs.h"
#include "kernel/extra/logger.h"
void bootloader(int argc, char* argv[]){
    std::string boot_option;
    std::cout << "Flash Bootloader\n";
    std::cout << "Talon : [1]\n";
    ensure_logger_config();
    log_info("bootloader: Flash Bootloader starting");
    std::cout << "Enter Boot Option \n --> ";
    std::getline(std::cin, boot_option);
    if (boot_option != "1"){
        log_error("bootloader: invalid boot option '" + boot_option + "'");
        std::cout << "Invalid boot option. Only [1] is supported.\n";
        std::exit(0);
    }
    log_info("bootloader: boot option 1 selected");
    make_dirs(argc,argv);
    create_tmpfs_initramfs();
    kernel();
}
