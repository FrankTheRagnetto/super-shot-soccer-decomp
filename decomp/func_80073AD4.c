typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

typedef struct { u8 b[256]; } Rec256;
extern Rec256 D_800F7D28[];
extern u32 D_800F0F48[];
int func_800734D4(Rec256 *);

u16 func_80073AD4(u16 arg0) {
    u16 i;
    u16 best;
    u32 min;

    best = 0x1F;
    min = -1;
    for (i = arg0; i < arg0 + 10; i++) {
        if (func_800734D4(&D_800F7D28[i]) == 0) {
            if (D_800F0F48[i] < min) {
                min = D_800F0F48[i];
                best = i;
            }
        }
    }
    return best;
}
