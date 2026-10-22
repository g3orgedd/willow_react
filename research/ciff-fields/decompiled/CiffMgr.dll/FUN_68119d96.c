// Source: CiffMgr.dll @ 68119d96; FUN_68119d96

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68119d96(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined *puVar3;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = FUN_68124126(param_1,0x6815f6d8,3,(int *)local_14,&local_18);
  puVar1 = param_2;
  if (iVar2 < 0) {
    local_18 = 0;
    *param_2 = 0;
    goto LAB_68119e43;
  }
  param_1 = (int *)0x0;
  local_8._0_1_ = 1;
  if (local_18 == 0) {
    iVar2 = 1;
    puVar3 = &DAT_6815f6f0;
LAB_68119e10:
    *param_2 = 0;
    iVar2 = FUN_68124126(local_14,(int)puVar3,iVar2,(int *)&param_1,&param_2);
    if (-1 < iVar2) {
      *puVar1 = param_2;
    }
  }
  else {
    if (local_18 == 1) {
      iVar2 = 0x1b;
      puVar3 = &DAT_6815f6f8;
      goto LAB_68119e10;
    }
    if (local_18 == 2) {
      iVar2 = 4;
      puVar3 = &DAT_6815f7d0;
      goto LAB_68119e10;
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
LAB_68119e43:
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return local_18;
}


