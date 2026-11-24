typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
void func_80018844(s32, s32);
void func_80018C1C(s32, s32);

void func_80018CD0(s32 arg0, s32 arg1) {
    if (arg1 < 3) {
        func_80018844(arg0, arg1);
    } else {
        func_80018C1C(arg0, arg1);
    }
}
