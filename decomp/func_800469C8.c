
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
extern char D_800D16A4;
extern s32 D_800FC2A0;
extern s32 D_800FC320;
extern s32 D_800FC370;
void func_800469C8(void)
{
  if (D_800FC370 == 1)
  {
    D_800FC370 = 0;
    func_800A8110(&D_800D16A4, &D_800FC2A0);
    func_800A8110((&D_800D16A4) + 8, &D_800FC320);
  }
}
