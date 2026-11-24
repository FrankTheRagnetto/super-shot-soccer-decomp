typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define NULL 0
#include "m2c_macros.h"
typedef struct { s32 x; s32 ids[1]; } E;
extern s32 D_800D0838;
E *func_80017F64(s32);

E *func_80017FE8(s32 arg0) {
    s32 i, j;
    E *p;
    for (i = 0; i < 16; i++) {
        p = func_80017F64(i);
        if (p == NULL) {
            return NULL;
        }
        for (j = 0; j < D_800D0838; j++) {
            if (p->ids[j] == arg0) {
                return p;
            }
        }
    }
    if (i == 16) {
        return NULL;
    }
    return p;
}
