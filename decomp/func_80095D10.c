
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
extern s32 D_801165D4;
void func_80095D10(s32 arg0, void *arg1)
{
  u8 temp_v0;
  void *temp_a0;
  char *new_var;
  int new_var2;
  new_var2 = arg0 & 0xFFFF;
  temp_a0 = D_801165D4 + (new_var2 * 0xC);
  *((s32 *) (((char *) arg1) + 4)) = (s32) (((*((u8 *) (((char *) temp_a0) + 0))) << 0x18) | 0x08000040);
  *((s32 *) (((char *) arg1) + 0x38)) = (s32) ((*((u16 *) (((char *) temp_a0) + 2))) << 0xC);
  *((s32 *) (((char *) arg1) + 0x3C)) = (s32) ((*((u16 *) (((char *) temp_a0) + 4))) << 0xC);
  temp_v0 = *((u8 *) (((char *) temp_a0) + 1));
  *((s16 *) (((char *) arg1) + 0x50)) = (s16) ((temp_v0 & 0x1F) | ((temp_v0 & 0x20) << 6));
  new_var = ((char *) temp_a0) + 7;
  *((u8 *) (((char *) arg1) + 0x52)) = (u8) (*((u8 *) (((char *) temp_a0) + 6)));
  *((u8 *) (((char *) arg1) + 0x53)) = (u8) (*((u8 *) new_var));
  *((u16 *) (((char *) arg1) + 0x54)) = (u16) (*((u16 *) (((char *) temp_a0) + 8)));
  *((u16 *) (((char *) arg1) + 0x56)) = (u16) (*((u16 *) (((char *) temp_a0) + 0xA)));
}
