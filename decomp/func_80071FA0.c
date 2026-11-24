typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
void func_8008E784(s32, s32);

void func_80071FA0(u8 arg0) {
    s32 i;
    s32 v;
    if (arg0 == 1) {
        v = 0;
    } else if (arg0 == 2) {
        v = 1;
    } else {
        return;
    }
    for (i = 0; i < 12; i++) {
        func_8008E784(i, v);
    }
}
