// Source: CLCSSmallBarcode.dll @ 42016472; FUN_42016472

void __fastcall FUN_42016472(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CSymbologyChooser::vftable;
  piVar1 = (int *)param_1[0xd];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString((BSTR)param_1[0xc]);
  FUN_42003103(param_1 + 9);
  if (param_1[5] != 0) {
    ATL::__FreeStdCallThunk((void *)param_1[5]);
  }
  return;
}


