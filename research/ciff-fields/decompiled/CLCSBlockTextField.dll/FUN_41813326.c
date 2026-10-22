// Source: CLCSBlockTextField.dll @ 41813326; FUN_41813326

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_41813326(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *local_18;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = PTR_DAT_41844110;
  local_8 = 0;
  local_14 = 1;
  if (DAT_41849ac0 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)FUN_4181c864(0x1c);
    local_8 = 1;
    if (local_18 == (undefined4 *)0x0) {
      DAT_41849ac0 = (undefined4 *)0x0;
    }
    else {
      DAT_41849ac0 = FUN_41804ccc(local_18);
    }
    local_8 = local_8 & 0xffffff00;
  }
  piVar1 = (int *)FUN_4180501c(DAT_41849ac0,&local_18,param_2);
  local_8 = 2;
  FUN_41804ebb(param_1,piVar1);
  FUN_41801600((int *)&local_18);
  return param_1;
}


