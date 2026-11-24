#include "m2c_macros.h"
int func_80074FF8(void);
int func_8007A21C(int base, int kind, int scale) {
    if (kind != 7) {
        return base;
    }
    return base + ((func_80074FF8() * scale) >> 8);
}
