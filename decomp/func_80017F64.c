typedef unsigned int u32; typedef int s32;
typedef struct { char d[0x64]; } E;
extern E D_800F9AF0[]; extern char D_80010020[];
void *func_800A0FA8(s32, s32); int func_800A0FB8(char *, s32);
E *func_80017F64(u32 arg0) {
    if (arg0 >= 0x10) {
        return 0;
    }
    return &D_800F9AF0[arg0];
}
/* second function at 80017F98, merged into func_80017F64 by the split */
void *L80017F98(s32 arg0) {
    void *p = func_800A0FA8(arg0, 1);
    if (p == 0) {
        func_800A0FB8(D_80010020, arg0);
    }
    return p;
}
