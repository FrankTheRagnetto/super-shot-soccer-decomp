typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
extern u8 D_8010C77B; extern u8 D_8010C77C; extern u8 D_8010C790[]; extern s32 D_800E9780[];
void func_8002EC40(u8, u8 *, s32 *);
void func_80093E4C(void) {
    s32 buf[12];
    u16 n = 0;
    u16 i;
    for (i = 1; i < 11; i++) {
        if (D_8010C77B != i && D_8010C77C != i) {
            buf[n] = D_800E9780[i]; D_8010C790[n] = i; n++;
        }
    }
    func_8002EC40(n, D_8010C790, buf);
}
