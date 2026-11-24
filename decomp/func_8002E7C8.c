typedef unsigned char u8; typedef unsigned short u16;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern P D_800F7D28[];
void D_8002E3B0(void);
void func_8002E9C0(void (*)(void), P *, u8);
void func_8007C9B0(void);
void func_8002E7C8(void) {
    u16 i;
    for (i = 0; i < 0x16; i++) {
        if (D_800F7D28[i].flags & 0x8000) {
            func_8002E9C0(D_8002E3B0, &D_800F7D28[i], i);
        }
    }
    func_8007C9B0();
}
