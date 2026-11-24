typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 a, b, c, d, e, f, g, h; } S;
extern S D_800FA298[];
extern S D_800FA338[];

void func_800195AC(void) {
    s32 i;
    for (i = 0; i < 20; i++) {
        if (i < 11) {
            D_800FA298[i].c = 1;
        } else {
            D_800FA298[i].c = 0;
        }
        D_800FA338[i] = D_800FA298[i];
    }
}
