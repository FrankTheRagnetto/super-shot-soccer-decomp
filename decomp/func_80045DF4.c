typedef unsigned char u8; typedef int s32;
extern u8 D_800D16C4[];
void D_800515CC(void);
s32 func_800147C0(s32); void func_80014644(void (*)(void), s32, u8, s32, s32); void func_800469C8(void);
void func_80045DF4(u8 arg0, s32 arg1) {
    s32 id = 11;
    s32 r;
    if (arg0 < 11) {
        id = 10;
    }
    r = func_800147C0(id);
    if (r == 1 && D_800D16C4[arg1 / 3] != 0xFF) {
        func_80014644(D_800515CC, id, arg0, arg1, r);
    }
    func_800469C8();
}
