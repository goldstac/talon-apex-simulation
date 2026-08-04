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
std::string version = "V0.0.2";
std::string home_dir = "filesystem/home/admin/Desktop";
std::string cache_dir = "filesystem/home/admin/.cache";
std::string config_dir = "filesystem/home/admin/.config";
std::string read_file(const std::string& filepath) {
    std::ifstream file(filepath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
void write_file(const std::string& filepath, const std::string& content) {
    std::ofstream file(filepath);
    file << content;
}
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
      else{
         std::cout << "echo what?\n";
      }
     }
     else if (shell == "date"){
      std::system("date > filesystem/home/admin/.cache/date.txt");
      std::string date_cmd = read_file("filesystem/home/admin/.cache/date.txt");
      std::cout << date_cmd << "\n";
     }
     else if (shell.substr(0,5) == "which"){
      if (shell.length() > 6){
        std::string which_full_form = shell.substr(6);
        std::string which_full_command = "find filesystem/bin/ -name \"" + which_full_form + "\"";
        std::system(which_full_command.c_str());
      }
      else{
         std::cout << "say a filename\n";
      }
     }
   }
   

}