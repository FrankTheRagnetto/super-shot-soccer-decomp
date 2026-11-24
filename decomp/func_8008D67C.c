typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
void func_800A50F8(s32, u8 *, s32);
void VSync_v3(s32);
void CdRead_v6(s32, s32, s32);
s32 CdReadSync_v5(s32, s32);
void func_8008D67C(s32 size, s32 buf, s32 mode) {
    u8 m;
    s32 n = (size + 0x7FF) / 0x800;
    m = mode;
    func_800A50F8(0xE, &m, 0);
    VSync_v3(3);
    CdRead_v6(n, buf, mode);
    while (CdReadSync_v5(1, 0) > 0) {
        VSync_v3(0);
    }
}
