typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
extern u16 D_800FC3F8;
extern u16 D_800FC3FA;
u16 func_80059910(u8 arg0) {
    if (arg0 == 1) {
        return D_800FC3F8;
    }
    if (arg0 == 2) {
        return D_800FC3FA;
    }
    return 0;
}
