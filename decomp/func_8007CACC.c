typedef int s32;
typedef struct { char pad[0x1724]; s32 a; s32 b; s32 c; s32 d; s32 e; } S;
extern S D_800F7D28;
void func_8007CACC(void) {
    S *p = &D_800F7D28;
    p->a = 0;
    p->b = 0x666;
    p->d = 0;
    p->e = 0;
}
