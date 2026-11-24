typedef unsigned char u8; typedef unsigned short u16; typedef int s32;

s32 func_800824B8(void *, u8, s32);
s32 func_800380E8(void *, u8, s32);
s32 func_8004B598(void *);
u16 func_800818E0(void *, u8, s32, s32);

void func_80081AD8(void *obj, u8 id, u16 want) {
    s32 a;

    do {
        if (func_800824B8(obj, id, 1) == 1) {
            return;
        }
        a = func_800380E8(obj, id, 0);
    } while (func_800818E0(obj, id, a, func_8004B598(obj)) == want);
}
