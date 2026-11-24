#include "m2c_macros.h"
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16;
typedef struct { u16 flags; u8 pad; s8 v; u8 rest[0x100 - 4]; } P;
extern P D_800F7D28[];
extern u8 D_800E974D;
extern s8 D_800F955D;
/* own body matches 24/24; target span (34 words) also holds an unnamed next function at 0x80073C54, written below */
void func_80073BF4(u8 id, s8 v) {
    u16 f;
    D_800F7D28[id].v = v;
    D_800E974D = id;
    f = D_800F7D28[id].flags & 0xDFFF;
    D_800F7D28[id].flags = f;
    if (D_800F955D != -1) {
        s8 t = D_800F955D | 4;
        D_800F7D28[id].flags = (f & 0xFFF8) | t;
    }
}
void func_80073C54(u8 id, s8 v) {
    D_800F7D28[id].v = v;
    D_800F7D28[id].flags &= 0xDFFF;
}
