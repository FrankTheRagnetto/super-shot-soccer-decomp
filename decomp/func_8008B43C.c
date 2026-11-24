typedef short s16; typedef int s32;
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { s32 x0; MATRIX m; } S;
MATRIX *RotMatrix(void *, MATRIX *);
void func_8008B43C(void *arg0, S *arg1) {
    MATRIX m;
    m.t[0] = arg1->m.t[0];
    m.t[1] = arg1->m.t[1];
    m.t[2] = arg1->m.t[2];
    RotMatrix(arg0, &m);
    arg1->x0 = 0;
    arg1->m = m;
}
