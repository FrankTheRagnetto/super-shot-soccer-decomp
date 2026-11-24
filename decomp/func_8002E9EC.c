typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u8 a, b, c; } T3;
extern T3 D_800F7CB8[];
extern u16 D_800F77A8;
void func_8002E9EC(u8 arg0, u8 arg1, u8 arg2) {
    if (D_800F77A8 >= 10) {
        D_800F77A8 = 0;
    }
    D_800F7CB8[D_800F77A8].a = arg0;
    D_800F7CB8[D_800F77A8].b = arg1;
    D_800F7CB8[D_800F77A8].c = arg2;
    D_800F77A8++;
}
