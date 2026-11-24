typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32;
typedef struct { char p0[0x1718]; s32 x1718; s32 x171C; } S;
extern u8 D_800F0EE5; extern S D_800F7D28; extern s16 D_800F9560[];
s32 func_80026070(u16); s32 ratan2_v4(s32, s32); u32 func_8004CB38(s16, s16);
s32 func_80073428(u8 arg0) {
    s16 a;
    if (D_800F0EE5 < 0x17) {
        s32 x; if (func_80026070(D_800F0EE5) == 0) { x = D_800F7D28.x1718 + 0x01C00000; } else { x = D_800F7D28.x1718 - 0x01C00000; } a = ratan2_v4(x, D_800F7D28.x171C);
        if (func_8004CB38(a, D_800F9560[arg0]) < 0x200) {
            return 1;
        }
    }
    return 0;
}
