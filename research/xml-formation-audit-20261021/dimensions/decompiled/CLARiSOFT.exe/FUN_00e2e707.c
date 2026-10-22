// Source: CLARiSOFT.exe @ 00e2e707; FUN_00e2e707

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00e2e707(void *this,BSTR param_1)

{
  BSTR pOVar1;
  bool bVar2;
  int iVar3;
  HRESULT HVar4;
  uint uVar5;
  code *pcVar6;
  int *piVar7;
  undefined4 uVar8;
  VARIANTARG local_58;
  VARIANTARG local_48;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  int local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0x48;
  local_8 = 0xe2e713;
  iVar3 = FUN_00e61ea6((int)param_1);
  if (iVar3 == 1) {
    CComQIPtr<>(&local_28,*(undefined4 **)(pOVar1 + 2));
    local_8 = 0;
    (**(code **)(**(int **)((int)this + 0x160) + 0x184))(*(int **)((int)this + 0x160),&local_30);
    if (local_30 == 0) {
      FUN_00e03b51((uint *)&local_58);
      local_8._0_1_ = 1;
      (**(code **)(**(int **)((int)this + 0x160) + 0x474))(*(int **)((int)this + 0x160),&local_58);
      CComQIPtr<>(&local_1c,(undefined4 *)local_58.n1._8_4_);
      local_8._0_1_ = 2;
      (**(code **)(*local_1c + 0x24))(local_1c,&local_2c);
      local_18 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,3);
      (**(code **)(*local_28 + 0xa8))(local_28,&local_18);
      local_20 = 0;
      pcVar6 = VariantClear_exref;
      if (0 < local_2c) {
        do {
          FUN_00e03b51((uint *)&local_48);
          local_20 = local_20 + 1;
          local_8._0_1_ = 4;
          (**(code **)(*local_1c + 0x20))(local_1c,local_20,&local_48);
          CComQIPtr<>(local_14,(undefined4 *)local_48.n1._8_4_);
          param_1 = (BSTR)0x0;
          local_8._0_1_ = 6;
          (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1);
          (**(code **)(*local_14[0] + 0x3c))(local_14[0],&local_34);
          FUN_00eae6d1(&local_24);
          local_8 = CONCAT31(local_8._1_3_,7);
          HVar4 = VarBstrCmp(param_1,local_18,0x400,0);
          pcVar6 = VariantClear_exref;
          if (HVar4 == 1) {
            piVar7 = *(int **)((int)this + 0x15c);
            uVar8 = local_34;
            if (piVar7 != (int *)0x0) {
              (**(code **)(*piVar7 + 4))(piVar7);
            }
            bVar2 = FUN_00eaed3b(piVar7,uVar8);
            if (bVar2) {
              local_8._0_1_ = 6;
              FUN_00eae7b2(&local_24);
              SysFreeString(param_1);
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
              goto LAB_00e2e905;
            }
          }
          local_8._0_1_ = 6;
          FUN_00eae7b2(&local_24);
          SysFreeString(param_1);
          local_8 = CONCAT31(local_8._1_3_,4);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          VariantClear(&local_48);
        } while (local_20 < local_2c);
      }
      SysFreeString(local_18);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      (*pcVar6)(&local_58);
      local_8 = 0xffffffff;
      uVar5 = 0;
      if (local_28 != (int *)0x0) {
        uVar5 = (**(code **)(*local_28 + 8))(local_28);
      }
      return uVar5 & 0xffffff00;
    }
LAB_00e2e905:
    local_8 = 0xffffffff;
    iVar3 = 0;
    if (local_28 != (int *)0x0) {
      iVar3 = (**(code **)(*local_28 + 8))(local_28);
    }
  }
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


