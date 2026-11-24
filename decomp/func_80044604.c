typedef unsigned char u8; typedef unsigned short u16; typedef int s32; typedef unsigned int u32;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern P D_800F7D28[]; extern u32 D_800E9780[];
s32 func_80044604(s32 arg0, u8 arg1, u32 arg2) {
    u16 i;
    u16 start;
    if (arg1 < 11) {
        start = 12;
    } else {
        start = 1;
    }
    for (i = start; i < start + 10; i++) {
        if (!(D_800F7D28[i].flags & 0x2000) && D_800E9780[i] < arg2) {
            return 0;
        }
    }
    return -1;
}
