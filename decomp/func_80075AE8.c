typedef int s32; typedef short s16; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { s32 a; s16 b, c, d, e; u8 f, g, h; } SP;
#define S ((SP *)0x1F800000)
void func_800AADF8(SP *, void *, u16);
void func_80075AE8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, u8 arg7, u8 arg8, u8 arg9) {
    s32 v = 0;
    if (arg2 != 4) {
        v = (arg2 | 4) << 28;
    }
    S->a = v;
    S->b = arg3;
    S->c = arg4;
    S->d = arg5;
    S->e = arg6;
    S->f = arg7;
    S->g = arg8;
    S->h = arg9;
    func_800AADF8(S, arg0, arg1);
}
