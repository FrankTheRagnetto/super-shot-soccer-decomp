
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
extern u8 D_800F77AD;
extern u8 D_8010477E;
extern u8 D_80104FB8;
extern s32 D_80107160;
void func_800149AC();
int func_8008CFA8();
void func_8008D0D8(void)
{
  s32 *new_var;
  if (D_800F77AD == 4)
  {
    if (D_80104FB8 == 2)
    {
      func_8008CFA8(3, 1);
      return;
    }
    goto block_4;
  }
  block_4:
  if (((u8) D_8010477E) >= 0xFU)
  {
    do
    {
      func_800149AC(1);
    }
    while (((u8) D_8010477E) >= 0xFU);
  }

  new_var = &D_80107160;
  *((s8 *) (((char *) ((typeof(D_80107160) *) (((char *) new_var) - (-(D_8010477E * 3))))) + 2)) = 2;
  D_8010477E += 1;
}
