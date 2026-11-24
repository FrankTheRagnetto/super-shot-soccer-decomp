typedef int s32; typedef short s16; typedef unsigned char u8;
typedef struct { char pad[0x18]; s32 x; s32 z; } S;
s32 func_80026070(u8);
s32 ratan2_v4(s32, s32);
s16 func_8004B834(S *arg0, u8 arg1) {
    s32 x;
    if (func_80026070(arg1) == 0) {
        x = arg0->x + 0x1C00000;
    } else {
        x = arg0->x - 0x1C00000;
    }
    return ratan2_v4(x, arg0->z);
}
