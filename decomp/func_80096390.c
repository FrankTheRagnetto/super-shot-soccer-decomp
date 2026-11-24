#include "m2c_macros.h"
typedef struct { char pad[0x58]; int m[2][3]; char pad2[0xA4 - 0x70]; int sx; int sy; char pad3[0xC8 - 0xAC]; } O;
void func_80096390(O *o, int v) {
    int i, j;
    char *p = (char *)o;
    for (i = 0; i < sizeof(O); i++) {
        *p++ = 0;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            o->m[i][j] = v;
        }
    }
    o->sx = 0x1000;
    o->sy = 0x1000;
}
