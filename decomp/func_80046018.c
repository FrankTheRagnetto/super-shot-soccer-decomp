#include "m2c_macros.h"
typedef unsigned short u16;
int func_80046018(u16 a) {
    if (a != 0x6A && (a == 7 || a == 0xE || a == 0x10)) {
        return 0;
    }
    return 1;
}
