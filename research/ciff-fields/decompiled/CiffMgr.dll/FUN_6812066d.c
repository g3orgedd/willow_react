// Source: CiffMgr.dll @ 6812066d; FUN_6812066d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6812066d(void *this,int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  _union_2683 local_30;
  void *local_20;
  BSTR local_1c;
  int *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x68120679;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *(undefined4 *)((int)this + 4) = 1;
    iVar2 = 0;
    local_20 = this;
    CComQIPtr<>(&param_1,param_1);
    piVar1 = param_2;
    local_8 = 0;
    if (param_1 != (int *)0x0) {
      local_1c = (BSTR)0x0;
      iVar2 = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&local_1c);
      if (-1 < iVar2) {
        local_18 = (int *)0x0;
        local_8._0_1_ = 1;
        iVar2 = (**(code **)(*(int *)*piVar1 + 0x44))((int *)*piVar1,&local_18);
        if ((-1 < iVar2) && (local_18 != (int *)0x0)) {
          param_2 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_SrcPrice_681600c8,&param_2);
          if ((-1 < iVar2) && (param_2 != (int *)0x0)) {
            FUN_68132710((uint *)&local_30,0,0x10);
            VariantInit((VARIANTARG *)&local_30.n2);
            local_8._0_1_ = 3;
            (**(code **)(*param_2 + 0x20))(param_2,&local_30);
            if (((local_30.n2.vt == 8) && ((short *)local_30._8_4_ != (short *)0x0)) &&
               (*(short *)local_30._8_4_ != 0)) {
              (**(code **)(*param_1 + 0x144))(param_1,local_30._8_4_);
            }
            VariantClear((VARIANTARG *)&local_30.n2);
          }
          local_8._0_1_ = 1;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
        }
        param_2 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,4);
        iVar2 = (**(code **)(*(int *)*piVar1 + 0x94))
                          ((int *)*piVar1,PTR_u_HigherFmt_6815feec,&param_2);
        if ((iVar2 == 0) && (param_2 != (int *)0x0)) {
          local_14[0] = (BSTR)0x0;
          iVar2 = (**(code **)(*param_2 + 0x68))(param_2,local_14);
          if (-1 < iVar2) {
            (**(code **)(*param_1 + 0x14c))(param_1,local_14[0]);
          }
          SysFreeString(local_14[0]);
        }
        local_8._0_1_ = 1;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        param_2 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,5);
        iVar2 = (**(code **)(*(int *)*piVar1 + 0x94))
                          ((int *)*piVar1,PTR_u_LowerFmt_6815fef0,&param_2);
        if ((iVar2 == 0) && (param_2 != (int *)0x0)) {
          local_14[0] = (BSTR)0x0;
          iVar2 = (**(code **)(*param_2 + 0x68))(param_2,local_14);
          if (-1 < iVar2) {
            (**(code **)(*param_1 + 0x154))(param_1,local_14[0]);
          }
          SysFreeString(local_14[0]);
        }
        local_8._0_1_ = 1;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        param_2 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        iVar2 = (**(code **)(*(int *)*piVar1 + 0x94))
                          ((int *)*piVar1,PTR_u_SwitchVal_6815fef4,&param_2);
        if ((iVar2 == 0) && (param_2 != (int *)0x0)) {
          local_14[0] = (BSTR)0x0;
          iVar2 = (**(code **)(*param_2 + 0x68))(param_2,local_14);
          piVar1 = param_1;
          if (-1 < iVar2) {
            iVar2 = *param_1;
            iVar3 = FUN_6812f116((ushort *)local_14[0]);
            iVar2 = (**(code **)(iVar2 + 0x15c))(piVar1,iVar3);
          }
          SysFreeString(local_14[0]);
        }
        local_8._0_1_ = 1;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (iVar2 == 1) {
          iVar2 = 0;
        }
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
      }
      SysFreeString(local_1c);
    }
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return iVar2;
}


