typedef int s32; typedef short s16; typedef unsigned char u8;
extern s32 D_801028D4;
extern u8 D_80102938, D_8010296E;
s16 func_800751B0(s32);
s16 func_80078CBC(void) {
    s16 v = func_800751B0(D_801028D4);
    D_801028D4 += 2;
    if (D_80102938 == 1 && D_8010296E == 1) {
        return v + 0x800;
    }
    return v;
}
