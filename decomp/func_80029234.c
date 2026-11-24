typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { u16 flags; u8 pad[0xFE]; } P;
typedef struct { u8 pad[0x18]; s32 x; s32 z; } A;
extern P D_800F7D28[];

s32 func_80029234(A *a, s32 *r1, s32 *r2) {
    u16 i;
    for (i = 0; i < 10; i++) {
        if ((D_800F7D28[i].flags & 0x8000) && r1[0] >= a->x && a->x >= r1[1] && r2[0] >= a->z && a->z >= r2[1]) {
            return 0;
        }
    }
    return -1;
}
