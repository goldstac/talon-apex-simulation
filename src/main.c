#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void bootloader(void);
extern void input(void);
extern char buf[64];

int main(void) {

  bootloader();
  buf[63] = '\0';
  buf[strcspn(buf, "\n")] = '\0';
  int buf_int = atoi(buf);
  if (buf_int == 1) {
    input();

  } else {
    return 1;
  }

  return 0;
}
