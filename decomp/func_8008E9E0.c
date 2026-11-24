#include "m2c_macros.h"
extern volatile unsigned int D_800ECE40;
int func_800C9354(int);
int func_8008E9E0(void) {
    unsigned int limit = D_800ECE40 + 60;
    while (func_800C9354(0) != 1) {
        if (D_800ECE40 >= limit) {
            return -1;
        }
    }
    return 0;
}
