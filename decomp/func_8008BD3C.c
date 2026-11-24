#include "m2c_macros.h"
typedef struct { unsigned int flags; int pad[4]; } V;
extern V D_80102DF8[2];
void func_8008BD3C(int on) {
    V *p = D_80102DF8;
    int i;
    for (i = 0; i < 2; i++, p++) {
        if (on == 1) {
            p->flags &= 0x7FFFFFFF;
        } else {
            p->flags = 0x80000000;
        }
    }
}
