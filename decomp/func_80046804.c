typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
extern u8 D_800FC374;
extern u8 D_800FC377;
u8 func_80046804(u8 arg0) {
    return (arg0 < 11) ? D_800FC374 : D_800FC377;
}
u8 func_80046830(u8 arg0) {
    return (arg0 < 11) ? D_800FC377 : D_800FC374;
}
