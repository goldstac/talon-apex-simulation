#include <stdio.h>
#include "kernel.h"
#include "extra/compat.h"
void kernel(){
    printf("Loading Linux linux..\n");
    sleep_ms(1200);
    printf("clean /dev/nvme0n1p6/ 8392492/432423 \n");
    sleep_ms(700);
}
