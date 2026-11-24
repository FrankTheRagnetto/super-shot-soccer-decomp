
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
extern volatile char D_80116400;
void func_800942A8(s32 arg0)
{
  *((typeof(D_80116400) *) ((char *) ((typeof(D_80116400) *) (((char *) (&D_80116400)) + ((arg0 & 0xFF) * 0x30))))) = 0;
}
