#include "m2c_macros.h"
typedef unsigned char u8;
extern u8 D_800F0F41;
extern u8 D_800F0F40;
int func_80079E00(int);
void func_8002EB78(u8 a, u8 b) {
    D_800F0F41 = a;
    D_800F0F40 = b;
    if (!(b & 1)) {
        func_80079E00(3);
    }
}
