typedef unsigned char u8; typedef int s32;

typedef struct { u8 pad[0x18]; s32 x; } Obj;

s32 func_80026070(u8);

s32 func_8007B70C(Obj *o, u8 team) {
    if (!func_80026070(team)) {
        if (o->x > -0xB851F0) {
            return -1;
        }
    } else if (o->x <= 0xB851EF) {
        return -1;
    }
    return 0;
}
