typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 pad; s32 arr[1]; } Obj;
extern s32 D_800D0838;
extern s32 D_800D083C[][3];
Obj *func_80017FE8();
void func_800183B8();

s32 func_800186A0(s32 arg0, s32 arg1, s32 arg2) {
    Obj *p;
    s32 i;

    p = func_80017FE8(arg0);
    if (p == NULL) {
        return -1;
    }
    for (i = 0; i < D_800D0838; i++) {
        if (p->arr[i] == arg0) {
            break;
        }
    }
    func_800183B8(p, i, D_800D083C[i][arg1], arg2);
    return 0;
}
