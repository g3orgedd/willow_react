// Source: CLCiffConversion_Layout.dll @ 454353f4; __whiteout

/* Library Function - Single Match
    __whiteout
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2019 Release */

uint __thiscall __whiteout(void *this,int *param_1,FILE *param_2)

{
  uint uVar1;
  uint uVar2;
  
  do {
    *param_1 = *param_1 + 1;
    uVar1 = FUN_4543d1f4(this,param_2);
    if ((WCHAR)uVar1 == L'\xffff') break;
    this = (void *)0x8;
    uVar2 = FUN_45434159((WCHAR)uVar1,8);
  } while (uVar2 != 0);
  return uVar1 & 0xffff;
}


