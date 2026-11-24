typedef int s32;
typedef struct { char pad[0x18]; s32 x; s32 y; } S;
s32 func_8004B600(S *arg0, s32 arg1, s32 arg2) {
    arg1 = (arg1 - arg0->x) >> 12;
    arg2 = (arg2 - arg0->y) >> 12;
    return arg1 * arg1 + arg2 * arg2;
}
