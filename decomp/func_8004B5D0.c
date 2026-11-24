typedef short s16; typedef int s32;
typedef struct { char pad[0x18]; s32 x; s32 y; } S;
int ratan2_v4();
s16 func_8004B5D0(S *arg0, s32 arg1, s32 arg2) {
    return ratan2_v4(arg0->x - arg1, arg0->y - arg2);
}
