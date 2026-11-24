typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"
typedef struct { s32 a, b; } Pair;
typedef struct { Pair p; s32 c; } Trip;
typedef struct { u8 pad[10]; u8 idx; } Info;
extern Pair D_800DC208;
extern s32 D_800DC210[];
extern s32 D_800D1E14[];
extern u8 D_800F0E84;
extern u8 D_800F0E8C;
Info *func_80079490();
s32 func_80075D48();

Trip func_800790A4(u8 arg1) {
    Trip t;
    u8 s;
    Info *info;
    u8 i;

    if (arg1 < 11) {
        s = D_800F0E84;
    } else {
        s = D_800F0E8C;
    }
    info = func_80079490(arg1);
    i = info->idx;
    t.p = D_800DC208;
    t.c = func_80075D48(D_800D1E14[s], D_800DC210[i]);
    return t;
}
