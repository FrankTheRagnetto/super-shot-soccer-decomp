
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
s32 func_8008ED20(void)
{
  s32 var_a0;
  int temp_v0;
  temp_v0 = func_80074FF8();
  var_a0 = 0;
  if (temp_v0 >= 0x99U)
  {
    var_a0 = 2;
    if (temp_v0 < 0xCCU)
    {
      var_a0 = 1;
    }
  }
  return var_a0;
}
