typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u32 D_800E9630, D_800F7C30, D_800E9654, D_800E9650;

void func_800137A0(void) {
    D_800E9630 = 0x801F5400;
    D_800E9654 = (D_800F7C30 + 3) & ~3;
    D_800E9650 = D_800E9630 - D_800E9654;
}
