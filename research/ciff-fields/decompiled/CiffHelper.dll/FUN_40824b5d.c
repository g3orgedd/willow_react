// Source: CiffHelper.dll @ 40824b5d; FUN_40824b5d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_40824b5d(BSTR param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar4;
  LPCWSTR extraout_ECX;
  char cVar5;
  uint unaff_EBX;
  BSTR pOVar6;
  BSTR pOVar7;
  BSTR pOVar8;
  LPCWSTR pWVar9;
  VARIANTARG local_44;
  int local_34;
  OLECHAR *local_30;
  OLECHAR *local_2c;
  BSTR local_28;
  OLECHAR *local_24;
  BSTR local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x40824b69;
  FUN_40802e76((uint *)&local_44);
  local_8 = 0;
  (**(code **)(**(int **)param_1 + 0xcc))();
  CComQIPtr<>(local_14,(undefined4 *)local_44.n1._8_4_);
  local_8._0_1_ = 1;
  puVar3 = FUN_40828a2f(&local_34,0x64cc);
  local_8._0_1_ = 2;
  FUN_40802e40(&local_20,(OLECHAR *)*puVar3);
  local_8._0_1_ = 4;
  FUN_40803143(&local_34);
  local_18 = 0;
  pOVar6 = (BSTR)(unaff_EBX & 0xffffff00);
  local_28 = pOVar6;
  (**(code **)(*local_14[0] + 0x1c))();
  pOVar8 = (BSTR)0x1;
  pOVar7 = pOVar8;
  if (0 < local_18) {
    do {
      (**(code **)(*local_14[0] + 0x30))();
      CComQIPtr<>(&local_1c,(undefined4 *)local_44.n1._8_4_);
      param_1 = (BSTR)0x0;
      local_8._0_1_ = 6;
      (**(code **)(*local_1c + 0x1c))();
      bVar1 = FUN_40805005(param_1,(ushort *)local_20);
      pOVar6 = (BSTR)((uint)pOVar6 & 0xff);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        pOVar6 = pOVar8;
      }
      SysFreeString(param_1);
      local_8._0_1_ = 4;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))();
      }
      pOVar7 = (BSTR)((int)pOVar7 + 1);
    } while ((int)pOVar7 <= local_18);
    local_28 = pOVar6;
    if ((char)pOVar6 != '\0') {
      (**(code **)(*local_14[0] + 0x24))();
    }
  }
  cVar5 = (char)pOVar6;
  bVar1 = false;
  local_1c = (int *)(**(code **)(*local_14[0] + 0x1c))();
  if (0 < local_18) {
    do {
      (**(code **)(*local_14[0] + 0x30))();
      CComQIPtr<>(&local_24,(undefined4 *)local_44.n1._8_4_);
      param_1 = (BSTR)0x0;
      local_8._0_1_ = 8;
      local_1c = (int *)(**(code **)(*(int *)local_24 + 0x1c))(local_24);
      bVar2 = FUN_40805005(param_1,(ushort *)L"Table containing Index Fields");
      if (CONCAT31(extraout_var_00,bVar2) != 0) {
        bVar1 = true;
      }
      SysFreeString(param_1);
      local_8._0_1_ = 4;
      if (local_24 != (OLECHAR *)0x0) {
        (**(code **)(*(int *)local_24 + 8))();
      }
      pOVar8 = (BSTR)((int)pOVar8 + 1);
    } while ((int)pOVar8 <= local_18);
    cVar5 = (char)local_28;
    piVar4 = local_1c;
    if (bVar1) goto LAB_40824e32;
  }
  piVar4 = local_1c;
  if (cVar5 != '\0') {
    (**(code **)(*local_14[0] + 0x20))();
    CComQIPtr<>(&local_1c,(undefined4 *)local_44.n1._8_4_);
    local_8._0_1_ = 9;
    FUN_408030e3(&local_28,L"Table containing Index Fields");
    local_8._0_1_ = 10;
    FUN_40804d06(&param_1,&local_28);
    local_8._0_1_ = 0xc;
    FUN_40803143((int *)&local_28);
    pWVar9 = extraout_ECX;
    FUN_408030ad(&stack0xffffff84,(int *)&param_1);
    FUN_4080340c(&local_30,pWVar9);
    local_8._0_1_ = 0xd;
    FUN_408030ad(&stack0xffffff84,(int *)&param_1);
    FUN_4080334a(&local_2c,pWVar9);
    local_8._0_1_ = 0xe;
    FUN_408030ad(&stack0xffffff84,(int *)&param_1);
    FUN_408033ab(&local_24,pWVar9);
    piVar4 = local_1c;
    local_8._0_1_ = 0xf;
    FUN_40802e40(&local_28,local_30);
    local_8._0_1_ = 0x10;
    (**(code **)(*piVar4 + 0x28))(piVar4);
    local_8._0_1_ = 0xf;
    SysFreeString(local_28);
    piVar4 = local_1c;
    puVar3 = FUN_40802e40(&local_28,local_2c);
    local_8._0_1_ = 0x11;
    (**(code **)(*piVar4 + 0x30))(piVar4,*puVar3);
    local_8._0_1_ = 0xf;
    SysFreeString(local_28);
    piVar4 = local_1c;
    puVar3 = FUN_40802e40(&local_28,local_24);
    local_8._0_1_ = 0x12;
    piVar4 = (int *)(**(code **)(*piVar4 + 0x38))(piVar4,*puVar3);
    SysFreeString(local_28);
    FUN_40803143((int *)&local_24);
    FUN_40803143((int *)&local_2c);
    FUN_40803143((int *)&local_30);
    FUN_40803143((int *)&param_1);
    local_8._0_1_ = 4;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
  }
LAB_40824e32:
  SysFreeString(local_20);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  VariantClear(&local_44);
  return piVar4;
}


