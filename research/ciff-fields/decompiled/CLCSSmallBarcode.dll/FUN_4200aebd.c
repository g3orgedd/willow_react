// Source: CLCSSmallBarcode.dll @ 4200aebd; FUN_4200aebd

void __fastcall FUN_4200aebd(undefined4 *param_1)

{
  *param_1 = CCommonBarcodeRender::vftable;
  SysFreeString((BSTR)param_1[0x40]);
  SysFreeString((BSTR)param_1[0x17]);
  SysFreeString((BSTR)param_1[0x16]);
  SysFreeString((BSTR)param_1[0x12]);
  SysFreeString((BSTR)param_1[10]);
  SysFreeString((BSTR)param_1[9]);
  FUN_4200a167(param_1);
  return;
}


