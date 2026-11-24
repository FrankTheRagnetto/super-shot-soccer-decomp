#include "m2c_macros.h"
typedef unsigned short u16;
void func_80015298(u16, int);
void func_80015388(u16, int, int, int);
void func_80015144(u16 y, u16 side, u16 mode) {
    int w;
    int x = y;
    int o = 0x19;
    if (side == 1) {
        o = 0x63;
    }
    if (mode == 1) {
        func_80015298(o + x, 0);
        w = 0x93;
    } else {
        func_80015298(o + x, 1);
        w = 0x138;
    }
    o = 0x3E;
    if (side == 1) {
        o = 0x88;
    }
    func_80015388(o + x, w, 10, 15);
}
