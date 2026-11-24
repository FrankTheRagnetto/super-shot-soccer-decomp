typedef unsigned char u8; typedef unsigned short u16; typedef int s32;
typedef struct { u8 a; u16 b; s32 c; s32 d; } E;
extern u8 D_80104788; extern E D_80107190[];
void func_8008C5D4(void) {
    s32 i;
    if (--D_80104788 != 0) {
        for (i = 0; i < D_80104788; i++) {
            D_80107190[i].b = D_80107190[i + 1].b;
            D_80107190[i].a = D_80107190[i + 1].a;
            D_80107190[i].c = D_80107190[i + 1].c;
            D_80107190[i].d = D_80107190[i + 1].d;
        }
    } else {
        D_80107190[0].a = 0;
        D_80107190[0].b = 0;
    }
}
