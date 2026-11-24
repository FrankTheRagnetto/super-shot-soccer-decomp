typedef int s32; typedef short s16;
typedef struct { s32 a; s16 x, y, w, h; s32 rest[6]; } S36;
typedef struct { s32 w[5]; } T20;
extern S36 D_800DB990[];
extern T20 D_800ECDD0[];
extern s32 D_800E9628;
void func_800AB668(S36 *, T20 *, s32);
void func_8001B98C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S36 s;
    s = D_800DB990[arg0 + 2];
    s.x = arg1 - 10;
    s.y = arg2 - 20;
    if (arg3 != 0) {
        s.h = 0x15;
    }
    func_800AB668(&s, &D_800ECDD0[D_800E9628], 4);
}
