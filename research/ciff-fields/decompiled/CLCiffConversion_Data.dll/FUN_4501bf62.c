// Source: CLCiffConversion_Data.dll @ 4501bf62; FUN_4501bf62

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_4501bf62(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 8;
  local_8 = 0;
  param_1[1] = 0;
  *param_1 = 0;
  if (param_2 != (int *)0x0) {
    param_1 = (undefined4 *)0x0;
    (**(code **)(*param_2 + 0xc4))(param_2,&param_1);
    if (param_1 == (undefined4 *)0x0) {
      local_14 = 0;
      local_18 = 0;
      iVar2 = FUN_45003392();
      uVar3 = 0;
      uVar4 = 0;
      if (iVar2 != 0) {
        FUN_45003ecd((LPCWSTR)&local_18);
        uVar3 = local_18;
        uVar4 = local_14;
      }
      *puVar1 = uVar3;
      puVar1[1] = uVar4;
    }
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return puVar1;
}


