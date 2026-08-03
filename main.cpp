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
int main(int argc,char* argv[]){
bootloader(argc,argv);
   std::string shell;
   while (true)
   {
     std::cout << "admin@talon [~/Desktop]\n --> ";
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
   }
   

}