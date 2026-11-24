typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;

typedef struct { s32 vx, vy, vz, pad; } VECTOR;

typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 x;      /* 0x08 */
    s32 y;      /* 0x0C */
    u8 pad10[0x58 - 0x10];
    VECTOR col; /* 0x58 */
    u8 pad68[0xC0 - 0x68];
    s32 unkC0;
} Obj;

extern u16 D_801165B2;

void func_80075464(s32, u16, s16, s16, u8, s32, u8, u8, u8);

void func_800961FC(Obj *o, s32 arg1, u8 arg2) {
    VECTOR c;

    c.vx = o->col.vx >> 12;
    c.vy = o->col.vy >> 12;
    c.vz = o->col.vz >> 12;
    func_80075464(arg1, o->unk2 << D_801165B2, o->x >> 12, o->y >> 12, arg2, o->unkC0, c.vx, c.vy, c.vz);
}
