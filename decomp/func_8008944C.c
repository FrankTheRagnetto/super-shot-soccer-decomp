typedef int s32; typedef signed char s8; typedef unsigned char u8;
typedef struct { s32 w[6]; } B24;
extern u8 D_801034E9;
void D_80089484(s32 arg0);
void func_80014590(void (*)(s32), s32, s32);
void func_800894D8(void);
void func_80019C8C(s32, B24 *);
void func_8002E6C8(s8);
void func_80014AE0(void);
void func_8008944C(s32 arg0) {
    D_801034E9 = 1;
    func_80014590(D_80089484, 7, arg0);
}
void D_80089484(s32 arg0) {
    B24 a, b;
    func_800894D8();
    func_80019C8C(0, &a);
    func_80019C8C(1, &b);
    func_8002E6C8((s8)arg0);
    D_801034E9 = 0;
    func_80014AE0();
}
