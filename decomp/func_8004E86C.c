typedef int s32; typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern P D_800F7D28[];
extern u32 D_800E9780[];
u8 func_8004E86C(s32 arg0, u8 arg1) {
    u32 best = -1;
    u16 start;
    s32 res;
    u16 i;
    if (arg1 < 11) {
        start = 12;
    } else {
        start = 1;
    }
    res = start;
    for (i = start; i < start + 10; i++) {
        if (!(D_800F7D28[i].flags & 0x2000)) {
            if (D_800E9780[i] < best) {
                best = D_800E9780[i];
                res = i;
            }
        }
    }
    return res;
}
