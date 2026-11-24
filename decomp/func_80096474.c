typedef int s32;
typedef struct { s32 x, y; } V;
typedef struct { s32 h0, h1; V arr[1][25]; } S;
extern S D_8010C7B8;
void func_80096474(s32 arg0, s32 arg1, V *arg2) {
    arg2->x = D_8010C7B8.arr[arg0][arg1].x;
    arg2->y = D_8010C7B8.arr[arg0][arg1].y;
}
