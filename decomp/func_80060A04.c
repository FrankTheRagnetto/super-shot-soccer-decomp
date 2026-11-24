typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;
typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { char pad[0xB]; u8 x; char pad2[2]; } E;
typedef struct { char pad[0xC]; MATRIX mat; E e[30]; u16 x1D0; u8 x1D2; u8 x1D3; } S;
int func_800A0F88();
void func_80060A04(S *arg0, u16 arg1) {
    s32 i, j;
    arg0->x1D2 = 0;
    arg0->x1D0 = arg1;
    arg0->x1D3 = 0;
    for (i = 29; i >= 0; i--) {
        arg0->e[i].x = 0;
    }
    func_800A0F88(&arg0->mat, 0, 0x20);
    for (i = 0, j = 2; i < 3; i++, j--) {
        arg0->mat.m[j][j] = 0x1000;
    }
}
