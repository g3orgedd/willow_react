// Source: CiffHelper.dll @ 40813558; FUN_40813558

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_40813558(int *param_1,int *param_2)

{
  int *piVar1;
  UINT UVar2;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  int iVar3;
  code *pcVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  undefined1 local_3c [4];
  _union_2683 local_38;
  BSTR local_28;
  BSTR local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0;
  if (param_1 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
    goto LAB_408137ba;
  }
  local_1c = 0;
  iVar3 = (**(code **)(*param_1 + 0xa8))();
  if (iVar3 < 0) goto LAB_408137ba;
  if (local_1c == 0) {
    local_20 = 0;
    iVar3 = (**(code **)(*param_1 + 0x100))();
    pcVar4 = SysFreeString_exref;
    if ((-1 < iVar3) && (local_20 != 0)) {
      local_38.decVal.Hi32 = 0;
      local_38._8_4_ = (BSTR)0x0;
      local_38._12_4_ = (BSTR)0x0;
      pOVar6 = (BSTR)0xffffffff;
      local_8._0_1_ = 1;
      pOVar5 = extraout_ECX_00;
      FUN_40803baf(&stack0xffffffac,param_2);
      local_38._0_4_ = FUN_40812280(local_3c,0,pOVar5,pOVar6);
      piVar1 = FUN_40812209(local_3c,&local_28);
      FUN_4080be61(param_2,piVar1);
      SysFreeString(local_28);
      local_8 = (uint)local_8._1_3_ << 8;
      SysFreeString((BSTR)local_38._12_4_);
      SysFreeString((BSTR)local_38._8_4_);
      SysFreeString((BSTR)local_38.decVal.Hi32);
    }
    UVar2 = SysStringLen((BSTR)*param_2);
    if ((UVar2 & 1) != 0) {
      FUN_40802e40(local_14,L"0");
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_408040a6(local_14,(BSTR)*param_2);
      FUN_40803e5b(param_2,(int *)local_14);
LAB_408136cd:
      (*pcVar4)();
    }
  }
  else if (local_1c - 1U < 9) {
    local_14[0] = (int *)0x0;
    iVar3 = (**(code **)(*param_1 + 0x100))();
    if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
      local_38.decVal.Hi32 = 0;
      local_38._8_4_ = (BSTR)0x0;
      local_38._12_4_ = (BSTR)0x0;
      pOVar6 = (BSTR)0xffffffff;
      local_8 = CONCAT31(local_8._1_3_,3);
      pOVar5 = extraout_ECX;
      FUN_40803baf(&stack0xffffffac,param_2);
      local_38._0_4_ = FUN_40812280(local_3c,local_1c,pOVar5,pOVar6);
      piVar1 = FUN_40812209(local_3c,&local_24);
      FUN_4080be61(param_2,piVar1);
      pcVar4 = SysFreeString_exref;
      SysFreeString(local_24);
      SysFreeString((BSTR)local_38._12_4_);
      SysFreeString((BSTR)local_38._8_4_);
      goto LAB_408136cd;
    }
  }
  local_18 = (int *)0x0;
  local_8._0_1_ = 4;
  iVar3 = (**(code **)(*param_1 + 0x5c))();
  if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
    local_20 = 0;
    iVar3 = (**(code **)(*local_18 + 0x1c))();
    if ((-1 < iVar3) && (local_20 == 1)) {
      FUN_40802e76((uint *)&local_38);
      local_8._0_1_ = 5;
      iVar3 = (**(code **)(*local_18 + 0x24))(local_18);
      if ((-1 < iVar3) && (local_38.n2.vt == 9)) {
        local_14[0] = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        iVar3 = (*(code *)**(undefined4 **)local_38._8_4_)(local_38._8_4_);
        if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
          local_24 = (BSTR)0x0;
          iVar3 = (**(code **)(*local_14[0] + 0x28))();
          if ((-1 < iVar3) && (local_24 == (BSTR)0x0)) {
            iVar3 = (**(code **)(*local_14[0] + 0x5c))();
          }
        }
        local_8._0_1_ = 5;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))();
        }
      }
      VariantClear((VARIANTARG *)&local_38.n2);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
LAB_408137ba:
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  return iVar3;
}


