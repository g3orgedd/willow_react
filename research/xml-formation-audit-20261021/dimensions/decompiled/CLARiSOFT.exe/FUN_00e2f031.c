// Source: CLARiSOFT.exe @ 00e2f031; FUN_00e2f031

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_00e2f031(void *this,BSTR param_1)

{
  BSTR pOVar1;
  char cVar2;
  int iVar3;
  HRESULT HVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  VARIANTARG local_58;
  VARIANTARG local_48;
  void *local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0x48;
  local_8 = 0xe2f03d;
  local_34 = this;
  iVar3 = FUN_00e61ea6((int)param_1);
  if (iVar3 == 1) {
    CComQIPtr<>(&local_20,*(undefined4 **)(pOVar1 + 2));
    local_8 = 0;
    FUN_00e03b51((uint *)&local_58);
    local_8._0_1_ = 1;
    (**(code **)(**(int **)((int)this + 0x160) + 0x474))(*(int **)((int)this + 0x160),&local_58);
    CComQIPtr<>(&local_1c,(undefined4 *)local_58.n1._8_4_);
    local_8._0_1_ = 2;
    (**(code **)(*local_1c + 0x24))(local_1c,&local_28);
    local_18 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*local_20 + 0xa8))(local_20,&local_18);
    (**(code **)(*local_20 + 0x88))(local_20,&local_2c);
    iVar3 = 0;
    if (0 < local_28) {
      do {
        FUN_00e03b51((uint *)&local_48);
        iVar3 = iVar3 + 1;
        local_8._0_1_ = 4;
        (**(code **)(*local_1c + 0x20))(local_1c,iVar3,&local_48);
        CComQIPtr<>(local_14,(undefined4 *)local_48.n1._8_4_);
        local_8._0_1_ = 5;
        (**(code **)(*local_14[0] + 0x3c))(local_14[0],&local_30);
        FUN_00eae6d1(&local_24);
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,7);
        (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1);
        HVar4 = VarBstrCmp(param_1,local_18,0x400,0);
        if (HVar4 == 1) {
          piVar6 = *(int **)((int)local_34 + 0x15c);
          iVar7 = local_30;
          iVar8 = local_2c;
          if (piVar6 != (int *)0x0) {
            (**(code **)(*piVar6 + 4))(piVar6);
          }
          cVar2 = FUN_00eaebe0(piVar6,iVar7,iVar8);
          if (cVar2 != '\0') {
            SysFreeString(param_1);
            local_8._0_1_ = 5;
            FUN_00eae7b2(&local_24);
            local_8._0_1_ = 4;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            VariantClear(&local_48);
            SysFreeString(local_18);
            local_8 = CONCAT31(local_8._1_3_,1);
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
            VariantClear(&local_58);
            local_8 = 0xffffffff;
            iVar3 = 0;
            if (local_20 != (int *)0x0) {
              iVar3 = (**(code **)(*local_20 + 8))(local_20);
            }
            goto LAB_00e2f051;
          }
        }
        SysFreeString(param_1);
        local_8._0_1_ = 5;
        FUN_00eae7b2(&local_24);
        local_8 = CONCAT31(local_8._1_3_,4);
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        VariantClear(&local_48);
      } while (iVar3 < local_28);
    }
    SysFreeString(local_18);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    VariantClear(&local_58);
    local_8 = 0xffffffff;
    uVar5 = 0;
    if (local_20 != (int *)0x0) {
      uVar5 = (**(code **)(*local_20 + 8))(local_20);
    }
    uVar5 = uVar5 & 0xffffff00;
  }
  else {
LAB_00e2f051:
    uVar5 = CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  return uVar5;
}


