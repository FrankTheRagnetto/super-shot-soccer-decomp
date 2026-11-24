
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
int func_80026070();
s32 func_80082428(u16 *arg0, u8 arg1)
{
  s32 temp_v1;
  s32 temp_v1_2;
  s32 var_s0;
  s32 var_v1;
  temp_v1 = *((s32 *) (((char *) arg0) + 0x1C));
  var_s0 = temp_v1 + 0xB83C10;
  temp_v1_2 = 0xB83C10 - temp_v1;
  var_v1 = 0xB83C10 - temp_v1;
  if (var_v1 < var_s0)
  {
    if (1)
    {
    }
    var_s0 = temp_v1_2;
  }
  if (func_80026070(arg1 & 0xFF) == 0)
  {
    var_v1 = (*((s32 *) (((char *) arg0) + 0x18))) + 0xFEDEB857;
  }
  else
  {
    var_v1 = 0xFEDEB857 - (*((s32 *) (((char *) arg0) + 0x18)));
  }
  var_s0 = var_s0;
  if (var_v1 < var_s0)
  {
    var_s0 = var_v1;
  }
  return var_s0;
}
