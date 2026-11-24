typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u8 a; u8 b; s16 x[18]; s16 y[18]; s16 z[18]; } S;
extern S D_801029E0;
extern s16 *D_80102B60[];
void func_8007EF40(void) {
    s16 i;
    D_801029E0.a = 0;
    D_801029E0.b = 0;
    for (i = 0; i < 18; i++) {
        s16 *p = D_80102B60[i];
        *p = D_801029E0.x[i];
        *++p = D_801029E0.y[i];
        *++p = D_801029E0.z[i];
    }
}
