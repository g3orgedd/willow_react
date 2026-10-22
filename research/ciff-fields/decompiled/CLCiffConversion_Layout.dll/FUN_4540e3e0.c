// Source: CLCiffConversion_Layout.dll @ 4540e3e0; FUN_4540e3e0

void __fastcall FUN_4540e3e0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ZipherBitmapFont::vftable;
  SysFreeString((BSTR)param_1[0x11]);
  SysFreeString((BSTR)param_1[0xe]);
  SysFreeString((BSTR)param_1[0xd]);
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


