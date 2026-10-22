// Source: CLCSSmallBarcode.dll @ 420318e1; FUN_420318e1

undefined4 * __fastcall FUN_420318e1(undefined4 *param_1)

{
  *param_1 = CPDF417Encoder::vftable;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  param_1[3] = 1;
  param_1[5] = 9;
  param_1[6] = 0;
  FUN_4202fd4d(param_1 + 8);
  param_1[0x486] = 1;
  param_1[0x688] = 0;
  return param_1;
}


