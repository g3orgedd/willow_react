// Source: CLARiSOFT.exe @ 00e2b55e; FUN_00e2b55e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_00e2b55e(void *this,BSTR param_1,BSTR param_2)

{
  int *piVar1;
  bool bVar2;
  HRESULT HVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_EAX;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR pOVar6;
  int *piVar7;
  int *piVar8;
  BSTR pOVar9;
  VARIANTARG local_88;
  _union_2683 local_78;
  _union_2683 local_68;
  undefined1 *local_54;
  int *local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  BSTR local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  void *local_1c;
  BSTR local_18;
  BSTR local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_48 = 1;
  local_8 = 1;
  local_1c = this;
  (**(code **)(**(int **)((int)this + 0x19c) + 0x1c))();
  local_38 = 0;
  if (local_44 < 1) {
LAB_00e2b8c9:
    local_48 = local_48 & 0xffffff00;
LAB_00e2b8cd:
    SysFreeString(param_1);
    SysFreeString(param_2);
    return CONCAT31((int3)((uint)extraout_EAX >> 8),(undefined1)local_48);
  }
LAB_00e2b59c:
  FUN_00e03b51((uint *)&local_78);
  local_38 = local_38 + 1;
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 0x19c) + 0x24))();
  if (local_78.n2.vt != 0) {
    CComQIPtr<>(&local_30,(undefined4 *)local_78._8_4_);
    local_8._0_1_ = 3;
    (**(code **)(*local_30 + 0x1c))();
    pOVar6 = (BSTR)0x0;
    if (0 < local_3c) {
      do {
        FUN_00e03b51((uint *)&local_68);
        local_8._0_1_ = 4;
        local_2c = (BSTR)((int)pOVar6 + 1);
        (**(code **)(*local_30 + 0x24))();
        pOVar6 = (BSTR)((int)pOVar6 + 1);
        if (local_68.n2.vt == 0) {
LAB_00e2b6ce:
          VariantClear((VARIANTARG *)&local_68.n2);
        }
        else {
          CComQIPtr<>(&local_24,(undefined4 *)local_68._8_4_);
          piVar1 = local_24;
          local_8._0_1_ = 6;
          local_50 = local_24;
          if (local_24 != (int *)0x0) {
            (**(code **)(*local_24 + 4))();
          }
          local_14 = (BSTR)0x0;
          local_8._0_1_ = 7;
          (**(code **)(*piVar1 + 0x1c))();
          HVar3 = VarBstrCmp(local_14,param_1,0x400,0);
          if (HVar3 != 1) {
            HVar3 = VarBstrCmp(local_14,param_2,0x400,0);
            if (HVar3 != 1) {
              SysFreeString(local_14);
              local_8._0_1_ = 5;
              (**(code **)(*piVar1 + 8))();
              local_8._0_1_ = 4;
              pOVar6 = local_2c;
              if (local_24 != (int *)0x0) {
                (**(code **)(*local_24 + 8))();
                pOVar6 = local_2c;
              }
              goto LAB_00e2b6ce;
            }
            local_2c = (BSTR)0x0;
            local_8._0_1_ = 8;
            (**(code **)(*piVar1 + 0x68))();
            bVar2 = FUN_00e03edc(&local_2c,L"MergeField");
            if (!bVar2) goto LAB_00e2b874;
            local_20 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,9);
            (**(code **)(*piVar1 + 0x5c))();
            if (local_20 == (int *)0x0) goto LAB_00e2b866;
            (**(code **)(*local_20 + 0x1c))();
            local_34 = 0;
            if (local_40 < 1) goto LAB_00e2b866;
            goto LAB_00e2b73e;
          }
          SysFreeString(local_14);
          local_8._0_1_ = 5;
          (**(code **)(*piVar1 + 8))();
          local_8._0_1_ = 4;
          if (local_24 != (int *)0x0) {
            (**(code **)(*local_24 + 8))();
          }
          VariantClear((VARIANTARG *)&local_68.n2);
          pOVar6 = local_2c;
        }
      } while ((int)pOVar6 < local_3c);
    }
    goto LAB_00e2b89f;
  }
  goto LAB_00e2b8b3;
LAB_00e2b73e:
  do {
    FUN_00e03b51((uint *)&local_88);
    local_8._0_1_ = 10;
    (**(code **)(*local_20 + 0x30))(local_20);
    CComQIPtr<>(&local_28,(undefined4 *)local_88.n1._8_4_);
    local_8._0_1_ = 0xb;
    (**(code **)(*local_28 + 0x50))(local_28,&local_4c);
    local_18 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,0xc);
    (**(code **)(*local_28 + 0xe4))(local_28,&local_18);
    HVar3 = VarBstrCmp(local_18,param_1,0x400,0);
    if (HVar3 == 1) {
LAB_00e2b8e2:
      SysFreeString(local_18);
      local_8._0_1_ = 10;
      if (local_28 != (int *)0x0) {
        (**(code **)(*local_28 + 8))();
      }
      VariantClear(&local_88);
      local_8._0_1_ = 8;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))();
      }
      SysFreeString(local_2c);
      SysFreeString(local_14);
      local_8._0_1_ = 5;
      (**(code **)(*piVar1 + 8))();
      local_8._0_1_ = 4;
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 8))();
      }
      VariantClear((VARIANTARG *)&local_68.n2);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))();
      }
      VariantClear((VARIANTARG *)&local_78.n2);
      goto LAB_00e2b8cd;
    }
    if (local_4c == 5) {
      pOVar9 = extraout_ECX;
      FUN_00e03ab8(&stack0xffffff4c,(int *)&local_18);
      pOVar6 = *(BSTR *)((int)local_1c + 0x19c);
      if (pOVar6 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar6 + 4))(pOVar6);
      }
      piVar8 = (int *)0x0;
      piVar7 = piVar1;
      (**(code **)(*piVar1 + 4))(piVar1);
      iVar4 = FUN_00eb4698(piVar7,piVar8,pOVar6,pOVar9);
      if (iVar4 != 2) {
        local_54 = &stack0xffffff4c;
        pOVar9 = extraout_ECX_00;
        FUN_00e03ab8(&stack0xffffff4c,(int *)&local_18);
        local_8._0_1_ = 0xd;
        pOVar6 = extraout_ECX_01;
        FUN_00e03ab8(&stack0xffffff48,(int *)&param_1);
        local_8 = CONCAT31(local_8._1_3_,0xc);
        uVar5 = FUN_00e2b55e(local_1c,pOVar6,pOVar9);
        if ((char)uVar5 == '\0') goto LAB_00e2b834;
      }
      goto LAB_00e2b8e2;
    }
LAB_00e2b834:
    SysFreeString(local_18);
    local_8 = CONCAT31(local_8._1_3_,10);
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))();
    }
    VariantClear(&local_88);
    local_34 = local_34 + 1;
  } while (local_34 < local_40);
LAB_00e2b866:
  local_8._0_1_ = 8;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
LAB_00e2b874:
  SysFreeString(local_2c);
  SysFreeString(local_14);
  local_8._0_1_ = 5;
  (**(code **)(*piVar1 + 8))();
  local_8._0_1_ = 4;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))();
  }
  VariantClear((VARIANTARG *)&local_68.n2);
LAB_00e2b89f:
  local_8._0_1_ = 2;
  this = local_1c;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))();
    this = local_1c;
  }
LAB_00e2b8b3:
  local_8 = CONCAT31(local_8._1_3_,1);
  VariantClear((VARIANTARG *)&local_78.n2);
  if (local_44 <= local_38) goto LAB_00e2b8c9;
  goto LAB_00e2b59c;
}


