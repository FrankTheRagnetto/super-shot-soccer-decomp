typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

typedef struct { u8 pad[0xBE]; u8 fBE; } ObjBE;
extern u8 D_800E9624;
extern s16 D_800F9560[];
extern u32 D_800E9780[];
int func_8004CB38(s16, s16);

s32 func_8003BCB4(ObjBE *arg0, u8 arg1, s16 arg2) {
    s32 ret;

    ret = 0;
    if (D_800E9624 == 0) {
        if (arg0->fBE != 0) {
            ret = 1;
        } else {
            if ((u32)((s16) func_8004CB38(arg2, D_800F9560[arg1]) - 0x201) < 0x3FF) {
                if (D_800E9780[arg1] < 0x57E4) {
                    ret = 1;
                }
            } else {
                if (D_800E9780[arg1] < 0x3A24) {
                    ret = 1;
                }
            }
        }
    }
    return ret;
}
