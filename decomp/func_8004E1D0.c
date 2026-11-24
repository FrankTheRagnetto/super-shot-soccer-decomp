typedef unsigned char u8; typedef unsigned short u16;
typedef struct { char pad[0x6E]; u16 x6E; char pad2[3]; u8 x73; } S;
u8 func_8004E1D0(S *arg0) {
    u16 t = arg0->x6E;
    u8 r = 0;
    if (t >= 0x24 && t < 0x70) {
        r = arg0->x73;
        if (t & 1) {
            if (r < 0xC) {
                r += 0xC;
            } else {
                r -= 0xC;
            }
        }
    }
    return r;
}
