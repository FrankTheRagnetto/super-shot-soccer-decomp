typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; u8 a; u8 st; char pad[0xFC]; } P;
extern P D_800F7D28[];
s32 func_800741B4(void) {
    s32 r = 0;
    u16 i;
    for (i = 0; i < 0x16; i++) {
        if (i != 0 && i != 0xB) {
            if (D_800F7D28[i].flags & 0x8000) {
                if (D_800F7D28[i].a != 2) {
                    D_800F7D28[i].st = 2;
                    r = -1;
                }
            }
        }
    }
    return r;
}
