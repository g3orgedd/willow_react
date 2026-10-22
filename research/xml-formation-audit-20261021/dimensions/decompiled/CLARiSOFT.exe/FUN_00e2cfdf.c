// Source: CLARiSOFT.exe @ 00e2cfdf; FUN_00e2cfdf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e2cfdf(void *this,int *param_1,BSTR param_2,BSTR param_3)

{
  undefined4 uVar1;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  int *piVar2;
  BSTR pOVar3;
  BSTR pOVar4;
  _union_2683 local_38;
  undefined1 *local_28;
  undefined1 *local_24;
  undefined1 local_20 [8];
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0;
  FUN_00e03b51((uint *)&local_38);
  local_8._0_1_ = 3;
  (**(code **)(*param_1 + 0x28))();
  if (local_38.n2.vt != 0) {
    CComQIPtr<>(local_14,(undefined4 *)local_38._8_4_);
    local_8._0_1_ = 4;
    (**(code **)(*local_14[0] + 0x24))();
    (**(code **)(*local_14[0] + 0x4c))(local_14[0],local_20);
    local_18 = (BSTR)0x0;
    local_8._0_1_ = 5;
    (**(code **)(*local_14[0] + 0xbc))(local_14[0],&local_18);
    local_24 = &stack0xffffffa8;
    pOVar4 = extraout_ECX;
    FUN_00e03ab8(&stack0xffffffa8,(int *)&param_3);
    local_8._0_1_ = 6;
    pOVar3 = extraout_ECX_00;
    FUN_00e03ab8(&stack0xffffffa4,(int *)&param_2);
    local_8._0_1_ = 5;
    uVar1 = FUN_00e29d43(this,pOVar3,pOVar4);
    if ((char)uVar1 == '\0') {
      (**(code **)(*param_1 + 0x24))();
      local_28 = &stack0xffffffa8;
      pOVar4 = extraout_ECX_01;
      FUN_00e03b21(&stack0xffffffa8,L"");
      local_8 = CONCAT31(local_8._1_3_,7);
      pOVar3 = extraout_ECX_02;
      FUN_00e03ab8(&stack0xffffffa4,(int *)&local_18);
      piVar2 = param_1;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 4))(param_1);
      }
      local_8._0_1_ = 5;
      FUN_00e2cfdf(this,piVar2,pOVar3,pOVar4);
    }
    SysFreeString(local_18);
    local_8._0_1_ = 3;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))();
    }
  }
  VariantClear((VARIANTARG *)&local_38.n2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  SysFreeString(param_2);
  SysFreeString(param_3);
  return;
}


