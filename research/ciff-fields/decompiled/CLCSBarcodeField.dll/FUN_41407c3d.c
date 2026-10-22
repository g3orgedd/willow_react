// Source: CLCSBarcodeField.dll @ 41407c3d; FUN_41407c3d

void __fastcall FUN_41407c3d(undefined4 *param_1)

{
  *param_1 = CBarcode::vftable;
  if (param_1[1] != 0) {
    DeleteObject((HGDIOBJ)param_1[1]);
  }
  SysFreeString((BSTR)param_1[0x4c]);
  SysFreeString((BSTR)param_1[0x25]);
  FUN_414062a0(param_1 + 0x16,'\x01',0);
  FUN_414062a0(param_1 + 0x10,'\x01',0);
  SysFreeString((BSTR)param_1[0xf]);
  SysFreeString((BSTR)param_1[0xe]);
  FUN_414062a0(param_1 + 2,'\x01',0);
  return;
}


