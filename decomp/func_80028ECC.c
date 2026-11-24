typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[3]; u8 f3; u8 pad2[0x98 - 4]; s32 f98; s32 f9C; u8 pad3[0xCA - 0xA0]; u8 fCA; u8 pad4[0x100 - 0xCB]; } P;
extern P D_800F7D28[];

void func_80028ECC(u8 arg0, u8 arg1, s8 arg2, u8 arg3, s32 arg4, s32 arg5) {
    u8 s = D_800F7D28[arg3].f3;
    if (s == 0 || s == 2 || s == 3 || s == 16 || s == 17) {
        if (s != 0) {
            D_800F7D28[arg3].f3 = arg0;
        }
        D_800F7D28[arg3].fCA = arg1;
        if (arg2 == 1) {
            arg4 = -arg4;
            arg5 = -arg5;
        }
        D_800F7D28[arg3].f98 = arg4;
        D_800F7D28[arg3].f9C = arg5;
    }
}
