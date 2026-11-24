#include "m2c_macros.h"
typedef unsigned char u8; typedef short s16;
typedef struct { s16 m[3][3]; int t[3]; } MATRIX;
typedef struct { u8 pad[0x17]; u8 flag; u8 pad2[4]; } E;
typedef struct { u8 pad[0x10]; MATRIX mat; E e[30]; s16 v; u8 a; u8 b; } O;
void func_800A0F88(void *, int, int);
void func_8006D2B4(O *o, s16 v) {
    int i;
    o->a = 0;
    o->v = v;
    o->b = 0;
    for (i = 0; i < 30; i++) {
        o->e[i].flag = 0;
    }
    func_800A0F88(&o->mat, 0, sizeof(MATRIX));
    for (i = 0; i < 3; i++) {
        o->mat.m[i][i] = 0x1000;
    }
}
