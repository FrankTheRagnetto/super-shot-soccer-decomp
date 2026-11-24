typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
extern u8 D_800F0FAD;
extern u8 D_800F0FAC;
void func_80079E00(s32);
void func_8002EBDC(s32 arg0, u8 arg1) {
    D_800F0FAD = arg0;
    D_800F0FAC = arg1;
    if (!(arg1 & 1)) {
        func_80079E00(3);
    }
}
