// Source: CLARiSOFT.exe @ 00e0a46c; FUN_00e0a46c

void __fastcall FUN_00e0a46c(undefined4 *param_1)

{
  int *piVar1;
  
  FUN_00e0a371(param_1 + 8);
  FUN_00e0a34f(param_1 + 6);
  FUN_00e0a3b5(param_1 + 4);
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString((BSTR)param_1[1]);
  SysFreeString((BSTR)*param_1);
  return;
}


