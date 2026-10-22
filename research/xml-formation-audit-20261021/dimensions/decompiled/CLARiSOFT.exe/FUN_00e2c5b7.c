// Source: CLARiSOFT.exe @ 00e2c5b7; FUN_00e2c5b7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_00e2c5b7(int *param_1)

{
  int iVar1;
  UINT UVar2;
  int *piVar3;
  undefined1 uVar4;
  bool bVar5;
  VARIANTARG local_b0;
  VARIANTARG local_a0;
  VARIANTARG local_90;
  _union_2683 local_80;
  _union_2683 local_70;
  _union_2683 local_60;
  int local_50;
  int local_4c;
  int local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  BSTR local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa0;
  local_1c = (int *)0x0;
  local_8 = 0;
  (**(code **)(*(int *)param_1[1] + 0x5c))((int *)param_1[1],&local_1c);
  uVar4 = 0;
  if (local_1c != (int *)0x0) {
    local_40 = 0;
    (**(code **)(*local_1c + 0x1c))(local_1c,&local_40);
    local_4c = 0;
    uVar4 = 0;
    if (0 < local_40) {
      do {
        FUN_00e03b51((uint *)&local_b0);
        local_8._0_1_ = 1;
        (**(code **)(*local_1c + 0x24))(local_1c,1,&local_b0);
        CComQIPtr<>(&param_1,(undefined4 *)local_b0.n1._8_4_);
        local_8._0_1_ = 2;
        (**(code **)(*param_1 + 0x28))(param_1,&local_50);
        if (local_50 == 2) {
LAB_00e2ca40:
          local_8 = CONCAT31(local_8._1_3_,1);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
          VariantClear(&local_b0);
          uVar4 = 1;
          break;
        }
        if (local_50 == 4) {
          local_14[0] = (BSTR)0x0;
          local_8._0_1_ = 3;
          iVar1 = (**(code **)(*param_1 + 0xb4))(param_1,local_14);
          if ((-1 < iVar1) && (UVar2 = SysStringLen(local_14[0]), UVar2 != 0)) {
            FUN_00e03b51((uint *)&local_90);
            local_8._0_1_ = 4;
            (**(code **)(**(int **)(local_48 + 0x19c) + 100))(*(int **)(local_48 + 0x19c),&local_90)
            ;
            CComQIPtr<>(&local_34,(undefined4 *)local_90.n1._8_4_);
            if (local_34 != (int *)0x0) {
              FUN_00e03b51((uint *)&local_80);
              local_8._0_1_ = 6;
              iVar1 = (**(code **)(*local_34 + 0x28))(local_34,local_14[0],&local_80);
              if ((-1 < iVar1) && (local_80.n2.vt == 9)) {
                CComQIPtr<>(&local_3c,(undefined4 *)local_80._8_4_);
                local_8._0_1_ = 7;
                if (local_3c != (int *)0x0) {
                  local_20 = 0;
                  (**(code **)(*local_3c + 0x54))(local_3c,&local_20);
                  if (local_20 == 1) {
                    local_8._0_1_ = 6;
                    if (local_3c != (int *)0x0) {
                      (**(code **)(*local_3c + 8))(local_3c);
                    }
                    VariantClear((VARIANTARG *)&local_80.n2);
                    local_8._0_1_ = 4;
                    if (local_34 != (int *)0x0) {
                      (**(code **)(*local_34 + 8))(local_34);
                    }
                    VariantClear(&local_90);
                    SysFreeString(local_14[0]);
                    goto LAB_00e2ca40;
                  }
                }
                local_8._0_1_ = 6;
                if (local_3c != (int *)0x0) {
                  (**(code **)(*local_3c + 8))(local_3c);
                }
              }
              VariantClear((VARIANTARG *)&local_80.n2);
            }
            local_8._0_1_ = 4;
            if (local_34 != (int *)0x0) {
              (**(code **)(*local_34 + 8))(local_34);
            }
            VariantClear(&local_90);
          }
          SysFreeString(local_14[0]);
        }
        else {
          if (local_50 == 7) {
            CComQIPtr<>(&local_44,param_1);
            bVar5 = local_44 == (int *)0x0;
            piVar3 = local_44;
            if (!bVar5) {
              local_14[0] = (BSTR)0x0;
              local_8._0_1_ = 9;
              iVar1 = (**(code **)(*local_44 + 0x140))(local_44,local_14);
              if ((-1 < iVar1) && (UVar2 = SysStringLen(local_14[0]), UVar2 != 0)) {
                CComQIPtr<>(&local_30,*(undefined4 **)(local_48 + 0x19c));
                if (local_30 != (int *)0x0) {
                  FUN_00e03b51((uint *)&local_a0);
                  local_8._0_1_ = 0xb;
                  (**(code **)(*local_30 + 0xb4))(local_30,&local_a0);
                  CComQIPtr<>(&local_24,(undefined4 *)local_a0.n1._8_4_);
                  if (local_24 != (int *)0x0) {
                    FUN_00e03b51((uint *)&local_70);
                    local_8._0_1_ = 0xd;
                    iVar1 = (**(code **)(*local_24 + 0x28))(local_24,local_14[0],&local_70);
                    if ((-1 < iVar1) && (local_70.n2.vt == 9)) {
                      CComQIPtr<>(&local_38,(undefined4 *)local_70._8_4_);
                      local_8._0_1_ = 0xe;
                      if (local_38 != (int *)0x0) {
                        local_20 = 0;
                        (**(code **)(*local_38 + 0x54))(local_38,&local_20);
                        if (local_20 == 1) {
                          local_8._0_1_ = 0xd;
                          if (local_38 != (int *)0x0) {
                            (**(code **)(*local_38 + 8))(local_38);
                          }
                          VariantClear((VARIANTARG *)&local_70.n2);
                          local_8._0_1_ = 0xb;
                          if (local_24 != (int *)0x0) {
                            (**(code **)(*local_24 + 8))(local_24);
                          }
                          VariantClear(&local_a0);
                          local_8 = CONCAT31(local_8._1_3_,9);
                          if (local_30 != (int *)0x0) {
                            (**(code **)(*local_30 + 8))(local_30);
                          }
                          SysFreeString(local_14[0]);
                          goto LAB_00e2ca32;
                        }
                      }
                      local_8._0_1_ = 0xd;
                      if (local_38 != (int *)0x0) {
                        (**(code **)(*local_38 + 8))(local_38);
                      }
                    }
                    VariantClear((VARIANTARG *)&local_70.n2);
                  }
                  local_8._0_1_ = 0xb;
                  if (local_24 != (int *)0x0) {
                    (**(code **)(*local_24 + 8))(local_24);
                  }
                  VariantClear(&local_a0);
                }
                local_8._0_1_ = 9;
                if (local_30 != (int *)0x0) {
                  (**(code **)(*local_30 + 8))(local_30);
                }
              }
              SysFreeString(local_14[0]);
              piVar3 = local_44;
LAB_00e2c959:
              bVar5 = piVar3 == (int *)0x0;
            }
          }
          else {
            if (local_50 != 3) goto LAB_00e2c967;
            CComQIPtr<>(&local_2c,param_1);
            bVar5 = local_2c == (int *)0x0;
            piVar3 = local_2c;
            if (!bVar5) {
              FUN_00e03b51((uint *)&local_60);
              local_8._0_1_ = 0x10;
              iVar1 = (**(code **)(*local_2c + 0x13c))(local_2c,&local_60);
              if (((-1 < iVar1) && (local_60.n2.vt == 9)) &&
                 ((undefined4 *)local_60._8_4_ != (undefined4 *)0x0)) {
                local_18 = (int *)0x0;
                local_8._0_1_ = 0x11;
                iVar1 = (*(code *)**(undefined4 **)local_60._8_4_)
                                  (local_60._8_4_,&DAT_00efd194,&local_18);
                if ((-1 < iVar1) && (local_18 != (int *)0x0)) {
                  local_28 = (BSTR)0x0;
                  local_8._0_1_ = 0x12;
                  (**(code **)(*local_18 + 0x48))(local_18,&local_28);
                  UVar2 = SysStringLen(local_28);
                  if (UVar2 != 0) {
                    SysFreeString(local_28);
                    local_8 = CONCAT31(local_8._1_3_,0x10);
                    if (local_18 != (int *)0x0) {
                      (**(code **)(*local_18 + 8))(local_18);
                    }
                    VariantClear((VARIANTARG *)&local_60.n2);
                    local_44 = local_2c;
LAB_00e2ca32:
                    local_8._0_1_ = 2;
                    if (local_44 != (int *)0x0) {
                      (**(code **)(*local_44 + 8))(local_44);
                    }
                    goto LAB_00e2ca40;
                  }
                  SysFreeString(local_28);
                }
                local_8._0_1_ = 0x10;
                if (local_18 != (int *)0x0) {
                  (**(code **)(*local_18 + 8))(local_18);
                }
              }
              VariantClear((VARIANTARG *)&local_60.n2);
              piVar3 = local_2c;
              goto LAB_00e2c959;
            }
          }
          local_8._0_1_ = 2;
          if (!bVar5) {
            (**(code **)(*piVar3 + 8))(piVar3);
          }
        }
LAB_00e2c967:
        local_8 = CONCAT31(local_8._1_3_,1);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
        VariantClear(&local_b0);
        local_4c = local_4c + 1;
      } while (local_4c < local_40);
    }
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return uVar4;
}


