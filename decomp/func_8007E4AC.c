typedef short s16; typedef unsigned short u16;
typedef struct { char pad[0x1704]; u16 a; s16 b; } S;
extern S D_800F7D28;
void func_8007E4AC(void) {
    D_800F7D28.b = 0;
    D_800F7D28.a = 0x800 - D_800F7D28.a;
}
