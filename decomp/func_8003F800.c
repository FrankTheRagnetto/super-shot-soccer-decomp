typedef int s32; typedef unsigned char u8;
typedef struct { char pad[0x18]; s32 x; char pad2[0xE4]; } P;
extern P D_800F7D28[];
s32 func_80026070(u8);
s32 func_8003F800(u8 arg0, u8 arg1) {
    s32 r = 0;
    if (func_80026070(arg0) == 0) {
        r = D_800F7D28[arg1].x < -0xEC5F8F;
    } else if (D_800F7D28[arg1].x > 0xEC5F8F) {
        r = 1;
    }
    return r;
}
