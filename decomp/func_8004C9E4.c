typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
u16 func_8004CB38(s16, s16);
s32 func_8004CB70(s16, s16);

s16 func_8004C9E4(s16 arg0, s16 arg1, s16 arg2) {
    if ((s16)func_8004CB38(arg1, arg0) < arg2) {
        arg0 = arg1;
    } else if (func_8004CB70(arg0, arg1) > 0) {
        arg0 = arg0 - arg2;
    } else {
        arg0 = arg0 + arg2;
    }
    return arg0;
}
