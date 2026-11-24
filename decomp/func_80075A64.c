typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;
typedef struct { s32 x0; s16 x4; s16 x6; s16 x8; s16 xA; u8 xC; u8 xD; u8 xE; } S;
#define SP ((S *)0x1F800000)
void func_800AB088(S *, s32, u16);
void func_80075A64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s32 v = 0;
    if (arg2 != 4) {
        v = (arg2 | 4) << 28;
    }
    SP->x0 = v;
    SP->x4 = arg3;
    SP->x6 = arg4;
    SP->x8 = arg5;
    SP->xA = arg6;
    SP->xC = arg7;
    SP->xD = arg8;
    SP->xE = arg9;
    func_800AB088(SP, arg0, arg1);
}
