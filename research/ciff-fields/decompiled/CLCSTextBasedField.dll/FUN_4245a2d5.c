// Source: CLCSTextBasedField.dll @ 4245a2d5; FUN_4245a2d5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_4245a2d5(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *local_18;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = PTR_DAT_424b9014;
  local_8 = 0;
  local_14 = 1;
  if (DAT_424c1b6c == (undefined4 *)0x0) {
    local_18 = (undefined4 *)FUN_4246d133(0x1c);
    local_8 = 1;
    if (local_18 == (undefined4 *)0x0) {
      DAT_424c1b6c = (undefined4 *)0x0;
    }
    else {
      DAT_424c1b6c = FUN_42410459(local_18);
    }
    local_8 = local_8 & 0xffffff00;
  }
  piVar1 = (int *)FUN_42410697(DAT_424c1b6c,&local_18,param_2);
  local_8 = 2;
  FUN_42407350(param_1,piVar1);
  FUN_42403ad1((int *)&local_18);
  return param_1;
}


