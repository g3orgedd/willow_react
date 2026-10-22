// Source: CLCSSmallBarcode.dll @ 4202c07e; FUN_4202c07e

bool __cdecl FUN_4202c07e(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (0x1d < param_1) {
    uVar1 = 10;
    *param_2 = 10;
  }
  else {
    *param_2 = *(undefined4 *)(&DAT_42093fb4 + param_1 * 0xc);
    uVar1 = *(undefined4 *)(&DAT_42093fb8 + param_1 * 0xc);
  }
  *param_3 = uVar1;
  return 0x1d >= param_1;
}


