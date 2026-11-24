typedef int s32;
typedef struct { char pad[0x18]; s32 x; s32 y; } S;
int SquareRoot0_v3();
s32 func_8004B634(S *arg0, s32 arg1, s32 arg2) {
    s32 dx = (arg1 - arg0->x) >> 12;
    s32 dy = (arg2 - arg0->y) >> 12;
    return SquareRoot0_v3(dx * dx + dy * dy) << 12;
}
