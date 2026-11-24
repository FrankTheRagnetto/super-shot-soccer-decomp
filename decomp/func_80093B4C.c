
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
extern u8 D_800F7C70;
extern u8 D_8010C77B;
extern u8 D_8010C77C;
int func_8007717C();
void func_80093B4C(s32 arg0, s32 arg1)
{
  int new_var;
  s32 var_a1;
  u8 var_a0;
  long new_var2;
  new_var = arg0 & 0xFF;
  var_a1 = arg1 & 0x1F;
  switch (var_a1)
  {
    case 30:
      var_a0 = D_8010C77B;
      break;

    case 31:
      var_a0 = D_8010C77C;
      break;

    case 23:
      var_a0 = 0x17;
      break;

    case 22:
      var_a0 = 0x16;
      break;

    default:
      if (new_var != D_800F7C70)
    {
      var_a1 = (var_a1 - -0xB) & 0xFF;
    }
      new_var2 = (u8) var_a1;
      var_a0 = new_var2 ^ 0;
      break;

  }

  func_8007717C(var_a0, var_a1);
}
