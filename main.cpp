#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
int main() {
    std::string version = "0.0.1";
    std::string status = "Alpha";
    std::string shell;
    std::cout << "admin@talon [~/Desktop] [ " << version << " " << status << " ] \n > ";
    std::getline(std::cin,shell);
    if (shell == "t!ping"){
        std::cout << "Pong!\n";
    }
}
