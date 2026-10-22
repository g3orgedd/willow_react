// Source: CLCiffConversion_Layout.dll @ 45412fba; FUN_45412fba

void __fastcall FUN_45412fba(int *param_1)

{
  int *piVar1;
  
  FUN_454160f3((int)param_1);
  FUN_454223fd(param_1 + 6);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45402c5d(param_1 + 2);
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45402c5d(param_1);
  return;
}


