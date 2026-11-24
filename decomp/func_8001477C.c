typedef int s32; typedef short s16; typedef unsigned short u16;
typedef struct { u16 a; s16 b; char pad[0x1C]; } S;
extern S D_800F9598[];
void func_8001477C(s32 arg0, s32 arg1) {
    S *p;
    S *b = D_800F9598;
    p = b + arg0;
    if (p->a == 0x80) {
        p->b = arg1;
    }
}
