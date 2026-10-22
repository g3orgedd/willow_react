// Source: CLCSSmallBarcode.dll @ 42009458; FUN_42009458

undefined4 * __fastcall FUN_42009458(undefined4 *param_1)

{
  FUN_4200a000(param_1);
  param_1[10] = 0;
  *param_1 = C2DigitAddOnBarcode::vftable;
  param_1[0xb] = 5;
  param_1[0xc] = 2;
  return param_1;
}


