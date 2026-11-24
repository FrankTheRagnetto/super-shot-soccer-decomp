typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 a; s16 x, y; s32 rest[7]; } S;
typedef struct { u8 pad[0x14]; } E;
extern S D_800DCEB8[];
extern E D_800ECDD0[];
extern s32 D_800E9628;
void func_800AB668(S *, E *, s32);

void func_80087814(s32 arg0, s32 arg1) {
    S *s = (S *)0x1F800000;
    *s = D_800DCEB8[14];
    s->y = arg1;
    s->x = arg0;
    func_800AB668(s, &D_800ECDD0[D_800E9628], 3);
}
