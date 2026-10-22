// Source: CLCSBarcodeField.dll @ 4144d093; FUN_4144d093

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_4144d093(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *local_18;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = PTR_DAT_414a9018;
  local_8 = 0;
  local_14 = 1;
  if (DAT_414b17b8 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)FUN_41460343(0x1c);
    local_8 = 1;
    if (local_18 == (undefined4 *)0x0) {
      DAT_414b17b8 = (undefined4 *)0x0;
    }
    else {
      DAT_414b17b8 = FUN_41406f2c(local_18);
    }
    local_8 = local_8 & 0xffffff00;
  }
  piVar1 = (int *)FUN_414071ce(DAT_414b17b8,&local_18,param_2);
  local_8 = 2;
  FUN_414070eb(param_1,piVar1);
  FUN_414031f1((int *)&local_18);
  return param_1;
}


