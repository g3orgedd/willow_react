// Source: CiffMgr.dll @ 681081e6; FUN_681081e6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_681081e6(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x681081f2;
  CComQIPtr<>(local_14,param_3);
  local_8 = 0;
  (**(code **)(*local_14[0] + 0x30))(local_14[0],&local_18);
  iVar1 = *(int *)this;
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1 == local_18;
}


