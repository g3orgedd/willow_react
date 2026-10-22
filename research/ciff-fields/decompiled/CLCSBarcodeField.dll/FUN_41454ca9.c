// Source: CLCSBarcodeField.dll @ 41454ca9; FUN_41454ca9

void __fastcall FUN_41454ca9(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CSymbologyChooser::vftable;
  piVar1 = (int *)param_1[0xd];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString((BSTR)param_1[0xc]);
  FUN_414031f1(param_1 + 9);
  if (param_1[5] != 0) {
    ATL::__FreeStdCallThunk((void *)param_1[5]);
  }
  return;
}


