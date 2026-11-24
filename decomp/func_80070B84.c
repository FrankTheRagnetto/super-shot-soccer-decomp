
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
void func_80070B84(void *arg0)
{
  int new_var;
  new_var = 0xFFFF;
  *((s16 *) (((char *) arg0) + 0xC)) = new_var;
}
