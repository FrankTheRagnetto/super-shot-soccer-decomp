typedef int s32; typedef unsigned short u16; typedef unsigned char u8; typedef short s16;
extern u16 D_800F0E8E;
extern u8 D_800F9AD8[];
extern u8 D_800F9AE8;
extern s16 D_800F9AC0;
void func_800169E4(void) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if (D_800F0E8E == D_800F9AD8[i]) {
            break;
        }
    }
    D_800F9AE8 = i + 0x64;
    D_800F9AC0 = 0;
}
