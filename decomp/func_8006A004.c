typedef short s16; typedef unsigned short u16; typedef int s32;
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { char pad[0x14]; MATRIX mat; char pad2[8]; u16 x3C; } S;
int func_800A0F88();
void func_8006A004(S *arg0, u16 arg1) {
    s32 i, j;
    MATRIX *m = &arg0->mat;
    arg0->x3C = arg1;
    func_800A0F88(m, 0, 0x20);
    for (i = 0, j = 2; i < 3; i++, j--) {
        m->m[j][j] = 0x1000;
    }
}
