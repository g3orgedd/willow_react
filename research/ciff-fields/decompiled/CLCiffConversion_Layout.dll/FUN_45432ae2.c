// Source: CLCiffConversion_Layout.dll @ 45432ae2; __updatetlocinfoEx_nolock

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
      FUN_454327d3(param_2);
      if (((piVar1 != (int *)0x0) && (FUN_454329c2(piVar1), *piVar1 == 0)) &&
         (piVar1 != (int *)&DAT_4545e268)) {
        FUN_45432868(piVar1);
      }
    }
  }
  return param_2;
}


