typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 x;
    s32 y;
    char pad[0xC8 - 0x10];
} S;

extern S D_8010C7B8[];

void func_80096400(s32 i, s32 x, s32 y) {
    D_8010C7B8[i].x = x << 12;
    D_8010C7B8[i].y = y << 12;
}
