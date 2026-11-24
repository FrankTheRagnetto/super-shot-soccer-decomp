#include "m2c_macros.h"
typedef unsigned char u8;
typedef struct { u8 b[8]; } E;
extern E D_800FA338[][20];
u8 func_80079578(u8 n) {
    int bank = 0;
    if (n >= 11) {
        bank = 1;
        n -= 11;
    }
    return D_800FA338[bank][n].b[0];
}
