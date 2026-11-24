typedef int s32; typedef signed char s8; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern P D_800F7D28[];
void func_80074068(s8, s32, u8);
void func_800740FC(s8 arg0) {
    u16 i;
    for (i = 0; i < 0x16; i++) {
        if ((D_800F7D28[i].flags & 0x8000) && i != 0 && i != 0xB) {
            if (arg0 == 1) {
                func_80074068(1, 0, i);
            } else {
                func_80074068(arg0, 2, i);
            }
        }
    }
}
