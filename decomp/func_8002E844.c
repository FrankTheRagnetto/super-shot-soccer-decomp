#include "m2c_macros.h"
typedef unsigned short u16;
void func_800147A8(int);
void func_8002E844(void) {
    u16 i; for (i = 0; i < 24; i++) { if (i == 22) continue; func_800147A8(i + 16); }
}
