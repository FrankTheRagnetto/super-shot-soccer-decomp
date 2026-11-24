#include "m2c_macros.h"
typedef unsigned char u8; typedef unsigned short u16;
typedef struct { u8 pad[2]; u8 a; u8 b; u16 cur; u8 pad2[4]; u16 next; u8 pad3[0xC9 - 0xC]; u8 stop; } O;
void func_800149AC(int);
void func_80033F40(O *o, u16 n) {
    u16 i;
    for (i = 0; i < n; i++) {
        if (o->stop) {
            break;
        }
        o->cur = o->next;
        if (o->a != o->b) {
            break;
        }
        func_800149AC(1);
    }
}
