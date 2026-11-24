typedef int s32;
typedef struct { s32 pad; s32 ids[1]; } R;
extern s32 D_800D0838;
extern s32 D_800D083C[][3];
R *func_80017FE8();
s32 func_80018844(s32 arg0, s32 arg1) {
    R *r = func_80017FE8();
    s32 i;
    if (r == 0) {
        return -1;
    }
    for (i = 0; i < D_800D0838; i++) {
        if (r->ids[i] == arg0) {
            break;
        }
    }
    return r->ids[D_800D083C[i][arg1]];
}
