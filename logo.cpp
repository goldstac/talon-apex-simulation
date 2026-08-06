#include "logo.h"
#include <iostream>

void printLogo(){
  
  const std::string R = "\033[0m";
  const std::string G1 = "\033[1;33m";
  const std::string G2 = "\033[0;33m";
  const std::string M = "\033[0;35m";
  const std::string R1 = "\033[1;31m";
  const std::string R2 = "\033[0;31m";
  const std::string W = "\033[1;37m";

  std::cout << G1 << "             .+*#%@@@@@%#*+.\n";
  std::cout << G1 << "          .+*#%@@@@@@@@@@@%#*+.\n";
  std::cout << G1 << "        .+*#%@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << G2 << "       .+*#%@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << G2 << "      .+*#%@@@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << G2 << "     .+*#%@@@@@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << M << "    .+*#%@@@@@@@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << M << "  .+*#%@@@@@@@@@@%#*+*#%@@@@@@@@@@%#*+.\n";
  std::cout << M << "  .+*#%@@@@@@@@@@%#*+*#%@@@@@@@@@@%#*+.\n";
  std::cout << M << "    .+*#%@@@@@@@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << R2 << "     .+*#%@@@@@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << R2 << "      .+*#%@@@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << R1 << "       .+*#%@@@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << R1 << "        .+*#%@@@@@@@@@@@@@@@%#*+.\n";
  std::cout << R2 << "          .+*#%@@@@@@@@@@@%#*+.\n";
  std::cout << R2 << "             .+*#%@@@@@%#*+.\n";
  std::cout << R << W << "             Talon Apex v0.0.3 (Stable)\n" << R;
}