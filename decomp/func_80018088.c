typedef int s32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 v; u16 pad; } E4;
typedef struct { s32 pad; E4 e[8]; u8 m[8][8]; } R;
typedef struct { u16 a; u16 b; } Out;
extern s32 D_800D0838;
R *func_80017F64(s32);
s32 func_80018088(s32 arg0, s32 arg1, Out *arg2) {
    R *r = func_80017F64(arg0);
    s32 i;
    if (r == 0) {
        return -1;
    }
    arg2->a = r->e[arg1].v;
    arg2->b = 0;
    for (i = 0; i < D_800D0838; i++) {
        if (i != arg1 && r->m[arg1][i] != 0xFF) {
            arg2->b += r->m[arg1][i];
        }
    }
    return 0;
}
