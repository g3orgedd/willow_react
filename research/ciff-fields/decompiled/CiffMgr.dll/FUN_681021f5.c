// Source: CiffMgr.dll @ 681021f5; FUN_681021f5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl
FUN_681021f5(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(*(int *)*param_1 + 0xd4))((int *)*param_1,param_3,local_14);
  if (((-1 < iVar1) && (local_14[0] != (int *)0x0)) &&
     (iVar1 = (**(code **)(*local_14[0] + 0x24))
                        (local_14[0],*param_4,param_4[1],param_4[2],param_4[3]), -1 < iVar1)) {
    iVar1 = (**(code **)(*(int *)*param_2 + 0x20))((int *)*param_2,local_14[0],0);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1;
}


