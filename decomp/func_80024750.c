typedef int s32; typedef signed char s8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned char u8;
extern u16 D_800FB58C;
extern u8 D_800F7C70;
u16 func_80023C44(void);
void func_800149AC(s32);
s32 func_80024750(u16 arg0, s8 arg1) {
    u16 i;
    for (i = 0; i < arg0; i++) {
        u16 v = func_80023C44();
        u32 k = v & 0x1F;
        if (k == 0x14) {
            D_800FB58C = v;
            return 1;
        }
        if (arg1 == 1 && k - 0x12 < 2) {
            if (D_800F7C70 == 0) {
                D_800FB58C = 0x32;
            } else {
                D_800FB58C = 0x12;
            }
            return 1;
        }
        func_800149AC(1);
    }
    return 0;
}
