// Source: CiffHelper.dll @ 40828a2f; FUN_40828a2f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_40828a2f(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *local_18;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = PTR_DAT_40862014;
  local_8 = 0;
  local_14 = 1;
  if (DAT_40866668 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)FUN_4082d9f3(0x1c);
    local_8 = 1;
    if (local_18 == (undefined4 *)0x0) {
      DAT_40866668 = (undefined4 *)0x0;
    }
    else {
      DAT_40866668 = FUN_408086ca(local_18);
    }
    local_8 = local_8 & 0xffffff00;
  }
  piVar1 = (int *)FUN_4080897c(DAT_40866668,&local_18,param_2);
  local_8 = 2;
  FUN_4080316d(param_1,piVar1);
  FUN_40803143((int *)&local_18);
  return param_1;
}


