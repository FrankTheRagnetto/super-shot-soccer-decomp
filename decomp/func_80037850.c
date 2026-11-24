typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;

typedef struct {
    u8 pad0[4];
    s16 unk4;
    s16 unk6;
    u8 pad8[2];
    s16 dir;    /* 0x0A */
    u8 padC[0x34 - 0xC];
    s32 unk34;
    u8 pad38[4];
    s32 unk3C;
} Obj;

s32 func_8004CB38(s16, s16);
s32 func_8004CB70(s16, s16);
void func_8001C3F0(Obj *, u8, s32, s32, s32, s32);

void func_80037850(Obj *o, u8 arg1, s16 dir) {
    s32 anim;

    o->unk34 = o->unk3C;
    if ((s16)func_8004CB38(o->dir, dir) < 0x300) {
        anim = 0xE8;
    } else if (func_8004CB70(o->dir, dir) > 0) {
        anim = 0xEA;
    } else {
        anim = 0xEB;
    }
    o->unk4 = dir;
    o->unk6 = dir;
    func_8001C3F0(o, arg1, anim, 0x1C5, 0xE3, 0);
}
