typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { u8 pad[0x18]; s32 x; s32 z; } Obj;
s32 rsin(s32);
s32 rcos_v3(s32);
s32 func_80075D48(s32, s32);
void func_8004CE6C(Obj *arg0, s32 arg1, s32 dist, s16 ang, s32 *out) {
    out[0] = arg0->x - func_80075D48(rsin(ang), dist);
    out[1] = arg0->z - func_80075D48(rcos_v3(ang), dist);
}
