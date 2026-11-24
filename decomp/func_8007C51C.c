typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x1704]; s16 f1704; u8 pad2[0x1728 - 0x1706]; s32 f1728; } G;
extern G D_800F7D28;
extern void D_80079C8C();
void func_8008DFF0(s32);
void func_8007CA80(void);
void func_8007DB04(u8, s32);
void func_80014550(void *, s32);
void func_8007A478(u8, s32, s32);

s16 func_8007C51C(u8 arg0, u8 arg1, s32 arg2) {
    func_8008DFF0(9);
    func_8007CA80();
    D_800F7D28.f1728 = 0x28;
    func_8007DB04(arg1, arg2);
    func_80014550(D_80079C8C, 0x27);
    func_8007A478(arg0, 0, 0x12);
    return D_800F7D28.f1704;
}
