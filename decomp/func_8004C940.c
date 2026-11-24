typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800F0F42, D_800F7C71, D_800F0EE5;
void func_8004EF9C(s32, u8, s32, s32);
void func_8002E9EC(s32, u8, s32);
void func_8007AEAC(u8, u8);
void func_8007A490(u8, s32);

void func_8004C940(s32 arg0, u8 arg1, u8 arg2) {
    if (D_800F0F42 == 0x17) {
        D_800F7C71 = arg1;
        func_8004EF9C(arg0, arg1, 5, 0);
        D_800F0F42 = 0x17;
        D_800F0EE5 = 0x17;
        func_8002E9EC(4, arg1, 0);
        if ((s8)arg2 >= 0) {
            func_8007AEAC(arg1, arg2);
        } else {
            func_8007A490(arg1, arg2 - 0x80);
        }
    }
}
