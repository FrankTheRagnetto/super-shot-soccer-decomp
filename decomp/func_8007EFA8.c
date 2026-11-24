
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
extern s32 D_8007E5C4;
extern u16 D_800F7D28;
extern s8 D_801029E0;
int func_80014550();
void func_8007EFA8(void)
{
  char *new_var;
  *((s8 *) (((char *) (&D_801029E0)) + 0)) = 1;
  new_var = (char *) (&D_800F7D28);
  *((s8 *) (((char *) (&D_801029E0)) + 1)) = 0;
  *((s32 *) (new_var + 0x1728)) = 0x2000;
  if ((*((s32 *) (((char *) (&D_800F7D28)) + 0x1730))) > 0x96000)
  {
    *((s32 *) (((char *) (&D_800F7D28)) + 0x1730)) = 0x96000;
  }
  if ((*((s32 *) (new_var + 0x1724))) > 0xA000)
  {
    *((s32 *) (((char *) (&D_800F7D28)) + 0x1724)) = 0xA000;
  }
  func_80014550(&D_8007E5C4, 0x27);
}
