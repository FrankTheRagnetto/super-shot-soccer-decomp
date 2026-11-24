
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
extern u8 D_8010477E;
extern s32 D_80107160;
void func_800149AC();
volatile int func_8008D060(void)
{
  s32 *new_var;
  if (((u8) D_8010477E) >= 0xFU)
  {
    do
    {
      func_800149AC(1);
    }
    while (((u8) D_8010477E) >= 0xFU);
  }
  new_var = &D_80107160;
  *((s8 *) (((char *) ((typeof(D_80107160) *) (((char *) new_var) - (-(D_8010477E * 3))))) + 2)) = 1;
  D_8010477E += 1;
}
