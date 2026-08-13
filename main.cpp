#include "update.h"
#include "version.h"
#include "bootloader.h"
#include "logo.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <filesystem>
std::map<std::string, std::string>dir;
const std::string whoami = "admin";
const std::string flash_version = BOOTLOADER_VERSION;
const std::string version = TALON_VERSION;
const std::string kernel_version = KERNEL_VERSION;
const std::string home_dir = "filesystem/home/admin/Desktop/";
const std::string cache_dir = "filesystem/home/admin/.cache";
const std::string config_dir = "filesystem/home/admin/.config";
namespace fs = std::filesystem;
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
void create_file(const std::string& filepath) {
    std::ofstream file(filepath);
}
int main(int argc,char* argv[]){
    std::string cpuinfo = read_file("filesystem/proc/cpuinfo");
bootloader(argc,argv);
   std::string shell;
   dir["Desktop"] = "filesystem/home/admin/Desktop";
   dir[".config"] = "filesystem/home/admin/.config";
   dir[".cache"] = "filesystem/home/admin/.cache";
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
     else if (shell == "whoami"){
      std::cout << whoami << "\n";
     }
     else if (shell == "bootloader --version"){
      std::cout << "Talon Apex Core\n";
      std::cout << "Flash Bootloader\n";
      std::cout << flash_version << "\n";
     }
     else if (shell == "echo $SHELL"){
     std::cout << "Penguin\n";
     }
     else if (shell == "kernel -v"){
      std::cout << "Talon Apex Core\n";
      std::cout << "Talon Apex Kernel\n";
      std::cout << kernel_version << "\n";
     }
     else if (shell == "cat proc/cpuinfo"){
     const std::string cpu_model = "Intel Core Ultra 9 285K";
    int cpu_cores = 24;
    int cpu_threads = 24;
    std::string l2_cache = "40MB";
    std::string l3_cache = "36MB";
    std::string max_speed = "5.7 GHz";

    std::cout << "---------------------------------\n";
    std::cout << "            CPU INFO             \n";
    std::cout << "---------------------------------\n";
    std::cout << "Name      | " << cpu_model << "\n";
    std::cout << "Cores     | " << cpu_cores << "\n";
    std::cout << "Threads   | " << cpu_threads << "\n";
    std::cout << "L2 Cache  | " << l2_cache << "\n";
    std::cout << "L3 Cache  | " << l3_cache << "\n";
    std::cout << "Max Speed | " << max_speed << "\n";
     }
     else if (shell == "cat proc/gpuinfo"){
       std::string gpu_name = "Nvidia GeForce RTX 5090";
  std::string vram = "32 GB";
  std::string memory_type = "GDDR7";
  int cuda_cores = 21760;
  std::string architecture = "Blackwell";
  std::string interface = "PCIE 5.0 X16 Slot";
  std::string memory_bus = "512-Bit";
  std::string bandwith = "1.79 TB/S";
  std::cout << "----------------------------------------\n";
  std::cout << "               GPU INFO\n";
  std::cout << "----------------------------------------\n";
  std::cout << "Name              |" << gpu_name << "\n";
  std::cout << "VRAM              |" << vram << "\n";
  std::cout << "CUDA Cores        |" << cuda_cores << "\n";
  std::cout << "RAM Type          |" << memory_type << "\n";
  std::cout << "Architecture      |" << architecture << "\n";
  std::cout << "Interface         |" << interface << "\n";
  std::cout << "Memory Bus        |" << memory_bus << "\n";
  std::cout << "Memory Bandwith   |" << bandwith << "\n";
     }
     else if (shell == "talon -qi"){
      std::cout << "-----------------------------\n";
      std::cout << "Talon Apex " << version << "\n";
      std::cout << "-------------------------------\n";
      std::cout << "Kernel     | Talon Apex Kernel " << kernel_version << "\n";
      std::cout << "Bootloader | Flash Bootloader " << flash_version << "\n";

     }
     else if (shell =="systeminfo"){
         // coming soon
     }
     else if (shell.substr(0,3) == "vim"){
         if (shell.length() > 4){
             std::string full_vim_command = shell.substr(4);
             std::string full_vim_cmd = "vim " + home_dir + full_vim_command;
             std::system(full_vim_cmd.c_str());
         }
         else{
             std::system("vim filesystem/home/admin/Desktop/");
         }
     }
     else if (shell.substr(0,4) == "nvim"){
         if (shell.length() > 5){
             std::string full_nvim = shell.substr(5);
             std::string full_nvim_cmd = "nvim " + home_dir + full_nvim;
             int nvim_run = std::system(full_nvim_cmd.c_str());
             if (nvim_run !=0){
                 std::cout << "something went wrong bro\n";
             }
             else{
                 // all good bro
             }
         }
         else{
             int nvim_run2 = std::system("nvim filesystem/home/admin/Desktop/");
             if(nvim_run2 !=0){
                 std::cout << "something went wrong bro\n";
             }
             else{
                 // all good bro
             }
         }
     }
     else if (shell.substr(0,5) == "touch"){
         if (shell.length() > 6){
             std::string touch_file = shell.substr(6);
             std::string touch_make_path = home_dir + touch_file;
             if(!fs::exists(touch_make_path)){
                 create_file(touch_make_path);
             }
             else{
                 std::cout << "file already exists\n";
             }
         }
             std::cout << "enter a filename\n";
         }
     else if (shell.substr(0,2) == "cd"){
         if (shell.length() > 3){
             std::string target_cd = shell.substr(3);
             if (target_cd.substr(0,2) == "~/"){
                 target_cd = target_cd.substr(2);
             }
           if (dir.count(target_cd)){
               std::string actualpath = dir[target_cd];
               std::cout << "moved to " << actualpath << "\n";
           }

         }
     }

     }
   }
