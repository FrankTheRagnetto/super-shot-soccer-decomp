#include "m2c_macros.h"
typedef unsigned char u8; typedef short s16;
extern s16 D_800F77D0[][32];
extern s16 D_800F7858[][32];
void func_80013B70(u8 n) {
    int i;
    for (i = 0; i < 32; i++) {
        D_800F77D0[n][i] = 0;
        D_800F7858[n][i] = 0;
    }
}
