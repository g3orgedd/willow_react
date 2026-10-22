// Source: CLARiSOFT.exe @ 00e2ca77; FUN_00e2ca77

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_00e2ca77(void *this,BSTR param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  HRESULT HVar5;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  int iVar6;
  BSTR pOVar7;
  BSTR pOVar8;
  BSTR pOVar9;
  _union_2683 local_74;
  _union_2683 local_64;
  _union_2683 local_54;
  BSTR local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  BSTR local_2c;
  BSTR local_28;
  int *local_24;
  int *local_20;
  BSTR local_1c;
  BSTR local_18;
  int local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 100;
  local_8 = 0xe2ca83;
  iVar6 = 0;
  piVar2 = (int *)FUN_00e77808((void *)((int)this + 4),0);
  pOVar9 = param_1;
  if (*piVar2 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = *piVar2 + -100;
  }
  local_18 = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(**(int **)(param_1 + 2) + 0x68))();
  bVar1 = FUN_00e03edc(&local_18,L"OffsetDateText");
  if ((bVar1) || (bVar1 = FUN_00e03edc(&local_18,L"DateText"), bVar1)) {
    param_1 = (BSTR)0x0;
    local_2c = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(**(int **)(pOVar9 + 2) + 0x5c))();
    FUN_00e03b51((uint *)&local_74);
    local_8._0_1_ = 3;
    (**(code **)(*(int *)local_2c + 0x24))(local_2c,1,&local_74);
    if (local_74.n2.vt != 0) {
      CComQIPtr<>(&local_28,(undefined4 *)local_74._8_4_);
      local_30 = (int *)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*(int *)local_28 + 0x28))();
      if (local_30 == (int *)0x4) {
        (**(code **)(*(int *)local_28 + 0xb4))();
        FUN_00e03b51((uint *)&local_64);
        local_8._0_1_ = 5;
        (**(code **)(**(int **)((int)this + 0x19c) + 100))(*(int **)((int)this + 0x19c),&local_64);
        if (local_64.n2.vt != 0) {
          CComQIPtr<>(&local_20,(undefined4 *)local_64._8_4_);
          FUN_00e03b51((uint *)&local_54);
          local_8._0_1_ = 7;
          (**(code **)(*local_20 + 0x28))(local_20);
          if (local_54.n2.vt != 0) {
            CComQIPtr<>(&local_24,(undefined4 *)local_54._8_4_);
            local_8._0_1_ = 8;
            (**(code **)(*local_24 + 0x24))();
            (**(code **)(*local_24 + 0x4c))(local_24,&local_34);
            if ((local_38 == 0) || (local_34 != (int *)0x2)) {
              local_1c = (BSTR)0x0;
              local_8._0_1_ = 9;
              (**(code **)(**(int **)(pOVar9 + 2) + 0x1c))(*(int **)(pOVar9 + 2),&local_1c);
              local_44 = (BSTR)&stack0xffffff70;
              pOVar8 = extraout_ECX;
              FUN_00e03ab8(&stack0xffffff70,(int *)&local_1c);
              local_8._0_1_ = 10;
              pOVar7 = extraout_ECX_00;
              FUN_00e03ab8(&stack0xffffff6c,(int *)&param_1);
              local_8._0_1_ = 9;
              uVar4 = FUN_00e29d43(this,pOVar7,pOVar8);
              if ((char)uVar4 == '\0') {
                local_44 = (BSTR)&stack0xffffff70;
                pOVar8 = extraout_ECX_01;
                FUN_00e03ab8(&stack0xffffff70,(int *)&local_1c);
                local_8 = CONCAT31(local_8._1_3_,0xb);
                pOVar7 = extraout_ECX_02;
                FUN_00e03ab8(&stack0xffffff6c,(int *)&param_1);
                piVar2 = local_20;
                if (local_20 != (int *)0x0) {
                  (**(code **)(*local_20 + 4))(local_20);
                }
                local_8._0_1_ = 9;
                FUN_00e2cfdf(this,piVar2,pOVar7,pOVar8);
              }
              SysFreeString(local_1c);
            }
            else {
              (**(code **)(*local_20 + 0x24))(local_20,param_1);
            }
            local_8._0_1_ = 7;
            if (local_24 != (int *)0x0) {
              (**(code **)(*local_24 + 8))();
            }
          }
          VariantClear((VARIANTARG *)&local_54.n2);
          local_8._0_1_ = 5;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))();
          }
        }
        VariantClear((VARIANTARG *)&local_64.n2);
      }
      local_8._0_1_ = 3;
      if (local_28 != (BSTR)0x0) {
        (**(code **)(*(int *)local_28 + 8))();
      }
    }
    VariantClear((VARIANTARG *)&local_74.n2);
    local_8._0_1_ = 1;
    if (local_2c != (BSTR)0x0) {
      (**(code **)(*(int *)local_2c + 8))();
    }
    local_8 = (uint)local_8._1_3_ << 8;
    SysFreeString(param_1);
  }
  bVar1 = FUN_00e03edc(&local_18,L"Price");
  if (bVar1) {
    param_1 = (BSTR)&stack0xffffff70;
    piVar2 = *(int **)((int)this + 0x19c);
    pOVar7 = (BSTR)&stack0xffffff70;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
      pOVar7 = param_1;
    }
    param_1 = pOVar7;
    local_8._0_1_ = 0xc;
    iVar3 = FUN_00e3e85d(local_14);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00e67954(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),pOVar9,piVar2);
  }
  uVar4 = FUN_00e61fec((int)pOVar9);
  if ((char)uVar4 != '\0') {
    param_1 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,0xd);
    (**(code **)(**(int **)(pOVar9 + 2) + 0x5c))();
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 0x1c))();
      local_24 = (int *)0x0;
      if (0 < local_38) {
        do {
          FUN_00e03b51((uint *)&local_64);
          local_8._0_1_ = 0xe;
          (**(code **)(*(int *)param_1 + 0x30))(param_1);
          CComQIPtr<>(&local_34,(undefined4 *)local_64._8_4_);
          local_8._0_1_ = 0xf;
          (**(code **)(*local_34 + 0x50))(local_34,&local_3c);
          if (local_3c == 5) {
            local_1c = (BSTR)0x0;
            local_8._0_1_ = 0x10;
            (**(code **)(**(int **)(pOVar9 + 2) + 0x5c))();
            if (local_1c != (BSTR)0x0) {
              FUN_00e03b51((uint *)&local_74);
              local_8._0_1_ = 0x11;
              (**(code **)(*(int *)local_1c + 0x30))(local_1c);
              if (local_74.n2.vt != 0) {
                CComQIPtr<>(&local_30,(undefined4 *)local_74._8_4_);
                if (local_30 != (int *)0x0) {
                  local_28 = (BSTR)0x0;
                  local_8._0_1_ = 0x13;
                  (**(code **)(*local_30 + 0xe4))();
                  iVar3 = FUN_00e3e85d(local_14);
                  FUN_00e68567(*(int *)(*(int *)((int)this + 400) + iVar3 * 4));
                  iVar3 = FUN_00e3e85d(local_14);
                  FUN_00e68547(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),&local_20);
                  while( true ) {
                    iVar3 = FUN_00e3e85d(local_14);
                    piVar2 = (int *)FUN_00e68558(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),
                                                 &local_40);
                    if (local_20 == (int *)*piVar2) break;
                    local_44 = (BSTR)local_20[2];
                    FUN_00e616d4(local_44,&local_2c);
                    local_8._0_1_ = 0x14;
                    HVar5 = VarBstrCmp(local_2c,local_28,0x400,0);
                    if (HVar5 == 1) {
                      iVar3 = FUN_00e3e85d(local_14);
                      FUN_00e6616a(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),local_44);
                      SysFreeString(local_2c);
                      break;
                    }
                    local_8._0_1_ = 0x13;
                    SysFreeString(local_2c);
                    local_20 = (int *)*local_20;
                  }
                  SysFreeString(local_28);
                }
                local_8._0_1_ = 0x11;
                if (local_30 != (int *)0x0) {
                  (**(code **)(*local_30 + 8))();
                }
              }
              VariantClear((VARIANTARG *)&local_74.n2);
            }
            local_8._0_1_ = 0xf;
            if (local_1c != (BSTR)0x0) {
              (**(code **)(*(int *)local_1c + 8))();
            }
          }
          local_8 = CONCAT31(local_8._1_3_,0xe);
          if (local_34 != (int *)0x0) {
            (**(code **)(*local_34 + 8))();
          }
          VariantClear((VARIANTARG *)&local_64.n2);
          local_24 = (int *)((int)local_24 + 1);
        } while ((int)local_24 < local_38);
      }
    }
    local_8 = local_8 & 0xffffff00;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))();
    }
  }
  iVar3 = FUN_00e3e85d(local_14);
  param_1 = (BSTR)FUN_00e6616a(*(void **)(*(int *)((int)this + 400) + iVar3 * 4),pOVar9);
  piVar2 = *(int **)((int)this + 400);
  if (piVar2 != *(int **)((int)this + 0x194)) {
    do {
      iVar3 = FUN_00e68567(*piVar2);
      piVar2 = piVar2 + 1;
      iVar6 = iVar6 + iVar3;
    } while (piVar2 != *(int **)((int)this + 0x194));
    if (iVar6 != 0) {
      pOVar9 = *(BSTR *)((int)this + 0x160);
      if (pOVar9 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar9 + 4))();
      }
      pOVar7 = *(BSTR *)((int)this + 0x19c);
      if (pOVar7 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar7 + 4))(pOVar7);
      }
      uVar4 = FUN_00eb1fd0((void *)((int)this + 0x1ac),pOVar7,pOVar9);
      *(undefined4 *)((int)this + 0x28) = uVar4;
    }
  }
  FUN_00e2b99e((int)this);
  SysFreeString(local_18);
  return (int)param_1;
}


