// Source: CLARiSOFT.exe @ 00e56254; FUN_00e56254

void __fastcall FUN_00e56254(int *param_1)

{
  int *piVar1;
  
  SysFreeString((BSTR)param_1[4]);
  SysFreeString((BSTR)param_1[3]);
  FUN_00e563cb(param_1 + 2);
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


