// Source: CLCiffConversion_Layout.dll @ 454123e6; FUN_454123e6

undefined4 * __cdecl FUN_454123e6(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
      uVar1 = *param_1;
      *param_1 = 0;
      *param_3 = uVar1;
    }
    param_3 = param_3 + 1;
  }
  return param_3;
}


