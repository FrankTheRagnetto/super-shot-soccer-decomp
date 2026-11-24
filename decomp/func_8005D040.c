typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800FC41C[];

void func_8005D040(u8 arg0) {
    u8 i = arg0 % 3;
    D_800FC41C[i] = 1;
}
