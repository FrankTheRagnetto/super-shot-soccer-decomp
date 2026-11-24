typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

extern u16 D_800F0E8E;
extern u8 D_800F9AD8[];

s32 func_80016560(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_800F0E8E == D_800F9AD8[i]) {
            break;
        }
    }
    return !(i < 8);
}
