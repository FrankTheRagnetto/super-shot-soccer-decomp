typedef int s32; typedef short s16; typedef unsigned short u16;
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { char pad[0x14]; MATRIX mat; char pad2[0x42]; u16 c; } O;
void func_800A0F88(void *, s32, s32);
void func_8005F66C(O *arg0, u16 arg1) {
    s32 i;
    func_800A0F88(&arg0->mat, 0, 0x20);
    for (i = 0; i < 3; i++) {
        arg0->mat.m[i][i] = 0x1000;
    }
    arg0->c = arg1;
}
