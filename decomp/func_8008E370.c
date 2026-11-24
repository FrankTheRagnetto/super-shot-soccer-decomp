typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s16 a; s16 b; s32 c; s32 d; } S;
extern S D_8010C428[];

s32 func_8008E370(s32 arg0) {
    s32 r = 0;
    if (D_8010C428[arg0].a < 0x18) {
        r = (D_8010C428[arg0].c << 4) >> 16;
    }
    return r;
}
