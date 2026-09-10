#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "bootloader.h"
int main() {
    std::string version = "1.0.0";
    std::string status = "Beta";
    std::string shell;
    bootloader();
    while (1){
        std::cout << "admin@talon [~/Desktop] [ " << version << " " << status << " ] \n > ";
        std::getline(std::cin,shell);
        if (shell == "exit"){
            break;
        }
        else if (shell == "t!ping"){
            std::cout << "Pong!\n";
        }
        else if (shell == "t!-v"){
            std::cout << version << " " << status << "\n";
        }
    }

}
