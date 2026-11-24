typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct { char p0[0x1718]; s32 x1718; s32 x171C; } G;
extern G D_800F7D28;
s32 func_80026070(u16);
s32 func_8004685C(u8 arg0, s32 arg1) {
    if (D_800F7D28.x171C - arg1 > -0xB83C10 && D_800F7D28.x171C + arg1 <= 0xB83C0F) {
        if (func_80026070(arg0) == 0) {
            if (D_800F7D28.x1718 - arg1 > 0x12147A9) {
                return 0;
            }
        } else {
            if (D_800F7D28.x1718 + arg1 < -0x12147A9) {
                return 0;
            }
        }
    }
    return -1;
}
