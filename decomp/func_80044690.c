#include "m2c_macros.h"
typedef unsigned char u8;
extern int D_800FC368[2];
extern u8 D_800FC374[2][3];
void func_80046918(void);
void func_80044690(void) {
    D_800FC368[0] = 0x32000;
    D_800FC368[1] = 0x32000;
    D_800FC374[0][2] = 0x6A;
    D_800FC374[0][0] = 0x6A;
    D_800FC374[1][2] = 0x6A;
    D_800FC374[1][0] = 0x6A;
    func_80046918();
}
