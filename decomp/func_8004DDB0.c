typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32;
#include "m2c_macros.h"

void func_800149AC(int);
void func_8001C3F0(void *, u8, int, int, int, u8);

typedef struct {
    u8 pad[0x73];
    u8 f73;
} Obj73;

typedef struct {
    u8 pad[0x2C];
    s32 f2C;
    s32 f30;
    s32 f34;
} Obj2C;

void func_8004DDB0(Obj73 *arg0, u8 arg1) {
    func_800149AC(1);
    while (arg0->f73 < arg1) {
        func_800149AC(1);
    }
}

void func_8004DDFC(Obj2C *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    func_8001C3F0(arg0, arg1, 0x30, 0x159, 0xE3, arg5);
    arg0->f30 = arg2;
    arg0->f2C = arg4;
    arg0->f34 = arg3;
}
