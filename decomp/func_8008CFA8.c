typedef signed char s8; typedef unsigned char u8;
typedef struct { s8 a; u8 b; u8 c; } E;
extern u8 D_8010477E; extern E D_80107160[];
void func_800149AC(int);
void func_8008CFA8(u8 arg0, s8 arg1) {
    while (D_8010477E >= 0xF) {
        func_800149AC(1);
    }
    D_80107160[D_8010477E].b = arg0;
    D_80107160[D_8010477E].c = 0;
    D_80107160[D_8010477E].a = arg1;
    D_8010477E++;
}
