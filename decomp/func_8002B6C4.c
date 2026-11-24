typedef unsigned char u8;
typedef struct { u8 r, g, b; } C3;
typedef struct { char pad[0xC]; C3 c; } H;
extern u8 D_800E977E, D_800F77AA, D_800F7C59;
extern H D_800DB410;
extern C3 D_800DB3FC, D_800FBDE8, D_800FBE00;
extern C3 D_800DB404[];
void func_8002B6C4(void) {
    D_800E977E = 2;
    D_800F77AA = 1;
    D_800DB410.c.r = D_800DB3FC.r;
    D_800FBDE8.r = D_800DB3FC.r;
    D_800DB410.c.g = D_800DB3FC.g;
    D_800FBDE8.g = D_800DB3FC.g;
    D_800DB410.c.b = D_800DB3FC.b;
    D_800FBDE8.b = D_800DB3FC.b;
    D_800FBE00.r = D_800DB404[D_800F7C59].r;
    D_800FBE00.g = D_800DB404[D_800F7C59].g;
    D_800FBE00.b = D_800DB404[D_800F7C59].b;
}
