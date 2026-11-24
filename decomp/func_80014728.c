
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
extern u16 D_800F9598;
void func_80014728(s32 arg0)
{
  int new_var;
  u16 *temp_a0;
  char *new_var2;
  u16 temp_v1;
  new_var2 = (char *) (&D_800F9598);
  temp_a0 = (typeof(D_800F9598) *) ((char *) ((typeof(D_800F9598) *) (new_var2 + (arg0 << 5))));
  temp_v1 = *temp_a0;
  if (temp_v1 & 0x100)
  {
    new_var = temp_v1 & 0xFEFF;
    *temp_a0 = new_var;
  }
}
