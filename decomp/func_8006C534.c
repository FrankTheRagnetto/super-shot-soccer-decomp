#include "m2c_macros.h"
typedef short s16;
typedef struct { s16 m[3][3]; int t[3]; } MATRIX;
typedef struct { char pad[0x28]; MATRIX mat; } O;
void func_800A0F88(void *, int, int);
void func_8006C534(O *o) {
    int i;
    func_800A0F88(&o->mat, 0, sizeof(MATRIX));
    for (i = 0; i < 3; i++) {
        o->mat.m[i][i] = 0x1000;
    }
}
