typedef int s32;
typedef struct { s32 flags; void *p; char pad[0x10]; } E;
extern E D_800E97E0[];
extern s32 D_800F0EE8;
void func_800AF6D8(s32, E *);
void func_800152F8(s32 arg0, s32 arg1) {
    E *e = &D_800E97E0[arg1];
    func_800AF6D8(arg0, e);
    e->p = &D_800F0EE8;
    e->flags &= 0x7FFFFFFF;
}
