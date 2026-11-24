typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
s32 func_80014C04(u16);
void func_80074890(s32, s16, s16, s16, s16);

void func_80015608(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80074890(func_80014C04(arg0), arg1, arg2, arg3, arg4);
}
