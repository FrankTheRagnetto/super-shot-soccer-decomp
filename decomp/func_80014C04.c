typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 *D_800E9654;
extern s32 D_800E9650;
s32 func_80014B7C(u16, u8 *, s32);
void func_800143C0(s32, s32);
s32 func_8001383C(s32);

u8 *func_80014C04(u16 arg0) {
    u8 *buf = D_800E9654;
    s32 n = func_80014B7C(arg0, buf, D_800E9650);
    *(s32 *)(buf + n) = 0;
    if (buf != D_800E9654) {
        func_800143C0(0x53, 0x13);
    }
    if (func_8001383C(n) == -1) {
        func_800143C0(0x53, 0xD);
    }
    return buf;
}
