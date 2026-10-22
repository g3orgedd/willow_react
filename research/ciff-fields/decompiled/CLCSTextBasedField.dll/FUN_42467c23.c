// Source: CLCSTextBasedField.dll @ 42467c23; FUN_42467c23

void __fastcall FUN_42467c23(undefined4 *param_1)

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


