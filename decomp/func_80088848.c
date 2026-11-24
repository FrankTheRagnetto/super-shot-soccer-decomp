typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800F7C70;
void func_80088870(s32, s32);

void func_80088848(s32 arg0) {
    func_80088870(arg0, D_800F7C70);
}
