typedef unsigned char u8; typedef int s32;
typedef struct { u8 a; u8 b; u8 c; char pad[0x2D]; } A;
typedef struct { u8 a; u8 b; char pad[0xC6]; } B;
typedef struct { s32 a; s32 b; } V;
extern A D_80116400[]; extern B D_8010C7B8[]; extern V D_801163F8; extern s32 D_801165D4;
void func_80094108(void) {
    s32 i;
    for (i = 0; i < 9; i++) {
        D_80116400[i].a = 0;
        D_80116400[i].c = 0;
    }
    for (i = 0; i < 200; i++) {
        D_8010C7B8[i].b = 0;
        D_8010C7B8[i].a = 0;
    }
    D_801163F8.b = 0;
    D_801163F8.a = 0;
    D_801165D4 = 0;
}
