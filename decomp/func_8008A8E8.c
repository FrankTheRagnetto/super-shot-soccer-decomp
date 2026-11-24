#include "m2c_macros.h"
typedef unsigned char u8;
extern u8 D_80102E28[][11];
u8 func_8008A8E8(u8 n) {
    int bank = 0;
    if (n >= 11) {
        bank = 1;
        n -= 11;
    }
    return D_80102E28[bank][n];
}
