typedef int s32; typedef unsigned short u16;
typedef struct { char pad[0x1704]; u16 a; u16 pad2; u16 b; u16 c; char pad3[0x24]; s32 v; } G;
extern G D_800F7D28;
extern s32 D_8010C760;
void func_8007E750(void);
void func_800149AC(s32);
void func_8007B694(void) {
    G *g;
    func_8007E750();
    g = &D_800F7D28;
    g->c = g->a;
    g->b += g->v / 200;
    if (D_8010C760 > 0) {
        D_8010C760--;
    }
    func_800149AC(1);
}
