
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
extern u16 D_800F7D28;
extern u8 D_8010C77B;
extern u8 D_8010C77C;
u8 func_80093AB4(s32 arg0, s32 arg1)
{
  int new_var;
  u16 *new_var2;
  s32 var_a1;
  new_var = arg0 & 0xFF;
  var_a1 = arg1 & 0x1F;
  switch (var_a1)
  {
    case 22:
      break;

    case 30:
      var_a1 = (s32) D_8010C77B;
      break;

    case 31:
      var_a1 = (s32) D_8010C77C;
      break;

    default:
      if (new_var != D_800F7C70)
    {
      var_a1 = (var_a1 + 0xB) & 0xFF;
    }
      break;

  }

  new_var2 = &D_800F7D28;
  *((typeof(D_800F7D28) *) ((char *) ((typeof(D_800F7D28) *) (((char *) new_var2) + (var_a1 << 8))))) = 0x8000;
  return (u8) var_a1;
}
