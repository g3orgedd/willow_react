// Source: CiffMgr.dll @ 68105669; FUN_68105669

void FUN_68105669(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)_Allocate<>(1);
  if (param_1 == (int *)0x0) {
    param_1 = piVar1;
    param_2 = piVar1;
  }
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)param_1;
  }
  if (piVar1 + 1 != (int *)0x0) {
    piVar1[1] = (int)param_2;
  }
  return;
}


