typedef int s32; typedef short s16;
typedef struct { s16 a; s16 b; s32 c; s32 d; } E;
extern E D_8010C428[];
void func_800C5B80(s32);
void func_8008E3B8(s32 arg0) {
    if (D_8010C428[arg0].a < 0x18) {
        func_800C5B80(D_8010C428[arg0].a);
    }
    D_8010C428[arg0].a = 0xFF;
    D_8010C428[arg0].b = 0;
    D_8010C428[arg0].c = 0;
    D_8010C428[arg0].d = 0;
}
