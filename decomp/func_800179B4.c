typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
extern u8 D_800F77AD;
extern u16 D_800F0FB0;
extern u8 D_80096AFC[];
void func_80074B04(s32);
void func_80093FF4(void *, s32);
void func_80093F7C(void *, s32);
s32 func_80093FAC(void);
void func_800941A0(void);
void func_800149AC(s32);
s32 func_800179B4(s32 arg0) {
    func_80074B04(0x18F);
    D_800F77AD = 1;
    if (arg0 == 1) {
        func_80093FF4(D_80096AFC, 1);
        return 0;
    }
    func_80093F7C(D_80096AFC, 1);
    while (func_80093FAC() == 1) {
        if (D_800F0FB0 & 0x840) {
            func_800941A0();
            func_800149AC(1);
            return 1;
        }
        func_800149AC(1);
    }
    return 0;
}
