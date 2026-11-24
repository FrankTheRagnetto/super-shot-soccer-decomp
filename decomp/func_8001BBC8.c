typedef unsigned char u8; typedef int s32;

extern u8 D_800FA4A8[10];
extern u8 D_801028D2;
extern u8 D_800F7853;

void func_8001BBC8(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        D_800FA4A8[i] = 0;
    }
    i = 0;
    if (D_801028D2 >= 3 && D_801028D2 < 6) {
        i = 3;
    }
    for (; i < 10; i++) {
        D_800FA4A8[i] = D_800F7853;
    }
}
