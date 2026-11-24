#include "m2c_macros.h"
typedef unsigned char u8;
typedef signed char s8;
extern u8 D_800F7D28[];

void func_8007A478(u8 arg0, s8 arg1, s8 arg2) {
    D_800F7D28[0x17D1] = arg2;
    D_800F7D28[0x17D2] = arg1;
    D_800F7D28[0x17D0] = arg0;
}
