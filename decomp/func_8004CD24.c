typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x1704]; s16 ang; u8 pad2[0x1730 - 0x1706]; s32 a; s32 b; } S7D28;
extern S7D28 D_800F7D28;
void func_8007A030(s32, s32, s32, s32, s32);

void func_8004CD24(s32 arg0, s32 arg1) {
    func_8007A030(D_800F7D28.ang, D_800F7D28.a, D_800F7D28.b, arg0, arg1);
}
