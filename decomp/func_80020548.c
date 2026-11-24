typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct { u8 pad[0xC]; u8 u0, v0; u16 clut; u8 pad1[4]; u8 u1, v1; u16 tpage; u8 pad2[4]; u8 u2, v2; u16 p2; u8 pad3[4]; u8 u3, v3; u16 p3; } POLY;
typedef struct { char pad[8]; char *ot; } S;
typedef struct { u8 a, b, c; } T;
extern T D_800D0FD8[];
void func_80020548(S *arg0, u8 arg1, u16 arg2, s32 arg3) {
    s32 i;
    POLY *p;
    p = (POLY *)(arg0->ot + arg3);
    for (i = 0; i < 2; i++, p++) {
        p->u2 = p->u3 = D_800D0FD8[arg1].a;
        p->u0 = p->u1 = D_800D0FD8[arg1].c;
        p->v2 = p->v0 = D_800D0FD8[arg1].b;
        p->v1 = p->v3 = D_800D0FD8[arg1].b + 40;
        p->clut = arg2;
    }
}
