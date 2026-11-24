typedef unsigned char u8;
typedef int s32;
#include "m2c_macros.h"

extern u8 D_8010C7B8;

void func_800941E0(s32 arg0) {
    u8 *var_a1;
    s32 mask;
    s32 var_a3;

    var_a1 = &D_8010C7B8;
    mask = ~0x40;
    var_a3 = 0xC7;
    do {
        if (M2C_FIELD(var_a1, u8 *, 0) != 0) {
            M2C_FIELD(var_a1, s32 *, 0x90) = 0;
            M2C_FIELD(var_a1, s32 *, 0x8C) = 0;
            M2C_FIELD(var_a1, s32 *, 0x88) = 0;
            M2C_FIELD(var_a1, s32 *, 4) = (s32) (M2C_FIELD(var_a1, s32 *, 4) & mask);
            M2C_FIELD(var_a1, u8 *, 1) = (u8) (M2C_FIELD(var_a1, u8 *, 1) | 0x10);
            M2C_FIELD(var_a1, s32 *, 0x70) = (s32) ((s32) -M2C_FIELD(var_a1, s32 *, 0x58) / arg0);
            M2C_FIELD(var_a1, s32 *, 0x74) = (s32) ((s32) -M2C_FIELD(var_a1, s32 *, 0x5C) / arg0);
            M2C_FIELD(var_a1, s32 *, 0x78) = (s32) ((s32) -M2C_FIELD(var_a1, s32 *, 0x60) / arg0);
        }
        var_a3 -= 1;
        var_a1 += 0xC8;
    } while (var_a3 >= 0);
}
