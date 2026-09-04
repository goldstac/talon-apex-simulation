#include <iostream>
#include <string>
void bootloader(){
    std::string boot_option;
    std::cout << "Flash Bootloader\n";
    std::cout << "Talon Apex [1] \n";
    std::cout << "Enter Boot Option > ";
    std::cin >> boot_option;
    if (boot_option == "1"){
        //
    }
    else{
        std::cout << "Choose [1] Since Talon Apex Is The Only Entrie.\n";
    }

}
