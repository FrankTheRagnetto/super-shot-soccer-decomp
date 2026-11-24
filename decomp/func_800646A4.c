typedef unsigned char u8; typedef unsigned short u16;
typedef struct { char pad[0x1E]; u16 x1E; } A;
typedef struct { char d[0x14]; } B;
typedef struct { char pad[4]; u16 x4; } S;
extern A D_800D4BF4[]; extern B D_800D5CC8[];
void func_80059E9C(char *, B *, u8);
void func_800646A4(S *arg0, u16 arg1, u8 arg2, u8 arg3) {
    char buf[0x28];
    func_80059E9C(buf, &D_800D5CC8[((A *)((arg2 << 5) + (char *)D_800D4BF4))->x1E], arg3);
    arg0->x4 = arg1;
}
