
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
extern u8 D_8010C7B8;
void func_80096598(s32 arg0, u16 arg1)
{
  u8 *new_var2;
  u16 new_var;
  new_var2 = &D_8010C7B8;
  new_var = arg1;
  *((u16 *) (((char *) ((typeof(D_8010C7B8) *) ((char *) ((typeof(D_8010C7B8) *) (((char *) new_var2) + (arg0 * 0xC8)))))) + 0x56)) = new_var;
}
