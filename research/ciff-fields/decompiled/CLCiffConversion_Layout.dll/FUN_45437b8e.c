// Source: CLCiffConversion_Layout.dll @ 45437b8e; __handle_qnan1

/* Library Function - Single Match
    __handle_qnan1
   
   Library: Visual Studio 2012 Release */

float10 __cdecl __handle_qnan1(int param_1,double param_2)

{
  int *piVar1;
  float10 fVar2;
  
  if (DAT_4545e6a0 == 0) {
    fVar2 = __umatherr(1,param_1);
    return fVar2;
  }
  piVar1 = __errno();
  *piVar1 = 0x21;
  __ctrlfp();
  return (float10)param_2;
}


