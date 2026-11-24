typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

typedef struct { s32 vx, vy, vz; } VECTOR;
typedef struct { u8 r, g, b, cd; } CVECTOR;

void func_800947E8(VECTOR *v, CVECTOR *c) {
    v->vx = c->r << 12;
    v->vy = (*(u16 *)c & 0xFF00) << 4;
    v->vz = c->b << 12;
}
