// Source: CLCSBarcodeField.dll @ 41407b94; FUN_41407b94

undefined4 * __fastcall FUN_41407b94(undefined4 *param_1)

{
  *param_1 = CBarcode::vftable;
  param_1[1] = 0;
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x15] = 7;
  param_1[0x14] = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  param_1[0x1b] = 7;
  param_1[0x1a] = 0;
  *(undefined2 *)(param_1 + 0x16) = 0;
  param_1[0x25] = 0;
  param_1[0x4c] = 0;
  FUN_414093eb((int)param_1);
  return param_1;
}


