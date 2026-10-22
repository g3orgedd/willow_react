// Source: CLCSSmallBarcode.dll @ 4201b06f; FUN_4201b06f

undefined4 * __fastcall FUN_4201b06f(undefined4 *param_1)

{
  FUN_4200a000(param_1);
  param_1[0xb] = 7;
  param_1[0xc] = 7;
  *param_1 = CUPCEBarcode::vftable;
  param_1[10] = 9;
  return param_1;
}


