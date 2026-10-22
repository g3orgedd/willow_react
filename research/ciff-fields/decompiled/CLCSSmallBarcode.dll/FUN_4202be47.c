// Source: CLCSSmallBarcode.dll @ 4202be47; FUN_4202be47

undefined4 * __fastcall FUN_4202be47(undefined4 *param_1)

{
  FUN_42027375(param_1);
  *param_1 = CDataMatrixRender::vftable;
  param_1[0x1f] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  FUN_4202be28((int)(param_1 + 0x34));
  return param_1;
}


