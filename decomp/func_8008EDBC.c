
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
extern s32 D_8008EF10;
extern s32 D_8010C550;
int func_80014550();
int func_8008E0E4();
int func_8008E288();
int func_8008E370();
void func_8008E3B8();
void func_8008EDBC(void)
{
  if (func_8008E370(0) == 0)
  {
    func_8008E0E4(0, 0, 0x80, 0x78);
    func_8008E0E4(1, 0, 0x80, 0x78);
  }
  else
  {
    func_8008E288(0, 0x80, 0x78);
    func_8008E288(1, 0x80, 0x78);
  }
  func_8008E3B8(3);
  func_8008E3B8(6);
  D_8010C550 = 0;
  func_80014550(&D_8008EF10, 8);
}
