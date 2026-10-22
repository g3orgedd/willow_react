// Source: CLCSSmallBarcode.dll @ 42010353; FUN_42010353

undefined4 * __fastcall FUN_42010353(undefined4 *param_1)

{
  FUN_4200a000(param_1);
  *param_1 = CEAN13Barcode::vftable;
  param_1[10] = 0xb;
  param_1[0xb] = 7;
  param_1[0xc] = 0xd;
  return param_1;
}


