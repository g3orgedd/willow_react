// Source: CLCiffConversion_Data.dll @ 4502e8f1; __umatherr

/* Library Function - Single Match
    __umatherr
   
   Library: Visual Studio 2019 Release */

float10 __cdecl __umatherr(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_45052250)[iVar1 * 2] == param_2) {
      iVar2 = *(int *)(iVar1 * 8 + 0x45052254);
      break;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x1d);
  if (iVar2 == 0) {
    __ctrlfp();
    __set_errno_from_matherr(param_1);
  }
  else {
    __ctrlfp();
    iVar2 = FUN_4500ffc2();
    if (iVar2 == 0) {
      __set_errno_from_matherr(param_1);
    }
  }
  return (float10)(double)CONCAT44(in_stack_00000020,in_stack_0000001c);
}


