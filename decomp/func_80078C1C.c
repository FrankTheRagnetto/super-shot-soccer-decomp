typedef unsigned char u8; typedef int s32;
extern s32 D_801028D4; extern u8 D_80102938; extern u8 D_8010296E;
s32 func_8007514C(s32);
s32 func_80078C1C(void) {
    s32 v = func_8007514C(D_801028D4);
    D_801028D4 += 4;
    if (D_80102938 == 1 && D_8010296E == 1) {
        return -v;
    }
    return v;
}
