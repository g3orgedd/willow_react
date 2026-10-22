// Source: CLCSSmallBarcode.dll @ 420108b7; FUN_420108b7

undefined4 * __fastcall FUN_420108b7(undefined4 *param_1)

{
  FUN_4200a000(param_1);
  param_1[10] = 7;
  param_1[0xb] = 7;
  *param_1 = CEAN8Barcode::vftable;
  param_1[0xc] = 8;
  return param_1;
}


