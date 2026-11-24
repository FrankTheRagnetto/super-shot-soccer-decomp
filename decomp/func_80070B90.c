
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
void func_80070B90(void *arg0, unsigned long long arg2)
{
  char *new_var;
  char *new_var2;
  char *new_var3;
  *((s16 *) (((char *) arg0) + 0xC)) = 0;
  new_var = arg0;
  new_var2 = ((char *) new_var) + 0xE;
  new_var = new_var2;
  *((s8 *) (new_var3 = new_var)) = arg2;
}
