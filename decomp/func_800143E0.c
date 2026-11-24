typedef short s16; typedef unsigned short u16;
typedef struct { s16 a; char pad[0x1E]; } E;
extern E *D_800F9590; extern u16 D_800F9594; extern E D_800F9598[];
void func_800143E0(void) {
    D_800F9590 = D_800F9598;
    D_800F9594 = 0;
    do {
        D_800F9590->a = 0;
        D_800F9590++;
        D_800F9594++;
    } while (D_800F9594 < 0x28);
}
