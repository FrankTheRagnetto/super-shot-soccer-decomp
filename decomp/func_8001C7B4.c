#include "m2c_macros.h"
typedef unsigned char u8; typedef unsigned short u16;
extern u8 *D_800F9528;
u8 func_8001C7B4(u16 a) {
    return D_800F9528[((int *)D_800F9528)[a >> 1]];
}
