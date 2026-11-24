typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u8 pad[0x24]; } E;
extern E D_80102BE8[][2];
void func_800AACF8(E *);

void func_80087AB0(void) {
    s32 i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_800AACF8(&D_80102BE8[i][j]);
        }
    }
}
