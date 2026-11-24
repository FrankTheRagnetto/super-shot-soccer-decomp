typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
extern u8 D_800E9664, D_8010C538;
extern u8 D_800D08F4[][5];
s32 func_80075118(s32);

s32 func_8001A3D4(s32 arg0) {
    u8 s;
    s32 r, sum, i;
    if (arg0 == 0 || D_800E9664 == 3 || D_800E9664 == 0) {
        s = 2;
    } else {
        s = D_8010C538;
    }
    r = func_80075118(100);
    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += D_800D08F4[i][s];
        if (r < sum) {
            return i;
        }
    }
    return 4;
}
