typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"
typedef struct { u8 a, b, c; } Rec3;
extern s8 D_800FC3B0;
extern Rec3 D_800FC374[];
void func_8004B278();
void func_800149AC();
void func_80045ADC();
void func_80014AE0();

void func_8004B1B4(void) {
    D_800FC3B0 = 0;
}

void D_8004B1C0(u8 arg0) {
    s32 i;
    s32 t;

    D_800FC3B0 = 1;
    func_8004B278(arg0, 0x1999);
    for (i = 0; i < 450; i++) {
        if (D_800FC3B0 == 0) {
            func_8004B278(arg0, 0x1999);
        }
        func_800149AC(1);
    }
    t = arg0 >= 11;
    D_800FC374[t].a = 0x6A;
    func_8004B278(arg0, 0x1000);
    func_80045ADC(arg0);
    func_80014AE0();
}
