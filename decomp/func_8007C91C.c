
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
extern s32 D_80079C8C;
extern u16 D_800F7D28;
int func_80014550();
int func_8002DB80();
int func_80075D48();
int func_8007CA80();
int func_8007DFBC();
int func_8008DFF0();
void func_8007C91C(s32 arg0, s16 arg1, s16 arg2)
{
  int new_var;
  func_8008DFF0(9);
  func_8007CA80();
  new_var = 0x1730;
  *((s32 *) (((char *) (&D_800F7D28)) + new_var)) = func_80075D48(arg0, 0x800);
  *((s16 *) (((char *) (&D_800F7D28)) + 0x1704)) = arg2;
  *((s32 *) (((char *) (&D_800F7D28)) + 0x1728)) = 0x2000;
  func_8007DFBC(arg1);
  func_8002DB80();
  func_80014550(&D_80079C8C, 0x27);
}
