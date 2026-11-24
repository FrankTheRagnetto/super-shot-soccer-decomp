typedef unsigned char u8; typedef int s32;

typedef struct {
    u8 pad[0x1718];
    s32 x;      /* 0x1718 */
    s32 y;      /* 0x171C */
    s32 z;      /* 0x1720 */
    s32 vx;     /* 0x1724 */
    s32 vy;     /* 0x1728 */
    s32 vz;     /* 0x172C */
    s32 u1730;
    s32 u1734;
} Big;

typedef struct { s32 x, y; } Vec2;

extern Big D_800F7D28;
extern Vec2 D_800F9548;

void func_8002EB04(void);
void func_800270F0(s32, s32);
void func_80027284(void);

void func_80025A88(void) {
    D_800F7D28.vx = 0;
    D_800F7D28.z = 0;
    D_800F7D28.u1734 = 0;
    D_800F7D28.u1730 = 0;
    D_800F7D28.vy = 0;
    D_800F7D28.x = D_800F9548.x;
    D_800F7D28.y = D_800F9548.y;
    func_8002EB04();
    func_800270F0(0, 0x2C);
    func_80027284();
}
