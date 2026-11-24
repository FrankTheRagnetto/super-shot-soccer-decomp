typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32;
typedef struct { char p0[0x1704]; u16 x1704; char p1[0x1718 - 0x1706]; s32 x1718; s32 x171C; char p2[0x1730 - 0x1720]; s32 x1730; s32 x1734; } G;
typedef struct { char p0[0xA]; u16 xA; char p1[0x18 - 0xC]; s32 x18; s32 x1C; char p2[0x30 - 0x20]; s32 x30; } S;
extern u8 D_800F0F42; extern G D_800F7D28;
s32 rsin(s32); s32 rcos_v3(s32); s32 func_80075D48(s32, s32); void func_8002EB04(void);
void func_8004CD60(S *arg0, u8 arg1, s32 arg2, s16 arg3) {
    if (D_800F0F42 == arg1) {
        D_800F7D28.x1718 = arg0->x18 - func_80075D48(rsin(arg3), arg2);
        D_800F7D28.x171C = arg0->x1C - func_80075D48(rcos_v3(arg3), arg2);
        D_800F7D28.x1704 = arg0->xA;
        D_800F7D28.x1730 = arg0->x30;
        D_800F7D28.x1734 = 0;
        func_8002EB04();
    }
}
