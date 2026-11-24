typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

void func_80076070(s32 *, void *, s32, void *);
void func_8007614C(s32 *, void *, s32, void *);

s32 *func_8001FCAC(void *arg0, void *arg1, void *arg2, s32 *arg3, s32 *arg4) {
    s32 n;
    s32 i;
    s32 *q;

    n = *arg3++;
    for (i = 0; i < n; i++) {
        q = &arg4[*arg3 >> 2];
        if (!(*q & 0x10000)) {
            func_80076070(q, arg1, 0xB, arg2);
        } else {
            func_8007614C(q, arg1, 0xB, arg2);
        }
        arg3++;
    }
    return arg3;
}
