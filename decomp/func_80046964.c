typedef int s32; typedef short s16;
typedef struct { s16 x, y, w, h; } RECT;
extern RECT D_800D16B4[];
extern s32 D_800FC370;
void MoveImage_v3(RECT *, s32, s32);
void func_80046964(void) {
    if (D_800FC370 == 0) {
        RECT *dst = D_800D16B4;
        RECT *src = dst - 2;
        D_800FC370 = 1;
        MoveImage_v3(&dst[0], src[0].x, src[0].y);
        MoveImage_v3(&dst[1], src[1].x, src[1].y);
    }
}
