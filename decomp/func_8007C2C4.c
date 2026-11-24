#include "m2c_macros.h"
typedef unsigned char u8;
int func_8007D448(u8 com, u8 *param, u8 *result);
int func_8007C2C4(u8 com, u8 *param) {
    return func_8007D448(com, param, 0);
}
