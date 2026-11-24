#include "m2c_macros.h"
typedef unsigned char u8;
typedef struct { char pad[0x18]; int x; } O;
int func_80026070(u8);
void func_800500F4(void *, u8);
void func_8002E960(u8);
/* own body matches 27/27; target span (39 words) also holds D_8004F564, written below */
int func_8004F4F8(O *o, u8 side) {
    int r = -1;
    if (func_80026070(side) == 0) {
        if (o->x < 0) {
            r = 0;
        }
    } else {
        if (o->x > 0) {
            r = 0;
        }
    }
    return r;
}
void D_8004F564(void *o, u8 id) {
    func_800500F4(o, id);
    func_8002E960(id);
}
