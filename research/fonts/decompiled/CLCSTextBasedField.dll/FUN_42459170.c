// Source: CLCSTextBasedField.dll @ 42459170; FUN_42459170

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_42459170(void *this,BSTR param_1,undefined4 param_2,void *param_3,undefined4 param_4,
            char param_5,undefined4 *param_6,int param_7,int param_8,int *param_9)

{
  BSTR pOVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined1 *puVar4;
  bool bVar5;
  char cVar6;
  CComBSTR *pCVar7;
  CComBSTR *this_00;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *piVar8;
  int iVar9;
  code *pcVar10;
  undefined4 uVar11;
  int *piVar12;
  int *piVar13;
  VARIANTARG local_60;
  VARIANTARG local_50;
  undefined1 *local_3c;
  int *local_38;
  undefined4 local_34;
  int local_30;
  void *local_2c;
  BSTR local_28;
  BSTR local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  pcVar10 = SysFreeString_exref;
  uStack_4 = 0x50;
  uVar11 = 0;
  local_8 = 0;
  local_34 = 0;
  local_2c = this;
  if (*(int *)param_1 == 0) {
    uVar11 = 0x80004005;
  }
  else {
    FUN_42403802((uint *)&local_60);
    local_8._0_1_ = 3;
    (**(code **)(**(int **)pOVar1 + 0x474))();
    CComQIPtr<>(&local_18,(undefined4 *)local_60.n1._8_4_);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (local_18 != (int *)0x0) {
      local_1c = 0;
      (**(code **)(*local_18 + 0x24))();
      iVar9 = 0;
      if (0 < local_1c) {
        do {
          FUN_42403802((uint *)&local_50);
          local_30 = iVar9 + 1;
          local_8._0_1_ = 5;
          (**(code **)(*local_18 + 0x20))();
          CComQIPtr<>(local_14,(undefined4 *)local_50.n1._8_4_);
          param_1 = (BSTR)0x0;
          local_8._0_1_ = 7;
          (**(code **)(*local_14[0] + 0x9c))(local_14[0],&param_1);
          pCVar7 = (CComBSTR *)FUN_42403768(&local_28,(int *)&param_1);
          local_8._0_1_ = 8;
          this_00 = (CComBSTR *)FUN_42403768(&local_24,&param_7);
          bVar5 = ATL::CComBSTR::operator==(this_00,pCVar7);
          pcVar10 = SysFreeString_exref;
          SysFreeString(local_24);
          local_8._0_1_ = 7;
          SysFreeString(local_28);
          if (bVar5) {
            piVar8 = extraout_ECX;
            if ((param_5 != '\0') &&
               (bVar5 = FUN_424073ed(&param_1,(BSTR)"TrueType"), piVar8 = extraout_ECX_00, !bVar5))
            {
              local_20 = (int *)0x0;
              (**(code **)(*local_14[0] + 0x3c))();
              piVar8 = extraout_ECX_01;
              if (param_8 < (int)local_20) goto LAB_4245931b;
            }
            piVar3 = local_14[0];
            local_20 = local_14[0];
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 4))();
              piVar8 = extraout_ECX_02;
            }
            local_8._0_1_ = 10;
            local_38 = piVar3;
            piVar13 = piVar3;
            puVar4 = &stack0xffffff8c;
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 4))();
              local_3c = &stack0xffffff8c;
              (**(code **)(*piVar3 + 4))();
              piVar8 = extraout_ECX_03;
              puVar4 = local_3c;
            }
            local_3c = puVar4;
            local_8._0_1_ = 0xb;
            piVar12 = piVar8;
            FUN_42432beb(&stack0xffffff84,&param_3);
            local_8._0_1_ = 10;
            cVar6 = FUN_4245962c(piVar8,(int)piVar12,piVar13);
            puVar2 = param_6;
            if (cVar6 != '\0') {
              FUN_42420daa(param_6,(int *)&local_20);
              bVar5 = FUN_424073ed(&param_1,(BSTR)"TrueType");
              if (bVar5) {
                *param_9 = param_8;
              }
              else {
                (**(code **)(*(int *)*puVar2 + 0x3c))();
              }
              local_8._0_1_ = 9;
              if (piVar3 != (int *)0x0) {
                (**(code **)(*piVar3 + 8))();
              }
              local_8._0_1_ = 7;
              if (piVar3 != (int *)0x0) {
                (**(code **)(*piVar3 + 8))();
              }
              pcVar10 = SysFreeString_exref;
              SysFreeString(param_1);
              local_8 = CONCAT31(local_8._1_3_,5);
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 8))();
              }
              VariantClear(&local_50);
              goto LAB_4245934f;
            }
            local_8._0_1_ = 9;
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 8))();
            }
            local_8._0_1_ = 7;
            pcVar10 = SysFreeString_exref;
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 8))();
              pcVar10 = SysFreeString_exref;
            }
          }
LAB_4245931b:
          (*pcVar10)();
          local_8 = CONCAT31(local_8._1_3_,5);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))();
          }
          VariantClear(&local_50);
          iVar9 = local_30;
        } while (local_30 < local_1c);
      }
    }
    uVar11 = 0x80004005;
LAB_4245934f:
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
    VariantClear(&local_60);
  }
  FUN_4243af0e((int *)&param_3);
  FID_conflict__free(param_3);
  (*pcVar10)();
  return uVar11;
}


