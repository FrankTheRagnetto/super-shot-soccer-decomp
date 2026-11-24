#include "m2c_macros.h"
typedef unsigned char u8; typedef unsigned short u16;
typedef struct { char pad[0x2C]; int b; int pad2; int a; } O;
void func_8001C3F0();
void func_8004DEE4(O *o, u8 id, int unused, int a, int b, u16 c) {
    func_8001C3F0(o, id, 0x30, 0x159, 0xE3, (u8)c);
    o->b = b;
    o->a = a;
}
