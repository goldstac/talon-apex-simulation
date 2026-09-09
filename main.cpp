#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "bootloader.h"
int main() {
    std::string version = "0.0.1";
    std::string status = "Alpha";
    std::string shell;
    while (1){
        std::cout << "admin@talon [~/Desktop] [ " << version << " " << status << " ] \n > ";
        std::getline(std::cin,shell);
        if (shell == "exit"){
            break;
        }
        else if (shell == "t!ping"){
            std::cout << "Pong!";
        }
    }

}
