
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
void func_8007E46C(void)
{
  char *new_var;
  new_var = (char *) (&D_800F7D28);
  *((u16 *) (new_var + 0x1704)) = (u16) (0x800 - (*((u16 *) (new_var + 0x1704))));
  func_80046084(0x17U);
  *((s16 *) (new_var + 0x1706)) = 0;
}
