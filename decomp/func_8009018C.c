typedef unsigned char u8; typedef signed char s8; typedef int s32;
typedef struct { u8 a[7]; u8 b[7]; } S;
extern S D_8010C538; extern u8 D_800F77AD; extern char D_8009C4F8[], D_8009C8CA[];
s32 func_80091238(s32); void func_800141E8(s32); void func_80074B04(s32); void func_8008CFA8(u8, s8);
void func_80093F7C(char *, s32); void func_800149AC(s32); void func_80094164(s32, char *);
void func_8009018C(void) {
    if (func_80091238(0) == 1) {
        D_8010C538.a[0] = D_8010C538.b[0];
        D_8010C538.a[1] = D_8010C538.b[1];
        D_8010C538.a[2] = D_8010C538.b[2];
        D_8010C538.a[3] = D_8010C538.b[3];
        D_8010C538.a[4] = D_8010C538.b[4];
        D_8010C538.a[5] = D_8010C538.b[5];
        D_8010C538.a[6] = D_8010C538.b[6];
        func_800141E8(1);
        func_80074B04(0x191);
        func_8008CFA8(1, 1);
    }
    D_800F77AD = 2;
    func_80093F7C(D_8009C4F8, 1);
    func_800149AC(1);
    func_80094164(1, D_8009C8CA);
    func_800149AC(1);
}
