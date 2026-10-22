// Source: CiffMgr.dll @ 6811f7c5; FUN_6811f7c5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811f7c5(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  _union_2683 local_28;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x18;
  local_8 = 0x6811f7d1;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 0x28))(param_1,&local_18);
    if (local_18 == 4) {
      local_14[0] = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*param_2 + 0x44))((int *)*param_2,local_14);
      if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
        param_1 = (int *)0x0;
        local_8._0_1_ = 1;
        iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_SrcOffset_68160060,&param_1);
        if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
          FUN_68132710((uint *)&local_28,0,0x10);
          VariantInit((VARIANTARG *)&local_28.n2);
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*param_1 + 0x20))(param_1,&local_28);
          if (local_28.n2.vt == 8) {
            iVar2 = (**(code **)(*piVar1 + 0xb8))(piVar1,local_28._8_4_);
          }
          VariantClear((VARIANTARG *)&local_28.n2);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      if (iVar2 == 1) {
        iVar2 = 0;
      }
      local_8 = 0xffffffff;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    else {
      iVar2 = -0x7ff8ffa9;
    }
  }
  return iVar2;
}


