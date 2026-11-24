typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 a, b, c, d, e, f, g; s8 h; } S;
extern S D_800FA298[];
u32 func_80074FF8(void);

void func_80019808(void) {
    s32 i;
    s32 v;
    for (i = 0; i < 20; i++) {
        v = D_800FA298[i].h;
        if (func_80074FF8() > 0x80) {
            v++;
        } else {
            v--;
        }
        if (v < 0) {
            v = 0;
        }
        if (v >= 5) {
            v = 4;
        }
        D_800FA298[i].h = v;
    }
}
