typedef signed char s8; typedef short s16; typedef int s32;
typedef struct { s32 a; s32 b; } V;
typedef struct {
    char p0[0x1706]; s16 x1706;
    char p1[0x1718 - 0x1708]; V x1718;
    char p2[0x1734 - 0x1720]; s32 x1734;
    char p3[0x1798 - 0x1738]; V x1798;
    char p4[0x17CC - 0x17A0]; s32 x17CC;
    s8 x17D0; s8 x17D1; s8 x17D2;
} S;
extern V D_801029C8;
extern S D_800F7D28;
void func_8007CA80(void) {
    D_801029C8.a = 0;
    D_801029C8.b = 0;
    D_800F7D28.x17D1 = 0x6A;
    D_800F7D28.x1706 = 0;
    D_800F7D28.x1734 = 0;
    D_800F7D28.x17CC = 0;
    D_800F7D28.x17D2 = 0;
    D_800F7D28.x17D0 = 0x1F;
    D_800F7D28.x1798 = D_800F7D28.x1718;
}
