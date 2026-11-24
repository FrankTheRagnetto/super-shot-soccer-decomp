typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x80]; s16 f80; } A;
extern u16 D_800F958C;
s32 func_80026070(u8);

void func_800432DC(A *arg0, u8 arg1, u8 arg2) {
    u32 a = (D_800F958C + (arg2 << 9)) & 0xFFF;
    if (func_80026070(arg1) != 0 && a - 1 < 0x7FF) {
        a += 0x800;
    }
    arg0->f80 = a & 0xFFF;
}
