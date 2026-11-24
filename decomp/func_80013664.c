typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#include "m2c_macros.h"
#define NULL 0
typedef struct { s16 x, y, w, h; } RECT;
typedef struct { u8 r, g, b; } RGB;
extern s32 D_800F7C74;
extern RGB D_800F790A;
void ClearImage_v3(RECT *, u8, u8, u8);
void ClearImage2_v3(RECT *, u8, u8, u8);
void DrawSync_v2(s32);
void func_80013664(void) {
    RECT r;
    if (D_800F7C74 == 0) {
        r.x = 0;
        r.y = 0;
        r.w = 0x180;
        r.h = 0x1E0;
        ClearImage_v3(&r, D_800F790A.r, D_800F790A.g, D_800F790A.b);
    } else {
        r.x = 0;
        r.y = 0;
        r.w = 0x280;
        r.h = 0x1E0;
        ClearImage2_v3(&r, D_800F790A.r, D_800F790A.g, D_800F790A.b);
    }
    DrawSync_v2(0);
}
