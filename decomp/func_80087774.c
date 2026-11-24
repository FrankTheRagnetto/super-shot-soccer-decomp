typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;

typedef struct { s32 unk0; s16 x; s16 y; s32 rest[7]; } Cfg;     /* 0x24 */
typedef struct { u8 pad[0x1D4]; Cfg cfg; } Tbl;
typedef struct { u8 data[0x14]; } Slot;

extern Tbl D_800DCEB8;
extern s32 D_800E9628;
extern Slot D_800ECDD0[];

void func_800AB668(Cfg *, Slot *, s32);

void func_80087774(s32 x, s32 y) {
    Cfg *c = (Cfg *)0x1F800000; /* scratchpad */

    *c = D_800DCEB8.cfg;
    c->y = y;
    c->x = x;
    func_800AB668(c, &D_800ECDD0[D_800E9628], 3);
}
