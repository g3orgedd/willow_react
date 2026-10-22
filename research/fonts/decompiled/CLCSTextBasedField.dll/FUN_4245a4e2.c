// Source: CLCSTextBasedField.dll @ 4245a4e2; FUN_4245a4e2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4245a4e2(void *this,void *param_1,int *param_2,void **param_3)

{
  BSTR pOVar1;
  bool bVar2;
  int *piVar3;
  UINT UVar4;
  BSTR extraout_ECX;
  BSTR pOVar5;
  undefined4 uVar6;
  void **ppvVar7;
  VARIANTARG local_48;
  _union_2683 local_38;
  BSTR local_28;
  int *local_24;
  OLECHAR *local_20;
  BSTR local_1c;
  BSTR local_18;
  LPCWSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8._1_3_ = 0;
  if ((param_2 == (int *)0x0) || (param_3 == (void **)0x0)) {
    uVar6 = 0x80004005;
    goto LAB_4245a715;
  }
  local_14[0] = (LPCWSTR)0x0;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  (**(code **)(*param_2 + 0xa8))();
  (**(code **)(*param_2 + 0x124))(param_2,(int *)((int)this + 0x40));
  if (*(int *)((int)this + 0x40) == 2) {
LAB_4245a6f5:
    FUN_42403b34(param_1,(int *)local_14);
  }
  else {
    local_28 = (BSTR)&stack0xffffffa4;
    pOVar5 = (BSTR)&stack0xffffffa4;
    ppvVar7 = param_3;
    pOVar1 = (BSTR)&stack0xffffffa4;
    if (param_3 != (void **)0x0) {
      (**(code **)((int)*param_3 + 4))();
      pOVar5 = extraout_ECX;
      pOVar1 = local_28;
    }
    local_28 = pOVar1;
    local_8._0_1_ = 3;
    FUN_42403768(&stack0xffffffa0,(int *)local_14);
    local_8._0_1_ = 2;
    bVar2 = FUN_4245a73e(pOVar5,ppvVar7);
    if (bVar2) goto LAB_4245a6f5;
    FUN_42403802((uint *)&local_48);
    local_8._0_1_ = 4;
    (**(code **)((int)*param_3 + 0x474))();
    CComQIPtr<>(&local_24,(undefined4 *)local_48.n1._8_4_);
    FUN_42403802((uint *)&local_38);
    local_8._0_1_ = 6;
    (**(code **)(*local_24 + 0x30))(local_24,local_14[0],&local_38);
    if (local_38.n2.vt == 0) {
LAB_4245a690:
      FUN_4240391a(&local_20,local_14[0]);
      local_8._0_1_ = 0xb;
      FUN_42427fd5(&DAT_424bfaec,&local_20);
      piVar3 = FUN_424037d2(&local_28,local_20);
      FUN_4241115f(param_1,piVar3);
      SysFreeString(local_28);
      FUN_42403ad1((int *)&local_20);
    }
    else {
      CComQIPtr<>(&local_20,(undefined4 *)local_38._8_4_);
      local_1c = (BSTR)0x0;
      local_8._0_1_ = 8;
      (**(code **)(*(int *)local_20 + 0x9c))();
      bVar2 = FUN_42403bfa(&local_1c,L"TrueType");
      if (bVar2) {
        local_18 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,10);
        (**(code **)(*(int *)local_20 + 0xac))();
        UVar4 = SysStringLen(local_18);
        if (UVar4 != 0) {
          FUN_42403b34(local_14,(int *)&local_18);
        }
        SysFreeString(local_18);
        SysFreeString(local_1c);
        local_8._0_1_ = 6;
        if (local_20 != (OLECHAR *)0x0) {
          (**(code **)(*(int *)local_20 + 8))();
        }
        goto LAB_4245a690;
      }
      FUN_4242958a(&local_18);
      local_8._0_1_ = 9;
      piVar3 = FUN_424037d2(&local_28,local_18);
      FUN_4241115f(param_1,piVar3);
      SysFreeString(local_28);
      FUN_42403ad1((int *)&local_18);
      SysFreeString(local_1c);
      local_8._0_1_ = 6;
      if (local_20 != (OLECHAR *)0x0) {
        (**(code **)(*(int *)local_20 + 8))();
      }
    }
    VariantClear((VARIANTARG *)&local_38.n2);
    local_8._0_1_ = 4;
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))();
    }
    VariantClear(&local_48);
  }
  uVar6 = 0;
  SysFreeString(local_14[0]);
LAB_4245a715:
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_3 != (void **)0x0) {
    (**(code **)((int)*param_3 + 8))();
  }
  return uVar6;
}


