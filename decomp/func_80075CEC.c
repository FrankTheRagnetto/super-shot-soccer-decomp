typedef int s32;
s32 func_80075CEC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 t = (arg0 * (arg3 - arg5)) + (arg2 * (arg5 - arg1)) + (arg4 * (arg1 - arg3));
    if (t == 0) {
        return 0;
    }
    if (t < 0) {
        return -1;
    }
    return 1;
}
