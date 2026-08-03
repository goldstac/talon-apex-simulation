#include "update.h"
#include "bootloader.h"
#include "kernel/kernel.h"
#include "logo.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <filesystem>
std::string version = "V0.0.1";
std::string home_dir = "filesystem/home/admin/Desktop";
std::string cache_dir = "filesystem/home/admin/.cache";
std::string config_dir = "filesystem/home/admin/.config";
int main(int argc,char* argv[]){
bootloader(argc,argv);
   std::string shell;
   while (true)
   {
     std::cout << "admin@talon [~/Desktop] " << version << "\n --> ";
     std::getline(std::cin,shell);
     if (shell == "clear"){
      #ifdef _WIN32
      std::system("cls");
#else
      std::system("clear");
#endif
     }
     else if (shell == "penguinfetch"){
      printLogo();
     }
     else if (shell == "update"){
      run_update();
     }
     else if (shell == "exit"){
      break;
     }
     else if (shell == "--version"){
      std::cout << version << "\n";
     }
     else if (shell.substr(0,4) == "echo"){
      if (shell.length() > 5){
         std::cout << shell.substr(5) << "\n";
      }
     }
   }
   

}