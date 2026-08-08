#include <iostream>
#include <string>
#include <cstdlib>
int main(){
    std::string input;
    std::string commit_msg;
    std::string full;
    std::cout << "Welcome To Push\n";
    std::cout << "Options \n";
    std::cout << "[1] Add . , Custom Commit , Push main\n";
    std::cout << "Enter Choice\n --> ";
    std::cin >> input;
    if (input == "1"){
        std::cin.ignore();
        std::cout << "Enter Commit Message\n --> ";
        std::getline(std::cin,commit_msg);
        full = "git add . && git commit -m \"" + commit_msg + "\" && git push origin main";
        std::system(full.c_str());
        std::cout << "done :) \n";
    }
}
