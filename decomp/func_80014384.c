#include "m2c_macros.h"
typedef unsigned char u8;
extern u8 D_8010C546[];
int func_80014384(void) {
    int i;
    for (i = 0; i < 3; i++) {
        if (D_8010C546[i] != 0) {
            return 1;
        }
    }
    return 0;
}
