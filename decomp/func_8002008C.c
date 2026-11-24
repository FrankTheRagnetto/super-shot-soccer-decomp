typedef int s32; typedef short s16; typedef unsigned char u8;
typedef struct { s16 a, b, c; } T6;
extern T6 D_800ECD38[];
typedef struct { s32 x, y, z; } V;
typedef struct { char pad[0x18]; V pos; char pad2[0xDC]; } P;
extern P D_800F7D28[];
T6 *func_8002008C(u8 arg0) {
    return &D_800ECD38[arg0];
}
V func_800200AC(u8 arg1) {
    V v;
    v.x = D_800F7D28[arg1].pos.x;
    v.y = D_800F7D28[arg1].pos.y;
    v.z = D_800F7D28[arg1].pos.z;
    return v;
}
