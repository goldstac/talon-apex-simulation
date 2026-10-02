#include "include/os-info.h"
#include "include/split_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void bootloader(void);
extern void input(void);
extern char buf[64];
extern char user_input[64];
int main(void) {

  bootloader();
  buf[63] = '\0';
  buf[strcspn(buf, "\n")] = '\0';
  int buf_int = atoi(buf);
  printf("Welcome To Talon Apex\n");
  if (buf_int == 1) {
    while (1) {
      input();
      user_input[63] = '\0';
      user_input[strcspn(user_input, "\n")] = '\0';
      char argv[6][64];
      int argc = split_string(user_input, ' ', 6, 64, argv);
      if (strcmp(argv[0], "exit") == 0) {
        break;
      } else if (argv[0][0] == '\0') {
        continue;
      }
    }

    return 0;
  }
}
