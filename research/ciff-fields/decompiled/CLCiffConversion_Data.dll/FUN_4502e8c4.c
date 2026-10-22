// Source: CLCiffConversion_Data.dll @ 4502e8c4; __set_errno_from_matherr

/* Library Function - Single Match
    __set_errno_from_matherr
   
   Library: Visual Studio 2019 Release */

void __cdecl __set_errno_from_matherr(int param_1)

{
  int *piVar1;
  
  if (param_1 == 1) {
    piVar1 = __errno();
    *piVar1 = 0x21;
  }
  else if (param_1 - 2U < 2) {
    piVar1 = __errno();
    *piVar1 = 0x22;
    return;
  }
  return;
}


