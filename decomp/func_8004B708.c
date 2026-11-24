typedef unsigned char u8; typedef short s16; typedef int s32;
typedef struct { char pad[0x18]; s32 x; s32 y; char pad2[0x100 - 0x20]; } S;
extern S D_800F7D28[];
int ratan2_v4();
s16 func_8004B708(S *arg0, u8 arg1) {
    return ratan2_v4(arg0->x - D_800F7D28[arg1].x, arg0->y - D_800F7D28[arg1].y);
}
