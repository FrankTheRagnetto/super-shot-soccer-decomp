#include "m2c_macros.h"
typedef unsigned char u8;
int func_80046084(u8);
void func_8004F69C(u8);
int func_8003E5F0(u8 a) {
    if (func_80046084(a) == 1) {
        func_8004F69C(a);
        return -1;
    }
    return 0;
}
