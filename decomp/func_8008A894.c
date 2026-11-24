
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
extern s32 D_800DD7F4;
extern u16 D_800E971E;
extern u8 D_800F77AF;
extern u8 D_800F77B1;
extern u8 D_800F7C5F;
extern u8 D_80104771;
void func_8008A894(void)
{
  char *new_var;
  D_80104771 = 6;
  D_800F77B1 = 0;
  new_var = (char *) (&D_800DD7F4);
  D_800F77AF = *((typeof(D_800DD7F4) *) ((char *) ((typeof(D_800DD7F4) *) (new_var + (D_800E971E * 2)))));
  D_800F7C5F = *((u8 *) (((char *) ((typeof(D_800DD7F4) *) (((char *) (&D_800DD7F4)) + (D_800E971E * 2)))) + 1));
}
