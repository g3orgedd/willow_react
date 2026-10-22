// Source: CiffMgr.dll @ 681155c3; FUN_681155c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_681155c3(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x681155cf;
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar2 = FUN_68115b3d(local_14);
    piVar1 = local_14[0];
    if (-1 < iVar2) {
      local_18 = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
      }
      local_8 = 0;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
      }
      local_8._0_1_ = 1;
      FUN_68116e65((void *)(param_1 + 4),local_14);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      iVar2 = FUN_681157f4(&local_18,param_2);
      local_8 = 0xffffffff;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
  }
  return iVar2;
}


