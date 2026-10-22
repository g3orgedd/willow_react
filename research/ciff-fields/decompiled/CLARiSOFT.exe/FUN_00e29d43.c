// Source: CLARiSOFT.exe @ 00e29d43; FUN_00e29d43

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

undefined4 __thiscall FUN_00e29d43(void *this,BSTR param_1,BSTR param_2)

{
  undefined1 uVar1;
  bool bVar2;
  HRESULT HVar3;
  undefined4 extraout_EAX;
  _union_2683 *pvarg;
  undefined1 uVar4;
  _union_2683 local_90;
  _union_2683 local_80;
  VARIANTARG local_70;
  _union_2683 local_60;
  int local_50 [3];
  void *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  BSTR local_24;
  BSTR local_20;
  int local_1c;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x80;
  local_8 = 0;
  local_44 = this;
  FUN_00e03b51((uint *)&local_90);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 0x19c) + 100))(*(int **)((int)this + 0x19c),&local_90);
  if (local_90.n2.vt != 0) {
    CComQIPtr<>(&local_30,(undefined4 *)local_90._8_4_);
    local_1c = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*local_30 + 0x1c))(local_30,&local_1c);
    uVar4 = 1;
    local_2c = (int *)0x1;
    if (0 < local_1c) {
      do {
        FUN_00e03b51((uint *)&local_60);
        local_8._0_1_ = 4;
        (**(code **)(*local_30 + 0x30))(local_30,local_2c,&local_60);
        CComQIPtr<>(&local_18,(undefined4 *)local_60._8_4_);
        local_14[0] = (BSTR)0x0;
        local_8._0_1_ = 6;
        (**(code **)(*local_18 + 0x1c))(local_18,local_14);
        HVar3 = VarBstrCmp(local_14[0],param_1,0x400,0);
        if (HVar3 != 1) {
          local_20 = (BSTR)0x0;
          local_8._0_1_ = 7;
          (**(code **)(*local_18 + 0xbc))(local_18,&local_20);
          HVar3 = VarBstrCmp(local_20,param_1,0x400,0);
          if (HVar3 == 1) {
            SysFreeString(local_20);
            SysFreeString(local_14[0]);
            local_8 = CONCAT31(local_8._1_3_,4);
            if (local_18 != (int *)0x0) {
              (**(code **)(*local_18 + 8))(local_18);
            }
            pvarg = &local_60;
LAB_00e2a13e:
            VariantClear((VARIANTARG *)&pvarg->n2);
            local_8._0_1_ = 2;
            uVar1 = (undefined1)local_8;
            local_8._0_1_ = 2;
            if (local_30 != (int *)0x0) {
              (**(code **)(*local_30 + 8))(local_30);
              uVar1 = (undefined1)local_8;
            }
            goto LAB_00e2a0aa;
          }
          SysFreeString(local_20);
        }
        SysFreeString(local_14[0]);
        local_8._0_1_ = 4;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        VariantClear((VARIANTARG *)&local_60.n2);
        local_2c = (int *)((int)local_2c + 1);
      } while ((int)local_2c <= local_1c);
    }
    local_50[1] = 0;
    (**(code **)(**(int **)((int)local_44 + 0x19c) + 0x1c))
              (*(int **)((int)local_44 + 0x19c),local_50 + 1);
    local_40 = 1;
    if (0 < local_1c) {
      do {
        FUN_00e03b51((uint *)&local_80);
        local_8._0_1_ = 8;
        (**(code **)(**(int **)((int)local_44 + 0x19c) + 0x24))
                  (*(int **)((int)local_44 + 0x19c),local_40,&local_80);
        CComQIPtr<>(&local_2c,(undefined4 *)local_80._8_4_);
        local_8._0_1_ = 9;
        if (local_2c != (int *)0x0) {
          local_3c = 0;
          (**(code **)(*local_2c + 0x1c))(local_2c,&local_3c);
          local_38 = 1;
          if (0 < local_3c) {
            do {
              FUN_00e03b51((uint *)&local_70);
              local_8._0_1_ = 10;
              (**(code **)(*local_2c + 0x24))(local_2c,local_38,&local_70);
              CComQIPtr<>(&local_20,(undefined4 *)local_70.n1._8_4_);
              local_14[0] = (BSTR)0x0;
              local_8._0_1_ = 0xc;
              (**(code **)(*(int *)local_20 + 0x1c))(local_20,local_14);
              bVar2 = FUN_00e03edc(&param_2,L"");
              if ((bVar2) || (HVar3 = VarBstrCmp(local_14[0],param_2,0x400,0), HVar3 != 1)) {
                local_18 = (int *)0x0;
                local_8._0_1_ = 0xd;
                (**(code **)(*(int *)local_20 + 0x5c))(local_20,&local_18);
                (**(code **)(*local_18 + 0x1c))(local_18,local_50 + 2);
                local_34 = 1;
                if (0 < local_50[2]) {
                  do {
                    FUN_00e03b51((uint *)&local_60);
                    local_8._0_1_ = 0xe;
                    (**(code **)(*local_18 + 0x24))(local_18,local_34,&local_60);
                    if (local_60.n2.vt != 0) {
                      CComQIPtr<>(&local_28,(undefined4 *)local_60._8_4_);
                      local_8._0_1_ = 0xf;
                      (**(code **)(*local_28 + 0x28))(local_28,local_50);
                      if (local_50[0] == 4) {
                        local_24 = (BSTR)0x0;
                        local_8._0_1_ = 0x10;
                        (**(code **)(*local_28 + 0xb4))(local_28,&local_24);
                        HVar3 = VarBstrCmp(local_24,param_1,0x400,0);
                        if (HVar3 == 1) {
                          SysFreeString(local_24);
                          local_8._0_1_ = 0xe;
                          if (local_28 != (int *)0x0) {
                            (**(code **)(*local_28 + 8))(local_28);
                          }
                          VariantClear((VARIANTARG *)&local_60.n2);
                          local_8._0_1_ = 0xc;
                          if (local_18 != (int *)0x0) {
                            (**(code **)(*local_18 + 8))(local_18);
                          }
                          SysFreeString(local_14[0]);
                          local_8._0_1_ = 10;
                          if (local_20 != (BSTR)0x0) {
                            (**(code **)(*(int *)local_20 + 8))(local_20);
                          }
                          VariantClear(&local_70);
                          local_8 = CONCAT31(local_8._1_3_,8);
                          if (local_2c != (int *)0x0) {
                            (**(code **)(*local_2c + 8))(local_2c);
                          }
                          pvarg = &local_80;
                          goto LAB_00e2a13e;
                        }
                        SysFreeString(local_24);
                      }
                      local_8._0_1_ = 0xe;
                      if (local_28 != (int *)0x0) {
                        (**(code **)(*local_28 + 8))(local_28);
                      }
                    }
                    VariantClear((VARIANTARG *)&local_60.n2);
                    local_34 = local_34 + 1;
                  } while (local_34 <= local_50[2]);
                }
                local_8._0_1_ = 0xc;
                if (local_18 != (int *)0x0) {
                  (**(code **)(*local_18 + 8))(local_18);
                }
              }
              SysFreeString(local_14[0]);
              local_8._0_1_ = 10;
              if (local_20 != (BSTR)0x0) {
                (**(code **)(*(int *)local_20 + 8))(local_20);
              }
              VariantClear(&local_70);
              local_38 = local_38 + 1;
            } while (local_38 <= local_3c);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,8);
        if (local_2c != (int *)0x0) {
          (**(code **)(*local_2c + 8))(local_2c);
        }
        VariantClear((VARIANTARG *)&local_80.n2);
        local_40 = local_40 + 1;
      } while (local_40 <= local_1c);
    }
    local_8._0_1_ = 2;
    if (local_30 != (int *)0x0) {
      (**(code **)(*local_30 + 8))(local_30);
    }
  }
  uVar4 = 0;
  uVar1 = (undefined1)local_8;
LAB_00e2a0aa:
  local_8._0_1_ = uVar1;
  VariantClear((VARIANTARG *)&local_90.n2);
  SysFreeString(param_1);
  SysFreeString(param_2);
  return CONCAT31((int3)((uint)extraout_EAX >> 8),uVar4);
}


