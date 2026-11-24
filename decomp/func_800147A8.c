
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
extern u16 D_800F9598;
void func_800147A8(s32 arg0)
{
  char *new_var;
  new_var = (char *) (&D_800F9598);
  *((typeof(D_800F9598) *) ((char *) ((typeof(D_800F9598) *) (new_var + (arg0 << 5))))) = 0;
}
