typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 a; s32 x[1]; } S;
S *func_80017F64();
void func_80018544();
extern s32 D_800D0838;
extern s32 D_800D083C[][3];

s32 func_800185D8(s32 arg0, s32 arg1) {
    S *p;
    s32 i;
    s32 v;

    p = func_80017F64(arg0);
    if (p == NULL) {
        return -1;
    }
    for (i = 0; i < D_800D0838; i++) {
        v = D_800D083C[i][arg1];
        if (v >= i) {
            func_80018544(p->x[i], p->x[v]);
        }
    }
    return 0;
}
