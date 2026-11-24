
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
void func_800290B8(void *arg0)
{
  s32 var_a2;
  int new_var;
  int new_var4;
  u16 *new_var5;
  s32 var_a3;
  unsigned int new_var3;
  int new_var2;
  new_var5 = &D_800F7D28;
  var_a3 = (*((s32 *) (((char *) new_var5) + 0x1718))) + (*((s32 *) (((char *) arg0) + 0xA0)));
  var_a2 = (*((s32 *) (((char *) (&D_800F7D28)) + 0x171C))) + (*((s32 *) (((char *) arg0) + 0xA4)));
  new_var = 0xFE488888;
  if (var_a3 < new_var)
  {
    new_var3 = -0x01B77778;
    var_a3 = new_var3;
  }
  else
    if (var_a3 > 0x01B77778)
  {
    var_a3 = 0x01B77778;
  }
  new_var4 = 0xFEE66888;
  if (var_a2 < new_var4)
  {
    new_var2 = 0x01199778;
    var_a2 = -new_var2;
  }
  else
    if (0x01199778 < var_a2)
  {
    var_a2 = 0x01199778;
  }
  *((s32 *) (((char *) arg0) + 0x98)) = var_a3;
  *((s32 *) (((char *) arg0) + 0x9C)) = var_a2;
}
