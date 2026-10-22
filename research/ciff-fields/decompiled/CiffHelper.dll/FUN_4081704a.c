// Source: CiffHelper.dll @ 4081704a; FUN_4081704a

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4081704a(int *param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  UINT UVar3;
  undefined3 extraout_var;
  undefined8 *puVar4;
  undefined3 extraout_var_00;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined3 extraout_var_01;
  BSTR extraout_ECX;
  BSTR pOVar7;
  int iVar8;
  code *pcVar9;
  int *piVar10;
  BSTR pOVar11;
  LPCWSTR pWVar12;
  uint local_11c [2];
  undefined4 *local_114;
  VARIANTARG local_10c;
  int local_fc;
  VARIANTARG local_f8;
  int local_e8;
  VARIANTARG local_e0;
  int *local_d0;
  VARIANTARG local_cc;
  VARIANTARG local_bc;
  int local_ac;
  int local_a8;
  uint local_a4;
  int *local_a0;
  int local_9c;
  int local_98;
  BSTR local_94;
  int *local_90;
  int *local_8c;
  int local_88;
  int *local_84;
  int local_80;
  uint local_7c;
  IUnknown *local_78;
  int *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  IID *local_64;
  IID *local_60;
  BSTR local_5c;
  BSTR local_58;
  BSTR local_54;
  int *local_50;
  BSTR local_4c;
  BSTR local_48;
  LPCWSTR local_44;
  BSTR local_40;
  int local_3c;
  int *local_38;
  BSTR local_34;
  undefined1 local_30 [8];
  uint local_28 [2];
  undefined4 *local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x118;
  local_8 = 0x40817059;
  local_50 = param_1;
  local_d0 = param_1;
  local_fc = param_2;
  CComQIPtr<>(&local_6c,*(undefined4 **)(param_2 + 8));
  local_8 = 0;
  local_34 = (BSTR)0x0;
  FUN_40802e76(local_11c);
  local_8._0_1_ = 2;
  (**(code **)(*local_6c + 100))();
  CComQIPtr<>(&local_90,local_114);
  local_ac = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  (**(code **)(*local_90 + 0x1c))();
  local_5c = (BSTR)0x0;
  pcVar9 = VariantClear_exref;
  if (0 < local_ac) {
    do {
      FUN_40802e76((uint *)&local_e0);
      local_5c = (BSTR)((int)local_5c + 1);
      local_8._0_1_ = 4;
      (**(code **)(*local_90 + 0x30))();
      CComQIPtr<>(&local_58,(undefined4 *)local_e0.n1._8_4_);
      local_3c = 0;
      local_8._0_1_ = 5;
      (**(code **)(*(int *)local_58 + 0x54))();
      piVar10 = local_50;
      if (local_3c != 0) {
        (**(code **)(*(int *)local_58 + 0x5c))();
        UVar3 = SysStringLen(local_34);
        if ((UVar3 == 0) && (piVar10[0x1c] != 0)) {
          FUN_4080bedd("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
          FUN_408040a6(&local_34,(BSTR)piVar10[0x1c]);
          FUN_4080bedd(";");
        }
        else {
          CComQIPtr<>(&local_74,local_6c);
          FUN_40802e76((uint *)&local_bc);
          local_8._0_1_ = 7;
          (**(code **)(*local_74 + 0xcc))();
          CComQIPtr<>(&local_54,(undefined4 *)local_bc.n1._8_4_);
          local_4c = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,8);
          (**(code **)(*(int *)local_54 + 0x1c))();
          local_70 = (int *)0x1;
          if (0 < (int)local_4c) {
            do {
              FUN_40802e76((uint *)&local_cc);
              local_8._0_1_ = 9;
              (**(code **)(*(int *)local_54 + 0x30))();
              CComQIPtr<>(&local_38,(undefined4 *)local_cc.n1._8_4_);
              local_44 = (LPCWSTR)0x0;
              local_64 = (IID *)0x0;
              local_48 = (BSTR)0x0;
              local_40 = (BSTR)0x0;
              local_8._0_1_ = 0xe;
              (**(code **)(*local_38 + 0x1c))();
              (**(code **)(*local_38 + 0x24))();
              (**(code **)(*local_38 + 0x2c))();
              (**(code **)(*local_38 + 0x34))();
              puVar5 = FUN_408030e3(&local_80,local_34);
              local_8._0_1_ = 0xf;
              puVar6 = FUN_408030e3(&local_84,local_44);
              local_8._0_1_ = 0x10;
              bVar2 = FUN_40805005((LPCWSTR)*puVar6,(ushort *)*puVar5);
              FUN_40803143((int *)&local_84);
              local_8._0_1_ = 0xe;
              FUN_40803143(&local_80);
              if (CONCAT31(extraout_var,bVar2) != 0) {
                FUN_40803e5b(&local_34,(int *)&local_40);
                SysFreeString(local_40);
                SysFreeString(local_48);
                SysFreeString((BSTR)local_64);
                SysFreeString(local_44);
                local_8 = CONCAT31(local_8._1_3_,9);
                if (local_38 != (int *)0x0) {
                  (**(code **)(*local_38 + 8))();
                }
                pcVar9 = VariantClear_exref;
                VariantClear(&local_cc);
                piVar10 = local_50;
                break;
              }
              SysFreeString(local_40);
              SysFreeString(local_48);
              SysFreeString((BSTR)local_64);
              SysFreeString(local_44);
              local_8 = CONCAT31(local_8._1_3_,9);
              if (local_38 != (int *)0x0) {
                (**(code **)(*local_38 + 8))();
              }
              VariantClear(&local_cc);
              local_70 = (int *)((int)local_70 + 1);
              piVar10 = local_50;
              pcVar9 = VariantClear_exref;
            } while ((int)local_70 <= (int)local_4c);
          }
          local_8._0_1_ = 7;
          if (local_54 != (BSTR)0x0) {
            (**(code **)(*(int *)local_54 + 8))();
          }
          (*pcVar9)();
          local_8._0_1_ = 5;
          if (local_74 != (int *)0x0) {
            (**(code **)(*local_74 + 8))();
          }
        }
        UVar3 = SysStringLen(local_34);
        if (UVar3 != 0) {
          puVar4 = (undefined8 *)basic_string<>(local_30,local_34);
          local_8._0_1_ = 0x11;
          FUN_40811e4c(piVar10 + 0x13,(int *)piVar10[0x13],puVar4);
          FUN_4080653d(local_30,'\x01',0);
          local_7c = local_7c & 0xffffff00;
          FUN_40811e7d(piVar10 + 0x13);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if (local_58 != (BSTR)0x0) {
        (**(code **)(*(int *)local_58 + 8))();
      }
      (*pcVar9)();
      param_1 = local_50;
    } while ((int)local_5c < local_ac);
  }
  local_9c = 0;
  local_78 = (IUnknown *)0x0;
  CComQIPtr<>(&local_8c,local_6c);
  if (local_8c != (int *)0x0) {
    FUN_40802e76((uint *)&local_bc);
    local_8 = CONCAT31(local_8._1_3_,0x14);
    (**(code **)(*local_8c + 0xb4))();
    if (local_78 != (IUnknown *)local_bc.n1._8_4_) {
      ATL::AtlComQIPtrAssign(&local_78,(IUnknown *)local_bc.n1._8_4_,(_GUID *)&DAT_4084aaa4);
    }
    if (local_78 != (IUnknown *)0x0) {
      (*local_78->lpVtbl[2].AddRef)(local_78);
      local_64 = (IID *)0x0;
      if (0 < local_9c) {
        do {
          FUN_40802e76((uint *)&local_f8);
          local_64 = (IID *)((int)&local_64->Data1 + 1);
          local_8._0_1_ = 0x15;
          (*local_78->lpVtbl[4].QueryInterface)(local_78,local_64,(void **)&local_f8);
          CComQIPtr<>(&local_4c,(undefined4 *)local_f8.n1._8_4_);
          pcVar9 = VariantClear_exref;
          local_8._0_1_ = 0x16;
          if (local_4c != (BSTR)0x0) {
            local_3c = 0;
            (**(code **)(*(int *)local_4c + 0x54))();
            if (local_3c != 0) {
              (**(code **)(*(int *)local_4c + 100))();
              UVar3 = SysStringLen(local_34);
              if ((UVar3 == 0) && (param_1[0x1c] != 0)) {
                FUN_4080bedd("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
                FUN_408040a6(&local_34,(BSTR)param_1[0x1c]);
                FUN_4080bedd(";");
              }
              else {
                FUN_40802e76((uint *)&local_e0);
                local_8._0_1_ = 0x17;
                (**(code **)(*local_8c + 0xcc))();
                CComQIPtr<>(&local_48,(undefined4 *)local_e0.n1._8_4_);
                local_8._0_1_ = 0x18;
                if (local_48 != (BSTR)0x0) {
                  local_5c = (BSTR)0x0;
                  (**(code **)(*(int *)local_48 + 0x1c))();
                  local_74 = (int *)0x1;
                  if (0 < (int)local_5c) {
                    do {
                      piVar10 = local_74;
                      FUN_40802e76((uint *)&local_cc);
                      local_8._0_1_ = 0x19;
                      (**(code **)(*(int *)local_48 + 0x30))();
                      CComQIPtr<>(&local_38,(undefined4 *)local_cc.n1._8_4_);
                      if (local_38 != (int *)0x0) {
                        local_44 = (LPCWSTR)0x0;
                        local_54 = (BSTR)0x0;
                        local_58 = (BSTR)0x0;
                        local_40 = (BSTR)0x0;
                        local_8._0_1_ = 0x1e;
                        (**(code **)(*local_38 + 0x1c))();
                        (**(code **)(*local_38 + 0x24))();
                        (**(code **)(*local_38 + 0x2c))();
                        (**(code **)(*local_38 + 0x34))();
                        puVar5 = FUN_408030e3(&local_80,local_34);
                        local_8._0_1_ = 0x1f;
                        puVar6 = FUN_408030e3(&local_84,local_44);
                        local_8._0_1_ = 0x20;
                        bVar2 = FUN_40805005((LPCWSTR)*puVar6,(ushort *)*puVar5);
                        FUN_40803143((int *)&local_84);
                        local_8._0_1_ = 0x1e;
                        FUN_40803143(&local_80);
                        if (CONCAT31(extraout_var_00,bVar2) != 0) {
                          FUN_40803e5b(&local_34,(int *)&local_40);
                          SysFreeString(local_40);
                          SysFreeString(local_58);
                          SysFreeString(local_54);
                          SysFreeString(local_44);
                          local_8._0_1_ = 0x19;
                          if (local_38 != (int *)0x0) {
                            (**(code **)(*local_38 + 8))();
                          }
                          VariantClear(&local_cc);
                          break;
                        }
                        SysFreeString(local_40);
                        SysFreeString(local_58);
                        SysFreeString(local_54);
                        SysFreeString(local_44);
                        piVar10 = local_74;
                      }
                      local_8._0_1_ = 0x19;
                      if (local_38 != (int *)0x0) {
                        (**(code **)(*local_38 + 8))();
                      }
                      VariantClear(&local_cc);
                      local_74 = (int *)((int)piVar10 + 1);
                    } while ((int)local_74 <= (int)local_5c);
                  }
                }
                local_8._0_1_ = 0x17;
                if (local_48 != (BSTR)0x0) {
                  (**(code **)(*(int *)local_48 + 8))();
                }
                local_8._0_1_ = 0x16;
                VariantClear(&local_e0);
                param_1 = local_50;
              }
              UVar3 = SysStringLen(local_34);
              if (UVar3 != 0) {
                puVar4 = (undefined8 *)basic_string<>(local_30,local_34);
                local_8._0_1_ = 0x21;
                FUN_40811e4c(param_1 + 0x13,(int *)param_1[0x13],puVar4);
                FUN_4080653d(local_30,'\x01',0);
                local_7c = local_7c & 0xffffff00;
                FUN_40811e7d(param_1 + 0x13);
              }
            }
          }
          local_8 = CONCAT31(local_8._1_3_,0x15);
          if (local_4c != (BSTR)0x0) {
            (**(code **)(*(int *)local_4c + 8))();
          }
          VariantClear(&local_f8);
          param_1 = local_50;
        } while ((int)local_64 < local_9c);
      }
    }
    (*pcVar9)();
  }
  local_68 = (int *)0x0;
  local_98 = 0;
  local_8 = CONCAT31(local_8._1_3_,0x22);
  (**(code **)(*local_6c + 0x1c))();
  iVar8 = 0;
  if (0 < local_98) {
    do {
      FUN_40802e76((uint *)&local_10c);
      local_a8 = iVar8 + 1;
      local_8._0_1_ = 0x23;
      (**(code **)(*local_6c + 0x24))();
      CComQIPtr<>(&local_60,(undefined4 *)local_10c.n1._8_4_);
      local_94 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0x24);
      (**(code **)(local_60->Data1 + 0x1c))();
      piVar10 = (int *)0x0;
      if (0 < (int)local_94) {
        do {
          FUN_40802e76((uint *)&local_cc);
          local_a0 = (int *)((int)piVar10 + 1);
          local_8 = CONCAT31(local_8._1_3_,0x25);
          (**(code **)(local_60->Data1 + 0x24))();
          piVar10 = local_68;
          if (local_68 != (int *)0x0) {
            local_68 = (int *)0x0;
            (**(code **)(*piVar10 + 8))();
          }
          (*(code *)**(undefined4 **)local_cc.n1._8_4_)();
          local_40 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x26);
          (**(code **)(*local_68 + 0x5c))();
          local_44 = (BSTR)0x0;
          (**(code **)(*(int *)local_40 + 0x1c))();
          iVar8 = 0;
          if (0 < (int)local_44) {
            do {
              FUN_40802e76((uint *)&local_e0);
              local_8._0_1_ = 0x27;
              local_88 = iVar8 + 1;
              (**(code **)(*(int *)local_40 + 0x24))();
              CComQIPtr<>(&local_70,(undefined4 *)local_e0.n1._8_4_);
              local_8._0_1_ = 0x28;
              (**(code **)(*local_70 + 0x28))();
              iVar8 = iVar8 + 1;
              if (local_84 == (int *)0x2) {
                (**(code **)(*local_70 + 0x70))();
                UVar3 = SysStringLen(local_34);
                piVar10 = local_50;
                if ((UVar3 == 0) && (local_50[0x1c] != 0)) {
                  FUN_4080bedd("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
                  FUN_408040a6(&local_34,(BSTR)piVar10[0x1c]);
                  FUN_4080bedd(";");
                }
                else {
                  CComQIPtr<>(&local_74,local_6c);
                  FUN_40802e76((uint *)&local_f8);
                  local_8._0_1_ = 0x2a;
                  (**(code **)(*local_74 + 0xcc))();
                  CComQIPtr<>(&local_64,(undefined4 *)local_f8.n1._8_4_);
                  local_5c = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,0x2b);
                  (**(code **)(local_64->Data1 + 0x1c))();
                  local_3c = 1;
                  if (0 < (int)local_5c) {
                    do {
                      iVar8 = local_3c;
                      FUN_40802e76((uint *)&local_bc);
                      local_8._0_1_ = 0x2c;
                      (**(code **)(local_64->Data1 + 0x30))(local_64,iVar8);
                      CComQIPtr<>(&local_38,(undefined4 *)local_bc.n1._8_4_);
                      local_48 = (LPCWSTR)0x0;
                      local_54 = (BSTR)0x0;
                      local_58 = (BSTR)0x0;
                      local_4c = (BSTR)0x0;
                      local_8._0_1_ = 0x31;
                      (**(code **)(*local_38 + 0x1c))(local_38,&local_48);
                      (**(code **)(*local_38 + 0x24))(local_38,&local_54);
                      (**(code **)(*local_38 + 0x2c))(local_38,&local_58);
                      (**(code **)(*local_38 + 0x34))(local_38,&local_4c);
                      puVar5 = FUN_408030e3(&local_7c,local_34);
                      local_8._0_1_ = 0x32;
                      puVar6 = FUN_408030e3(&local_80,local_48);
                      local_8._0_1_ = 0x33;
                      bVar2 = FUN_40805005((LPCWSTR)*puVar6,(ushort *)*puVar5);
                      FUN_40803143(&local_80);
                      local_8._0_1_ = 0x31;
                      FUN_40803143((int *)&local_7c);
                      if (CONCAT31(extraout_var_01,bVar2) != 0) {
                        FUN_40803e5b(&local_34,(int *)&local_4c);
                        SysFreeString(local_4c);
                        SysFreeString(local_58);
                        SysFreeString(local_54);
                        SysFreeString(local_48);
                        local_8 = CONCAT31(local_8._1_3_,0x2c);
                        if (local_38 != (int *)0x0) {
                          (**(code **)(*local_38 + 8))();
                        }
                        pcVar9 = VariantClear_exref;
                        VariantClear(&local_bc);
                        break;
                      }
                      SysFreeString(local_4c);
                      SysFreeString(local_58);
                      SysFreeString(local_54);
                      SysFreeString(local_48);
                      local_8 = CONCAT31(local_8._1_3_,0x2c);
                      if (local_38 != (int *)0x0) {
                        (**(code **)(*local_38 + 8))();
                      }
                      VariantClear(&local_bc);
                      local_3c = local_3c + 1;
                      pcVar9 = VariantClear_exref;
                    } while (local_3c <= (int)local_5c);
                  }
                  local_8._0_1_ = 0x2a;
                  if (local_64 != (IID *)0x0) {
                    (**(code **)(local_64->Data1 + 8))();
                  }
                  (*pcVar9)();
                  local_8._0_1_ = 0x28;
                  piVar10 = local_50;
                  if (local_74 != (int *)0x0) {
                    (**(code **)(*local_74 + 8))();
                    piVar10 = local_50;
                  }
                }
                UVar3 = SysStringLen(local_34);
                iVar8 = local_88;
                if (UVar3 != 0) {
                  puVar4 = (undefined8 *)basic_string<>(local_30,local_34);
                  local_8._0_1_ = 0x34;
                  FUN_40811e4c(piVar10 + 0x13,(int *)piVar10[0x13],puVar4);
                  FUN_4080653d(local_30,'\x01',0);
                  local_a4 = local_a4 & 0xffffff00;
                  FUN_40811e7d(piVar10 + 0x13);
                  iVar8 = local_88;
                }
              }
              local_8 = CONCAT31(local_8._1_3_,0x27);
              if (local_70 != (int *)0x0) {
                (**(code **)(*local_70 + 8))();
              }
              (*pcVar9)();
            } while (iVar8 < (int)local_44);
          }
          local_8 = CONCAT31(local_8._1_3_,0x25);
          if (local_40 != (BSTR)0x0) {
            (**(code **)(*(int *)local_40 + 8))();
          }
          (*pcVar9)();
          piVar10 = local_a0;
        } while ((int)local_a0 < (int)local_94);
      }
      local_8 = CONCAT31(local_8._1_3_,0x23);
      if (local_60 != (IID *)0x0) {
        (**(code **)(local_60->Data1 + 8))();
      }
      (*pcVar9)();
      iVar8 = local_a8;
    } while (local_a8 < local_98);
  }
  local_8._0_1_ = 0x35;
  iVar8 = FUN_4080c4f0((int)local_50);
  if (iVar8 < 0) {
    local_8._0_1_ = 0x13;
    if (local_68 != (int *)0x0) {
      (**(code **)(*local_68 + 8))();
    }
    local_8._0_1_ = 0x12;
    if (local_8c != (int *)0x0) {
      (**(code **)(*local_8c + 8))();
    }
    local_8._0_1_ = 3;
    if (local_78 != (IUnknown *)0x0) {
      (*local_78->lpVtbl->Release)(local_78);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_90 != (int *)0x0) {
      (**(code **)(*local_90 + 8))();
    }
    (*pcVar9)();
    SysFreeString(local_34);
  }
  else {
    local_8 = CONCAT31(local_8._1_3_,0x36);
    local_84 = (int *)local_50[0x13];
    while (piVar10 = local_50, local_84 = (int *)*local_84, local_84 != (int *)local_50[0x13]) {
      if (local_50 + 0x15 != local_84 + 2) {
        FUN_40806812(local_50 + 0x15,(undefined8 *)(local_84 + 2),0,0xffffffff);
      }
      local_3c = FUN_4080cd7c((int)piVar10);
      if (local_3c < 0) {
        FUN_4080c4fb((int)piVar10);
        SysFreeString((BSTR)0x0);
        local_8._0_1_ = 0x13;
        if (local_68 != (int *)0x0) {
          (**(code **)(*local_68 + 8))();
        }
        local_8._0_1_ = 0x12;
        if (local_8c != (int *)0x0) {
          (**(code **)(*local_8c + 8))();
        }
        local_8._0_1_ = 3;
        if (local_78 != (IUnknown *)0x0) {
          (*local_78->lpVtbl->Release)(local_78);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_90 != (int *)0x0) {
          (**(code **)(*local_90 + 8))();
        }
        (*pcVar9)();
        SysFreeString(local_34);
        local_8 = 0xffffffff;
        if (local_6c != (int *)0x0) {
          (**(code **)(*local_6c + 8))();
        }
        FUN_40818385();
        return;
      }
      local_60 = (IID *)0x0;
      while ((int)local_60 < local_ac) {
        FUN_40802e76((uint *)&local_10c);
        local_60 = (IID *)((int)&local_60->Data1 + 1);
        local_8._0_1_ = 0x37;
        (**(code **)(*local_90 + 0x30))();
        pcVar9 = VariantClear_exref;
        CComQIPtr<>(&local_4c,(undefined4 *)local_10c.n1._8_4_);
        local_e8 = 0;
        local_8 = CONCAT31(local_8._1_3_,0x38);
        (**(code **)(*(int *)local_4c + 0x54))();
        if (local_e8 != 0) {
          pOVar7 = local_4c;
          if (local_4c != (BSTR)0x0) {
            (**(code **)(*(int *)local_4c + 4))();
          }
          FUN_4080f9ba(piVar10,(int *)pOVar7);
        }
        local_8._0_1_ = 0x37;
        if (local_4c != (BSTR)0x0) {
          (**(code **)(*(int *)local_4c + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,0x36);
        VariantClear(&local_10c);
      }
      if (local_78 != (IUnknown *)0x0) {
        local_60 = (IID *)0x0;
        while ((int)local_60 < local_9c) {
          FUN_40802e76((uint *)&local_f8);
          local_60 = (IID *)((int)&local_60->Data1 + 1);
          local_8._0_1_ = 0x39;
          (*local_78->lpVtbl[4].QueryInterface)(local_78,local_60,(void **)&local_f8);
          pcVar9 = VariantClear_exref;
          CComQIPtr<>(&local_48,(undefined4 *)local_f8.n1._8_4_);
          local_8._0_1_ = 0x3a;
          if (local_48 != (BSTR)0x0) {
            local_3c = 0;
            (**(code **)(*(int *)local_48 + 0x54))();
            if (local_3c != 0) {
              pOVar7 = local_48;
              if (local_48 != (BSTR)0x0) {
                (**(code **)(*(int *)local_48 + 4))();
              }
              FUN_40810662(piVar10,(int *)pOVar7);
            }
          }
          local_8._0_1_ = 0x39;
          if (local_48 != (BSTR)0x0) {
            (**(code **)(*(int *)local_48 + 8))();
          }
          local_8 = CONCAT31(local_8._1_3_,0x36);
          VariantClear(&local_f8);
        }
      }
      (**(code **)(*local_6c + 0x1c))();
      for (local_3c = 0; local_3c < local_98; local_3c = local_3c + 1) {
        FUN_40802e76(local_28);
        local_8._0_1_ = 0x3b;
        (**(code **)(*local_6c + 0x24))();
        CComQIPtr<>(&local_74,local_20);
        local_a8 = 0;
        local_8 = CONCAT31(local_8._1_3_,0x3c);
        (**(code **)(*local_74 + 0x1c))();
        for (local_88 = 0; local_88 < local_a8; local_88 = local_88 + 1) {
          FUN_40802e40(&local_40,L"");
          FUN_40802e76((uint *)&local_cc);
          local_8._0_1_ = 0x3e;
          (**(code **)(*local_74 + 0x24))();
          piVar1 = local_68;
          if (local_68 != (int *)0x0) {
            local_68 = (int *)0x0;
            (**(code **)(*piVar1 + 8))();
          }
          (*(code *)**(undefined4 **)local_cc.n1._8_4_)();
          piVar10[0x21] = 0;
          CComQIPtr<>(&local_64,local_68);
          if (local_64 != (IID *)0x0) {
            CComQIPtr<>(&local_a0,&local_64->Data1);
            local_8._0_1_ = 0x40;
            if (local_a0 != (int *)0x0) {
              (**(code **)(*local_a0 + 0x140))();
            }
            local_8._0_1_ = 0x3f;
            if (local_a0 != (int *)0x0) {
              (**(code **)(*local_a0 + 8))();
            }
          }
          local_70 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x41);
          (**(code **)(*local_68 + 0x5c))();
          local_a4 = 0;
          (**(code **)(*local_70 + 0x1c))();
          local_54 = (BSTR)0x0;
          while ((int)local_54 < (int)local_a4) {
            FUN_40802e76((uint *)&local_bc);
            local_54 = (BSTR)((int)local_54 + 1);
            local_8._0_1_ = 0x42;
            (**(code **)(*local_70 + 0x24))();
            CComQIPtr<>(&local_38,(undefined4 *)local_bc.n1._8_4_);
            local_8._0_1_ = 0x43;
            (**(code **)(*local_38 + 0x28))();
            if (local_7c == 2) {
              (**(code **)(*piVar10 + 0x1c))();
              local_94 = (BSTR)0x0;
              local_8._0_1_ = 0x44;
              (**(code **)(*local_38 + 0x60))();
              FUN_408040a6(&local_40,local_94);
              pcVar9 = SysFreeString_exref;
LAB_40818171:
              (*pcVar9)();
              piVar10 = local_50;
            }
            else if (local_7c == 4) {
              local_60 = (IID *)0x0;
              local_8._0_1_ = 0x45;
              (**(code **)(*local_38 + 0xb4))();
              FUN_40802e76((uint *)&local_e0);
              local_8._0_1_ = 0x46;
              (**(code **)(*local_6c + 100))();
              CComQIPtr<>(&local_58,(undefined4 *)local_e0.n1._8_4_);
              pOVar7 = (BSTR)&stack0xfffffe50;
              local_8._0_1_ = 0x47;
              pOVar11 = local_58;
              if (local_58 != (BSTR)0x0) {
                (**(code **)(*(int *)local_58 + 4))();
                pOVar7 = extraout_ECX;
              }
              local_8._0_1_ = 0x48;
              FUN_40803baf(&stack0xfffffe4c,(int *)&local_60);
              local_8._0_1_ = 0x47;
              FUN_4081bb85(&local_44,pOVar7,(int *)pOVar11);
              local_8._0_1_ = 0x49;
              local_80 = 0;
              pcVar9 = SysFreeString_exref;
              if ((local_44 != (BSTR)0x0) &&
                 ((**(code **)(*(int *)local_44 + 0x24))(), pcVar9 = SysFreeString_exref,
                 local_80 == 1)) {
                pWVar12 = local_44;
                if (local_44 != (BSTR)0x0) {
                  (**(code **)(*(int *)local_44 + 4))();
                }
                piVar10 = local_38;
                if (local_38 != (int *)0x0) {
                  (**(code **)(*local_38 + 4))(local_38);
                }
                FUN_4080d800(piVar10,(int *)pWVar12);
                local_5c = (BSTR)0x0;
                local_8._0_1_ = 0x4a;
                (**(code **)(*local_38 + 0x60))();
                FUN_408040a6(&local_40,local_5c);
                pcVar9 = SysFreeString_exref;
                SysFreeString(local_5c);
              }
              local_8._0_1_ = 0x47;
              if (local_44 != (BSTR)0x0) {
                (**(code **)(*(int *)local_44 + 8))();
              }
              local_8._0_1_ = 0x46;
              if (local_58 != (BSTR)0x0) {
                (**(code **)(*(int *)local_58 + 8))();
              }
              VariantClear(&local_e0);
              goto LAB_40818171;
            }
            local_8._0_1_ = 0x42;
            if (local_38 != (int *)0x0) {
              (**(code **)(*local_38 + 8))();
            }
            pcVar9 = VariantClear_exref;
            local_8 = CONCAT31(local_8._1_3_,0x41);
            VariantClear(&local_bc);
          }
          UVar3 = SysStringLen(local_40);
          if (UVar3 != 0) {
            (**(code **)(*local_68 + 0x9c))();
          }
          local_8._0_1_ = 0x3f;
          if (local_70 != (int *)0x0) {
            (**(code **)(*local_70 + 8))();
          }
          local_8._0_1_ = 0x3e;
          if (local_64 != (IID *)0x0) {
            (**(code **)(local_64->Data1 + 8))();
          }
          (*pcVar9)();
          local_8 = CONCAT31(local_8._1_3_,0x3c);
          SysFreeString(local_40);
        }
        local_8._0_1_ = 0x3b;
        if (local_74 != (int *)0x0) {
          (**(code **)(*local_74 + 8))();
        }
        local_8 = CONCAT31(local_8._1_3_,0x36);
        (*pcVar9)();
      }
      FUN_4080c4fb((int)piVar10);
    }
    FUN_4080c4fb((int)local_50);
    SysFreeString((BSTR)0x0);
    local_8 = 0x13;
    if (local_68 != (int *)0x0) {
      (**(code **)(*local_68 + 8))();
    }
    local_8._0_1_ = 0x12;
    if (local_8c != (int *)0x0) {
      (**(code **)(*local_8c + 8))();
    }
    local_8._0_1_ = 3;
    if (local_78 != (IUnknown *)0x0) {
      (*local_78->lpVtbl->Release)(local_78);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_90 != (int *)0x0) {
      (**(code **)(*local_90 + 8))();
    }
    (*pcVar9)();
    SysFreeString(local_34);
  }
  local_8 = 0xffffffff;
  if (local_6c != (int *)0x0) {
    (**(code **)(*local_6c + 8))();
  }
  FUN_40818385();
  return;
}


