// Source: CLCiffConversion_Layout.dll @ 4540890a; FUN_4540890a

void __fastcall FUN_4540890a(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CInstalledCapabilities::vftable;
  FUN_454089b0((int)param_1);
  SysFreeString((BSTR)param_1[3]);
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


