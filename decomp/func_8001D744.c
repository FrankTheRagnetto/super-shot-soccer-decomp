
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
extern u16 D_800F7D28;
void func_8001D744(void)
{
  char *new_var;
  s32 var_v1;
  new_var = &D_800F7D28;
  var_v1 = 0x15;
  new_var = (char *) new_var;
  do
  {
    *((s8 *) (new_var + 0x79)) = 0;
    var_v1 -= 1;
    new_var += 0x100;
  }
  while (var_v1 >= 0);
}
