// Source: CLCSTextBasedField.dll @ 4243b625; FUN_4243b625

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_4243b625(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 8;
  local_8 = 0x4243b631;
  local_14[0] = 0;
  (**(code **)(*(int *)*param_1 + 0xb0))((int *)*param_1,local_14);
  param_1 = (undefined4 *)0x1;
  CComQIPtr<>(&local_18,(undefined4 *)*puVar1);
  local_8 = 0;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 0x168))(local_18,&param_1);
  }
  iVar2 = FUN_4243b69c(local_14[0],(int)param_1,param_2);
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return iVar2;
}


