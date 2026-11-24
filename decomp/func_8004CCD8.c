#include "m2c_macros.h"
typedef unsigned char u8; typedef short s16;
typedef struct { char pad[0x1704]; s16 a; char pad2[0x1724 - 0x1706]; int b; int c; } S;
extern u8 D_800F0F42;
extern S D_800F7D28;
void func_80079F84(int, int, int, int, int, int);
void func_8004CCD8(u8 id, int x, int y) {
    if (D_800F0F42 == id) {
        func_80079F84(D_800F7D28.a, x, y, D_800F7D28.b, D_800F7D28.c, 0);
    }
}
