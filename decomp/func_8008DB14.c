typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s16 a; s16 b; s32 c; s32 d; } S;
extern S D_8010C428[];

void func_8008DB14(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        D_8010C428[i].a = 0xFF;
        D_8010C428[i].b = 0;
        D_8010C428[i].c = 0;
        D_8010C428[i].d = 0;
    }
}
