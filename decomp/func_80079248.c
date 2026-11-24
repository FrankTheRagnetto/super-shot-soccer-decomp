typedef int s32; typedef unsigned char u8;
typedef struct { char pad[0x10]; u8 k; } R;
extern s32 D_800DC270[];
extern s32 D_800D1CD4[];
extern u8 D_800F0E84, D_800F0E8C;
R *func_80079490(u8);
s32 func_80075D48(s32, s32);
s32 func_80079248(u8 arg0) {
    R *r = func_80079490(arg0);
    s32 b = D_800DC270[r->k];
    u8 t;
    if (arg0 < 0xB) {
        t = D_800F0E84;
    } else {
        t = D_800F0E8C;
    }
    return func_80075D48(D_800D1CD4[t], b);
}
