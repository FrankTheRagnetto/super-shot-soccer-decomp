typedef unsigned char u8; typedef short s16; typedef int s32;
typedef struct { s32 a; s16 x; s16 y; s16 w; s16 h; } S;
extern S D_801165B8; extern s32 D_800F7C74; extern s32 D_801165D0; extern u8 D_801165CC; extern u8 D_801165D8;
void func_800965C0(void) {
    D_801165B8.a = 0x60000000;
    if (D_800F7C74 == 0) {
        D_801165B8.x = -0xC0;
        D_801165B8.y = -0x78;
        D_801165B8.w = 0x180;
        D_801165B8.h = 0xF0;
    } else {
        D_801165B8.x = -0x140;
        D_801165B8.y = -0xF0;
        D_801165B8.w = 0x280;
        D_801165B8.h = 0x1E0;
    }
    D_801165D0 = 0;
    D_801165CC = 0;
    D_801165D8 = 0;
}
