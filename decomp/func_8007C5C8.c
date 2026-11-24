typedef unsigned char u8; typedef short s16; typedef int s32;

typedef struct {
    u8 pad[0x1704];
    s16 unk1704;
    u8 pad1706[0x1728 - 0x1706];
    s32 unk1728;
} Big;

extern Big D_800F7D28;
extern s32 D_800DCD38;
void D_80079C8C(void);

void func_8008DFF0(s32);
void func_8007CA80(void);
void func_8007D490(u8, s32, s32);
void func_80014550(void (*)(void), s32);

s16 func_8007C5C8(u8 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg3 == 1) {
        func_8008DFF0(9);
    }
    func_8007CA80();
    D_800F7D28.unk1728 = D_800DCD38;
    func_8007D490(arg0, arg1, 1);
    func_80014550(D_80079C8C, 0x27);
    return D_800F7D28.unk1704;
}
