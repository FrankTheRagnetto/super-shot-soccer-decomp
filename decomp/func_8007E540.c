typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x1730]; s32 v; } S7D28;
extern S7D28 D_800F7D28;

void func_8007E540(s32 arg0) {
    s32 v = (D_800F7D28.v * arg0) >> 8;
    if (v < 0x10000) {
        v = 0x10000;
    }
    D_800F7D28.v = v;
}
