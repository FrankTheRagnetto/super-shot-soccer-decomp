typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

void func_80014B7C(s32, s32, s32);

void func_800151D4(u8 arg0, s32 arg1) {
    func_80014B7C(arg0 + 0xB, arg1, 0x3500);
}
