typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 flags; char pad[0xFE]; } P;
extern P D_800F7D28[];
extern u8 D_800FC374[];
void D_8003B874();
void func_8002E9C0(void (*)(), P *, u8);
void func_80048678(void) {
    s32 i;
    s32 skip;
    if (D_800FC374[0] == 7) {
        skip = D_800FC374[0];
    } else if (D_800FC374[3] == 7) {
        skip = D_800FC374[3];
    }
    for (i = 0; i < 22; i++) {
        if ((D_800F7D28[i].flags & 0x8000) && i != skip) {
            func_8002E9C0(D_8003B874, &D_800F7D28[i], i);
        }
    }
}
