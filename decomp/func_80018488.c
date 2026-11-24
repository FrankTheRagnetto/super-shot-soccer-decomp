typedef int s32;
typedef struct { s32 x0; s32 ids[1]; } T;
extern s32 D_800D0838;
T *func_80017FE8(s32); void func_800183B8(T *, s32, s32, s32);
s32 func_80018488(s32 arg0, s32 arg1, s32 arg2) {
    T *t;
    s32 a, b, i;
    t = func_80017FE8(arg0);
    b = -1;
    if (t == 0) {
        return -2;
    }
    a = -1;
    for (i = 0; i < D_800D0838; i++) {
        if (t->ids[i] == arg0) a = i;
        if (t->ids[i] == arg1) b = i;
    }
    if (b < 0 || a < 0) {
        return -3;
    }
    func_800183B8(t, a, b, arg2);
    return 0;
}
