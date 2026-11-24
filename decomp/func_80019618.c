typedef int s32; typedef unsigned char u8;
typedef struct { u8 b[8]; } B8;
typedef struct { u8 a, b, c, pad[3], d; } H;
extern H D_800FA288;
extern B8 D_800FA298[];
extern B8 D_800FA338[];
extern u8 D_80104770, D_800F77AE, D_800F7C5E, D_801028FC;
void func_80019618(void) {
    s32 i;
    for (i = 0; i < 20; i++) {
        D_800FA298[i] = D_800FA338[i];
    }
    D_800FA288.a = D_80104770;
    D_800FA288.b = D_800F77AE;
    D_800FA288.c = D_800F7C5E;
    D_800FA288.d = D_801028FC;
}
