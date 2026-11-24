typedef unsigned short u16;
int func_80014758();
void func_8002E894(void) {
    u16 i;
    for (i = 0; i < 0x18; i++) {
        if (i != 0x16) {
            func_80014758(i + 0x10);
        }
    }
}
