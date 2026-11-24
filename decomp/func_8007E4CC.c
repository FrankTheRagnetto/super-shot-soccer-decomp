
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
void func_8007E4CC(void)
{
  int new_var;
  new_var = 0x1704;
  *((u16 *) (((char *) (&D_800F7D28)) + new_var)) = (u16) (0x1000 - (*((u16 *) (((char *) (&D_800F7D28)) + new_var))));
  func_80046084(0x17U);
  *((s16 *) (((char *) (&D_800F7D28)) + 0x1706)) = 0;
}
