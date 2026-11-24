
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
void func_80059E9C(u16 *arg0, s32 *arg1, s32 arg2)
{
  unsigned int var_v1;
  *((s32 *) (((char *) arg0) + 0)) = (s32) (*((s32 *) (((char *) arg1) + 0)));
  *((u16 *) (((char *) arg0) + 8)) = (u16) (*((u16 *) (((char *) arg1) + 4)));
  *((u16 *) (((char *) arg0) + 0xA)) = (u16) (*((u16 *) (((char *) arg1) + 6)));
  *((u16 *) (((char *) arg0) + 0x18)) = (u16) (*((u16 *) (((char *) arg1) + 0xC)));
  *((u16 *) (((char *) arg0) + 0x1A)) = (u16) (*((u16 *) (((char *) arg1) + 0xE)));
  *((u8 *) (((char *) arg0) + 0xE)) = (u8) (*((u8 *) (((char *) arg1) + 0x10)));
  *((u8 *) (((char *) arg0) + 0xF)) = (u8) (*((u8 *) (((char *) arg1) + 0x11)));
  if ((arg2 & 0xFF) == 1)
  {
    *((s16 *) (((char *) arg0) + 0xC)) = 0x1C;
    var_v1 = 0x3C0;
    var_v1 = (*((u16 *) (((char *) arg1) + 8))) + var_v1;
  }
  else
  {
    *((s16 *) (((char *) arg0) + 0xC)) = 0x1D;
    var_v1 = (*((u16 *) (((char *) arg1) + 8))) + 0x3E0;
  }
  *((s16 *) (((char *) arg0) + 0x10)) = var_v1;
  *((s16 *) (((char *) arg0) + 0x12)) = (s16) ((*((u16 *) (((char *) arg1) + 0xA))) + 0x1C0);
}
