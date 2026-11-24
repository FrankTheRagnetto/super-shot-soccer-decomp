typedef int s32;
s32 func_800137DC(s32);
extern s32 D_800FBE70;
extern s32 D_800FBE48;

void func_8002BD8C(void) {
    s32 *p = &D_800FBE70;
    *p = func_800137DC(0xB402);
    D_800FBE48 = *p;
}
