#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
std::string random_string(int len) {
    srand(time(0));
    const char chars[] =
        "1368213SOISFOSIDFOSDFkofjFODSJIOSDerwqtrweuieodplmsjkasjghdffteoiqwo";
     std::string result = "";
     for (int i = 0; i < len; i++)
     result += chars[rand() % 62];
     return result;

}
int main(){
    // i want a an implemntation of /dev/urandom on this very soon
    // lets see if i can manage to integrate that :3
  while (1){
      sleep(1);
       std::cout << random_string(16) << std::endl;
  }
}
