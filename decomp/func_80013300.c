typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern s8 D_800F790A[];
extern s8 D_800E977E;

void func_80013300(s8 arg0, s8 arg1, s8 arg2) {
    D_800E977E = 1;
    D_800F790A[0] = arg0;
    D_800F790A[1] = arg1;
    D_800F790A[2] = arg2;
}
