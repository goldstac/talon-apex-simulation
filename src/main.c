#include <stdio.h>
#include <string.h>
extern void bootloader(void);
extern char buf[64];

int main(void) {

  bootloader();
  buf[63] = '\0';
  buf[strcspn(buf, "\n")] = '\0';

  if (strcmp(buf, "hi") == 0) {
    printf("hahaha");
  }

  return 0;
}
