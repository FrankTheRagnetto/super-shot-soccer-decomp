
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
s32 ResetGraph_v5(s32);
extern u32 D_800E9654;
extern u8 D_8010C54A;
void func_800142C4(s32 arg0, unsigned char arg1)
{
  if (((u32) D_800E9654) > 0x80122FFFU)
  {
    func_800143C0(0x53, 3);
  }
  ResetGraph_v5(0);
  func_80014B7C(0x232, 0x80123000U, 0x800000);
  func_801230BC(arg0, 0, D_8010C54A, arg1 & 0xFF);
}
