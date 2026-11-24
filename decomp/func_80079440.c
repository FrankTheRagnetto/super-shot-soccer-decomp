typedef unsigned char u8;
typedef struct { char pad[0x14]; u8 x14; } S;
S *func_80079490(u8);
extern u8 D_800DC330[];
u8 func_80079440(u8 arg0) {
    S *p = func_80079490(arg0);
    return D_800DC330[p->x14];
}
