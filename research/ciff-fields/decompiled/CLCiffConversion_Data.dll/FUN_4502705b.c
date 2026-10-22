// Source: CLCiffConversion_Data.dll @ 4502705b; __updatetlocinfoEx_nolock

/* Library Function - Single Match
    __updatetlocinfoEx_nolock
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2019 Release */

int * __cdecl __updatetlocinfoEx_nolock(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  
  if ((param_2 == (int *)0x0) || (param_1 == (undefined4 *)0x0)) {
    param_2 = (int *)0x0;
  }
  else {
    piVar1 = (int *)*param_1;
    if (piVar1 != param_2) {
      *param_1 = param_2;
      FUN_45026d4c(param_2);
      if (((piVar1 != (int *)0x0) && (FUN_45026f3b(piVar1), *piVar1 == 0)) &&
         (piVar1 != (int *)&DAT_45051f98)) {
        FUN_45026de1(piVar1);
      }
    }
  }
  return param_2;
}


