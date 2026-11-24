
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
void func_80014758(s32 arg0)
{
  u16 *new_var2;
  u16 *temp_a0;
  int new_var;
  new_var2 = &D_800F9598;
  temp_a0 = (typeof(D_800F9598) *) ((char *) ((typeof(D_800F9598) *) (((char *) new_var2) + (arg0 << 5))));
  *temp_a0 |= (new_var = 0x100);
}
