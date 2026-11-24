typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_801165B0;

void func_80095E04(s32 arg0, u8 arg1) {
    switch (arg1) {
    case 2:
        D_801165B0 = 1;
        break;
    case 3:
        D_801165B0 = 0;
        break;
    case 1:
        break;
    }
}
