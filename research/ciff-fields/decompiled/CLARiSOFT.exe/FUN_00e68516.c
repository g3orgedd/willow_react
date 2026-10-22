// Source: CLARiSOFT.exe @ 00e68516; FUN_00e68516

void FUN_00e68516(int *param_1,int *param_2)

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


