typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
extern s32 D_800D08F0;
extern s32 D_800D08EC;
extern u8 D_800FA130[][17];
void func_80018A4C(s32 n, s32 *src) {
    s32 i;
    D_800D08F0 = 0;
    D_800D08EC = n;
    for (i = 0; i < n; i++) {
        D_800FA130[D_800D08F0][i] = *src++;
    }
    D_800FA130[D_800D08F0][i] = 0xFF;
}
