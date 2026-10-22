// Source: CLCSSmallBarcode.dll @ 4201ab37; FUN_4201ab37

undefined4 * __fastcall FUN_4201ab37(undefined4 *param_1)

{
  FUN_4200a000(param_1);
  param_1[10] = 9;
  param_1[0xb] = 9;
  *param_1 = CUPCABarcode::vftable;
  param_1[0xc] = 0xc;
  return param_1;
}


