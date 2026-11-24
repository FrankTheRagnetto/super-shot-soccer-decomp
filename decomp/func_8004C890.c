typedef unsigned char u8; typedef short s16; typedef int s32;
extern u8 D_800F0F42; extern u8 D_800F7C71; extern u8 D_800F0EE5;
void func_8004EF9C(void *, u8, s32, s32); void func_8002E9EC(s32, u8, s32); void func_8007C154(void *, u8, s16, u8);
void func_8004C890(void *arg0, u8 arg1, s16 arg2, u8 arg3) {
    if (D_800F0F42 == 0x17) {
        D_800F7C71 = arg1;
        func_8004EF9C(arg0, arg1, 4, 0);
        D_800F0F42 = 0x17;
        D_800F0EE5 = 0x17;
        func_8002E9EC(3, arg1, 0);
        func_8007C154(arg0, arg1, arg2, arg3);
    }
}
