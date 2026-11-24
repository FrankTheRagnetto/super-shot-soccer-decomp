typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; u8 a; u8 st; char pad[0xFC]; } P;
extern P D_800F7D28[];
void func_80073FB4(void) {
    u16 i;
    for (i = 1; i < 0x16; i++) {
        if (D_800F7D28[i].flags & 0x8000) {
            if (i != 0xB) {
                D_800F7D28[i].st = 2;
                D_800F7D28[i].flags &= 0xFFF8;
            }
        }
    }
}
