typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct {
    u8 pad0[0x14];
    MATRIX mat;
    u16 unk34;
} Obj;

void func_800A0F88(void *, s32, s32);

void func_800627E0(Obj *obj, u16 arg1) {
    s32 i;

    obj->unk34 = arg1;
    func_800A0F88(&obj->mat, 0, sizeof(MATRIX));
    for (i = 0; i < 3; i++) {
        obj->mat.m[i][i] = 0x1000;
    }
}
