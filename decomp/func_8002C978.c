typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
extern u16 D_800FBE5A;
extern u16 D_800FBE52;
extern s8 D_800FBE4E;
extern u16 D_800FBE58;
void func_8002C978(u8 arg0) {
    if (D_800FBE5A == 0) {
        D_800FBE52 = 0x77;
    } else {
        D_800FBE52 = D_800FBE5A - 1;
    }
    if (D_800FBE4E == 0) {
        if (D_800FBE52 < arg0) {
            D_800FBE58 = 0;
        } else {
            D_800FBE58 = D_800FBE52 - arg0;
        }
    } else {
        D_800FBE58 = D_800FBE52 - arg0;
        if (D_800FBE58 >= 0x78) {
            D_800FBE58 += 0x78;
        }
    }
}
