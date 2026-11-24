typedef unsigned char u8; typedef unsigned short u16; typedef int s32; typedef unsigned int u32;
typedef struct { u16 flags; char pad[0x96]; s32 x98; s32 x9C; char pad2[0x60]; } P;
extern P D_800F7D28[];
u8 func_80025488(u16 arg0) {
    u32 min = -1;
    s32 i;
    s32 best;
    for (i = arg0; i < arg0 + 10; i++) {
        if (D_800F7D28[i].flags & 0x8000) {
            s32 x = D_800F7D28[i].x98 >> 12;
            s32 z = D_800F7D28[i].x9C >> 12;
            u32 d = x * x + z * z;
            if (d < min) {
                min = d;
                best = i;
            }
        }
    }
    return best;
}
