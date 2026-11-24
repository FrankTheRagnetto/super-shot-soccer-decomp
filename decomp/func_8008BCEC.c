typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u32 f; u8 pad[0x10]; } S;
extern S D_80102CB8[];

void func_8008BCEC(s32 arg0) {
    S *p = D_80102CB8;
    s32 i;
    for (i = 0; i < 16; i++, p++) {
        if (arg0 == 1) {
            p->f &= 0x7FFFFFFF;
        } else {
            p->f = 0x80000000;
        }
    }
}
