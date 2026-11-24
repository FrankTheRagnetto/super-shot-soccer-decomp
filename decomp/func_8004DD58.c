typedef unsigned char u8;
typedef struct { char pad[0x70]; u8 x70; } S;
void func_800149AC(int);
void func_8004DD58(S *arg0) {
    if (!(arg0->x70 & 0x40)) {
        while (!(arg0->x70 & 0x80)) {
            func_800149AC(1);
        }
    }
}
