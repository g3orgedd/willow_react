// Source: CLCSBarcodeField.dll @ 4143f4fc; FUN_4143f4fc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4143f4fc(undefined4 param_1,BSTR param_2)

{
  BSTR pOVar1;
  UINT UVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  BSTR extraout_ECX;
  BSTR pOVar6;
  BSTR pOVar7;
  undefined1 local_30 [8];
  BSTR local_28;
  BSTR local_24;
  BSTR local_20;
  BSTR local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_2;
  uStack_4 = 0x20;
  piVar4 = *(int **)param_2;
  if (piVar4 == (int *)0x0) {
    return 0x80004003;
  }
  param_2 = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(*piVar4 + 0x98))();
  UVar2 = SysStringLen(param_2);
  if ((UVar2 & 1) == 0) {
    local_14[0] = 0;
    uVar3 = (**(code **)(**(int **)pOVar1 + 0x100))();
    if (local_14[0] == 0) goto LAB_4143f605;
    pOVar7 = (BSTR)0xffffffff;
    pOVar6 = extraout_ECX;
    FUN_41402eab(&stack0xffffffb8,(int *)&param_2);
    FUN_4143ddd6(local_30,*(int *)(local_18 + 10),pOVar6,pOVar7);
    local_8._0_1_ = 1;
    piVar4 = FUN_41413d27(local_30,&local_18);
    FUN_41407c9d(&param_2,piVar4);
    SysFreeString(local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    SysFreeString(local_20);
    SysFreeString(local_24);
    SysFreeString(local_28);
  }
  else {
    FUN_41403041(local_14,L"0");
    local_8._0_1_ = 2;
    puVar5 = FUN_4140b914(&local_18,local_14,param_2);
    local_8._0_1_ = 3;
    FUN_414032cc(&param_2,(OLECHAR *)*puVar5);
    FUN_414031f1((int *)&local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_414031f1(local_14);
  }
  uVar3 = (**(code **)(**(int **)pOVar1 + 0x9c))();
LAB_4143f605:
  SysFreeString(param_2);
  return uVar3;
}


