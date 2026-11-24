#include "m2c_macros.h"
extern int D_800FC368[2];
void func_800446E0(void) {
    int i;
    for (i = 0; i < 2; i++) {
        D_800FC368[i] += 0xCC;
        if (D_800FC368[i] > 0x64000) {
            D_800FC368[i] = 0x64000;
        }
    }
}
