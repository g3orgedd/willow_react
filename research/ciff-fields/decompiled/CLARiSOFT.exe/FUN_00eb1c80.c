// Source: CLARiSOFT.exe @ 00eb1c80; FUN_00eb1c80

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00eb1c80(void *this,BSTR param_1,BSTR param_2)

{
  void *this_00;
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *in_stack_ffffff44;
  BSTR pOVar7;
  BSTR pOVar8;
  BSTR pOVar9;
  int **ppiVar10;
  BSTR pOVar11;
  BSTR pOVar12;
  _union_2683 local_68;
  _union_2683 local_58;
  undefined4 *local_48;
  BSTR local_44;
  int local_40;
  int local_3c;
  BSTR local_38;
  void *local_34;
  int *local_30;
  int local_2c;
  BSTR local_28;
  BSTR local_24;
  int local_20;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_34 = this;
  (**(code **)(*(int *)param_1 + 0x1c))();
  iVar5 = 0;
  if (0 < local_40) {
    do {
      FUN_00e03b51((uint *)&local_68);
      local_8._0_1_ = 2;
      local_3c = iVar5 + 1;
      (**(code **)(*(int *)param_1 + 0x24))();
      iVar5 = iVar5 + 1;
      if (local_68.n2.vt != 0) {
        CComQIPtr<>(&local_18,(undefined4 *)local_68._8_4_);
        local_8._0_1_ = 3;
        (**(code **)(*local_18 + 0x1c))();
        local_38 = (BSTR)0x0;
        local_8._0_1_ = 4;
        (**(code **)(*local_18 + 0x4c))();
        local_14[0] = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,5);
        pOVar12 = param_2;
        if (param_2 != (BSTR)0x0) {
          (**(code **)(*(int *)param_2 + 4))();
        }
        piVar2 = FUN_00eb5f25((int *)pOVar12);
        local_30 = piVar2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))();
        }
        local_8._0_1_ = 6;
        piVar6 = (int *)0x0;
        if (((piVar2 != (int *)0x0) &&
            (FUN_00e2f762((int *)&local_30,(undefined4 *)((int)this + 0x20),local_14),
            this_00 = local_34, piVar6 = local_14[0], local_14[0] != (int *)0x0)) &&
           (local_20 = 0, 0 < local_2c)) {
          iVar5 = 0;
          do {
            FUN_00e03b51((uint *)&local_58);
            iVar5 = iVar5 + 1;
            local_8._0_1_ = 7;
            local_20 = iVar5;
            (**(code **)(*local_18 + 0x24))();
            if (local_58.n2.vt != 0) {
              CComQIPtr<>(&local_28,(undefined4 *)local_58._8_4_);
              pOVar12 = local_28;
              local_8._0_1_ = 9;
              local_44 = local_28;
              if (local_28 != (BSTR)0x0) {
                (**(code **)(*(int *)local_28 + 4))();
              }
              local_24 = (BSTR)0x0;
              local_8._0_1_ = 10;
              (**(code **)(*(int *)pOVar12 + 0x68))();
              bVar1 = FUN_00e03edc(&local_24,L"MergeField");
              if (bVar1) {
                local_1c = (BSTR)0x0;
                local_8._0_1_ = 0xb;
                (**(code **)(*(int *)pOVar12 + 0x1c))();
                bVar1 = false;
                if (*(int *)((int)this_00 + 0x14) == 0) {
                  puVar3 = (undefined4 *)FUN_00eca369(8);
                  local_8._0_1_ = 0xc;
                  local_48 = puVar3;
                  if (puVar3 == (undefined4 *)0x0) {
                    puVar3 = (undefined4 *)0x0;
                  }
                  else {
                    *puVar3 = 0;
                    puVar3[1] = 0;
                    uVar4 = FUN_00e68516((int *)0x0,(int *)0x0);
                    *puVar3 = uVar4;
                  }
                  *(undefined4 **)((int)this_00 + 0x14) = puVar3;
                  bVar1 = true;
                  local_8._0_1_ = 0xb;
                }
                FUN_00e03ab8(&stack0xffffff5c,(int *)&local_1c);
                pOVar11 = param_1;
                if (param_1 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_1 + 4))();
                }
                pOVar8 = param_2;
                if (param_2 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_2 + 4))(param_2);
                }
                pOVar7 = pOVar12;
                pOVar9 = pOVar12;
                (**(code **)(*(int *)pOVar12 + 4))();
                FUN_00eb296a(this_00,(int *)pOVar7,(int *)pOVar9,pOVar8,pOVar11);
                if (bVar1) {
                  if (*(void **)((int)this_00 + 0x14) != (void *)0x0) {
                    FUN_00eafb3c(*(void **)((int)this_00 + 0x14),1);
                  }
                  *(undefined4 *)((int)this_00 + 0x14) = 0;
                }
                local_8._0_1_ = 10;
                SysFreeString(local_1c);
                iVar5 = local_20;
              }
              else {
                if (param_1 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_1 + 4))();
                }
                pOVar11 = param_2;
                if (param_2 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_2 + 4))();
                }
                ppiVar10 = local_14;
                piVar2 = (int *)0xeb1ee7;
                pOVar8 = pOVar12;
                pOVar7 = pOVar12;
                (**(code **)(*(int *)pOVar12 + 4))();
                FUN_00eb1420(this_00,in_stack_ffffff44,piVar2,(int *)pOVar8,pOVar7,(BSTR)ppiVar10,
                             pOVar11);
              }
              (**(code **)(*(int *)local_58._8_4_ + 8))();
              local_58._8_4_ = (int *)0x0;
              local_58.n2.vt = 0;
              SysFreeString(local_24);
              local_8._0_1_ = 8;
              (**(code **)(*(int *)pOVar12 + 8))();
              local_8._0_1_ = 7;
              if (local_28 != (BSTR)0x0) {
                (**(code **)(*(int *)local_28 + 8))();
              }
            }
            local_8._0_1_ = 6;
            VariantClear((VARIANTARG *)&local_58.n2);
            piVar2 = local_30;
            this = local_34;
            piVar6 = local_14[0];
          } while (iVar5 < local_2c);
        }
        (**(code **)(*(int *)local_68._8_4_ + 8))();
        local_68._8_4_ = (int *)0x0;
        local_68.n2.vt = 0;
        local_8._0_1_ = 5;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))();
        }
        local_8._0_1_ = 4;
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 8))();
        }
        SysFreeString(local_38);
        local_8._0_1_ = 2;
        iVar5 = local_3c;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))();
          iVar5 = local_3c;
        }
      }
      VariantClear((VARIANTARG *)&local_68.n2);
    } while (iVar5 < local_40);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (BSTR)0x0) {
    (**(code **)(*(int *)param_1 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_2 != (BSTR)0x0) {
    (**(code **)(*(int *)param_2 + 8))();
  }
  return 0;
}


