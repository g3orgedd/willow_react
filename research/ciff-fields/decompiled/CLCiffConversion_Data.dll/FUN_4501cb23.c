// Source: CLCiffConversion_Data.dll @ 4501cb23; FUN_4501cb23

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_4501cb23(undefined4 *param_1,uint param_2)

{
  int *piVar1;
  undefined4 *local_18;
  undefined4 local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *param_1 = PTR_DAT_4505101c;
  local_8 = 0;
  local_14 = 1;
  if (DAT_45054fe4 == (undefined4 *)0x0) {
    local_18 = (undefined4 *)FUN_450213f3(0x1c);
    local_8 = 1;
    if (local_18 == (undefined4 *)0x0) {
      DAT_45054fe4 = (undefined4 *)0x0;
    }
    else {
      DAT_45054fe4 = FUN_450087f3(local_18);
    }
    local_8 = local_8 & 0xffffff00;
  }
  piVar1 = (int *)FUN_45008b34(DAT_45054fe4,&local_18,param_2);
  local_8 = 2;
  FUN_45008a06(param_1,piVar1);
  FUN_45002256((int *)&local_18);
  return param_1;
}


