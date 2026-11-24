#include "m2c_macros.h"
typedef unsigned char u8;
int func_80026070(u8);
int func_8004B8DC(u8 a) {
    int v;
    if (func_80026070(a) == 0) {
        v = 0x400;
    } else {
        v = -0x400;
    }
    return v;
}
