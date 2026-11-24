
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
extern u8 D_800F0F42;
extern u16 D_800F7D28;
void func_80051128(u8 arg0, s32 arg1, s32 arg2)
{
  int new_var;
  if ((arg0 & 0xFF) == D_800F0F42)
  {
    new_var = 0x1724;
    *((s32 *) (((char *) (&D_800F7D28)) + new_var)) = arg1;
    *((s32 *) (((char *) (&D_800F7D28)) + 0x1728)) = 0x2000;
    *((s32 *) (((char *) (&D_800F7D28)) + 0x1720)) = (s32) ((*((s32 *) (((char *) (&D_800F7D28)) + 0x1720))) - arg2);
  }
}
