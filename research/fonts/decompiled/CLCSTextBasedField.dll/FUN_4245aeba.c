// Source: CLCSTextBasedField.dll @ 4245aeba; FUN_4245aeba

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4245aeba(BSTR param_1,void *param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  VARIANTARG local_48;
  _union_2683 local_38;
  BSTR local_28;
  int *local_24;
  OLECHAR *local_20;
  LPCWSTR local_1c;
  OLECHAR *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 1;
  if (param_3 == (int *)0x0) {
    uVar3 = 0x80004005;
    goto LAB_4245b047;
  }
  FUN_42403768(&local_1c,(int *)&param_1);
  FUN_42403802((uint *)&local_48);
  local_8._0_1_ = 3;
  (**(code **)(*param_3 + 0x474))(param_3,&local_48);
  CComQIPtr<>(&local_24,(undefined4 *)local_48.n1._8_4_);
  FUN_42403802((uint *)&local_38);
  local_8._0_1_ = 5;
  (**(code **)(*local_24 + 0x30))(local_24,local_1c,&local_38);
  uVar3 = 0;
  if (local_38.n2.vt == 0) {
LAB_4245afdf:
    FUN_4240391a(&local_18,local_1c);
    local_8._0_1_ = 9;
    FUN_42427fd5(&DAT_424bfaec,&local_18);
    piVar2 = FUN_424037d2(&local_28,local_18);
    FUN_4241115f(param_2,piVar2);
    SysFreeString(local_28);
    FUN_42403ad1((int *)&local_18);
  }
  else {
    CComQIPtr<>(&local_18,(undefined4 *)local_38._8_4_);
    local_14[0] = (BSTR)0x0;
    local_8._0_1_ = 7;
    (**(code **)(*(int *)local_18 + 0x9c))(local_18,local_14);
    bVar1 = FUN_42403bfa(local_14,L"TrueType");
    if (bVar1) {
LAB_4245afc9:
      SysFreeString(local_14[0]);
      local_8._0_1_ = 5;
      if (local_18 != (OLECHAR *)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      goto LAB_4245afdf;
    }
    bVar1 = FUN_42403bfa(local_14,L"ZFBF");
    if (bVar1) goto LAB_4245afc9;
    FUN_4242958a(&local_20);
    local_8._0_1_ = 8;
    piVar2 = FUN_424037d2(&local_28,local_20);
    FUN_4241115f(param_2,piVar2);
    SysFreeString(local_28);
    FUN_42403ad1((int *)&local_20);
    SysFreeString(local_14[0]);
    local_8._0_1_ = 5;
    if (local_18 != (OLECHAR *)0x0) {
      (**(code **)(*(int *)local_18 + 8))(local_18);
    }
  }
  VariantClear((VARIANTARG *)&local_38.n2);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  VariantClear(&local_48);
  SysFreeString(local_1c);
LAB_4245b047:
  SysFreeString(param_1);
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return uVar3;
}


