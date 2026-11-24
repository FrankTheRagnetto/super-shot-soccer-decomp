
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
int func_800758D8();
int func_80075964();
void func_80075890(u8 arg0, s8 *arg1)
{
  u32 new_var4;
  s32 var_a0;
  u32 new_var5;
  u32 new_var3;
  char new_var2;
  u32 temp_a0;
  unsigned char new_var;
  temp_a0 = func_80075964(arg0 & 0xFF) & 0xFFFF;
  new_var5 = (new_var4 = temp_a0);
  new_var3 = temp_a0;
  var_a0 = new_var3;
  var_a0 = var_a0;
  if (new_var5 >= 0x99U)
  {
    new_var2 = (var_a0 = 0x99 & ((unsigned long) 0xFF));
  }
  new_var = var_a0;
  func_800758D8(new_var, arg1);
}
