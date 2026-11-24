typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x6E]; u16 v; } S;

s32 func_80038660(S *arg0) {
    u16 x = arg0->v;
    if (x >= 0x24 && x < 0x70 && x != 0x52) {
        return 0;
    }
    return -1;
}
