// Source: CiffMgr.dll @ 68102315; FUN_68102315

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl
FUN_68102315(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,void *param_5)

{
  int iVar1;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (int *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  iVar1 = (**(code **)(*param_1 + 0xbc))(param_1,param_3,local_14);
  if ((-1 < iVar1) && (local_14[0] != (int *)0x0)) {
    local_18 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar1 = (**(code **)(*param_1 + 0xcc))(param_1,param_4,&local_18);
    if ((-1 < iVar1) &&
       ((local_18 != (int *)0x0 &&
        (iVar1 = (**(code **)(*local_14[0] + 0x54))(local_14[0],local_18,0), -1 < iVar1)))) {
      iVar1 = (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,local_14[0],0);
    }
    FUN_68102161(param_5,(int *)local_14);
    local_8._0_1_ = 1;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar1;
}


