// Source: CLCSTextBasedField.dll @ 42422d37; FUN_42422d37

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __thiscall
FUN_42422d37(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4
            ,undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
            undefined4 *param_9,undefined4 param_10,int *param_11)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  undefined1 uVar5;
  code *pcVar6;
  BSTR pOVar7;
  VARIANTARG local_78;
  VARIANTARG local_68;
  VARIANTARG local_58;
  int *local_48;
  int *local_44;
  undefined1 local_40 [4];
  int *local_3c;
  int local_38;
  undefined4 local_34;
  BSTR local_30;
  int *local_2c;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  pcVar6 = SysFreeString_exref;
  uStack_4 = 0x68;
  local_8 = 0;
  uVar5 = 0;
  local_2c = this;
  if (param_11 == (int *)0x0) goto LAB_4242319a;
  CComQIPtr<>(&param_11,param_11);
  CComQIPtr<>(&local_44,param_11);
  local_8._0_1_ = 2;
  if (param_11 != (int *)0x0) {
    FUN_42420b4b(local_40,(GUID *)&DAT_42496ecc);
    local_8._0_1_ = 3;
    (**(code **)(*param_11 + 0x74))();
    local_28 = (int *)0x0;
    local_8._0_1_ = 4;
    (**(code **)(*param_11 + 0x5c))();
    if (local_28 != (int *)0x0) {
      (**(code **)(*param_11 + 0x6c))();
      FUN_42403802((uint *)&local_78);
      local_8._0_1_ = 5;
      (**(code **)(*local_28 + 0x28))();
      CComQIPtr<>(&local_1c,(undefined4 *)local_78.n1._8_4_);
      local_8._0_1_ = 6;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 0x54))();
        FUN_424037d2(&local_24,L"PPpp");
        local_8._0_1_ = 7;
        (**(code **)(*local_1c + 0x5c))();
        (**(code **)(*local_1c + 100))();
        (**(code **)(*param_11 + 0x9c))();
        local_14[0] = 0;
        local_8._0_1_ = 8;
        (**(code **)(*param_11 + 0x1c))();
        CComQIPtr<>(&local_18,local_1c);
        local_8._0_1_ = 9;
        uVar5 = (undefined1)local_8;
        local_8._0_1_ = 9;
        if (local_18 != (int *)0x0) {
          FUN_4240719d(&local_30,"Price");
          local_8._0_1_ = 10;
          iVar1 = FUN_42403ee7(local_14,local_30);
          if (iVar1 < 0) {
LAB_42422e95:
                    /* WARNING: Subroutine does not return */
            FUN_42403fdf(iVar1);
          }
          local_8._0_1_ = 9;
          SysFreeString(local_30);
          FUN_4240375f(&local_34);
          local_8 = CONCAT31(local_8._1_3_,0xb);
          pOVar7 = extraout_ECX;
          FUN_42403768(&stack0xffffff3c,local_14);
          piVar2 = FUN_42405325((BSTR)local_2c[0x37],pOVar7);
          local_48 = piVar2;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 4))();
          }
          local_8._0_1_ = 0xc;
          if (piVar2 == (int *)0x0) {
LAB_42422f41:
            CComQIPtr<>(&local_30,param_3);
            if (local_30 != (BSTR)0x0) {
              FUN_42403802((uint *)&local_68);
              local_8._0_1_ = 0xf;
              (**(code **)(*(int *)local_30 + 0xb4))(local_30);
              CComQIPtr<>(&local_2c,(undefined4 *)local_68.n1._8_4_);
              if (local_2c != (int *)0x0) {
                FUN_42403802((uint *)&local_58);
                local_8._0_1_ = 0x11;
                (**(code **)(*local_2c + 0x20))(local_2c,local_14[0]);
                CComQIPtr<>(&local_20,(undefined4 *)local_58.n1._8_4_);
                local_8._0_1_ = 0x12;
                if (local_20 != (int *)0x0) {
                  (**(code **)(*local_20 + 0x28))(local_20);
                  (**(code **)(*local_20 + 0x40))(local_20,0);
                  (**(code **)(*local_20 + 0x50))(local_20,0);
                }
                local_8._0_1_ = 0x11;
                if (local_20 != (int *)0x0) {
                  (**(code **)(*local_20 + 8))();
                }
                VariantClear(&local_58);
              }
              local_8._0_1_ = 0xf;
              if (local_2c != (int *)0x0) {
                (**(code **)(*local_2c + 8))();
              }
              VariantClear(&local_68);
            }
            local_8._0_1_ = 0xc;
            if (local_30 != (BSTR)0x0) {
              (**(code **)(*(int *)local_30 + 8))();
            }
          }
          else {
            FUN_4240719d(&local_30,"001");
            local_8._0_1_ = 0xd;
            iVar1 = FUN_42403ee7(local_14,local_30);
            if (iVar1 < 0) goto LAB_42422e95;
            local_8._0_1_ = 0xc;
            SysFreeString(local_30);
            pOVar7 = extraout_ECX_00;
            FUN_42403768(&stack0xffffff3c,local_14);
            piVar3 = FUN_42405325((BSTR)local_2c[0x37],pOVar7);
            if (piVar3 == (int *)0x0) goto LAB_42422f41;
            (**(code **)(*piVar3 + 4))();
            (**(code **)(*piVar3 + 8))(piVar3);
          }
          piVar3 = local_18;
          FUN_42403768(&local_30,local_14);
          local_8._0_1_ = 0x13;
          (**(code **)(*piVar3 + 0x144))(piVar3);
          local_8._0_1_ = 0xc;
          SysFreeString(local_30);
          piVar3 = local_18;
          puVar4 = FUN_424037d2(&local_30,L"\'£\'P\'.\'pp");
          local_8._0_1_ = 0x14;
          (**(code **)(*piVar3 + 0x14c))(piVar3,*puVar4);
          local_8._0_1_ = 0xc;
          SysFreeString(local_30);
          piVar3 = local_18;
          puVar4 = FUN_424037d2(&local_30,L"ppp\'p\'");
          local_8._0_1_ = 0x15;
          (**(code **)(*piVar3 + 0x154))(piVar3,*puVar4);
          pcVar6 = SysFreeString_exref;
          SysFreeString(local_30);
          local_8._0_1_ = 0xb;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))();
          }
          local_8._0_1_ = 9;
          FUN_42403ab6(&local_34);
          uVar5 = (undefined1)local_8;
        }
        local_8._0_1_ = uVar5;
        (**(code **)(*param_11 + 0xac))(param_11);
        local_38 = 1;
        CComQIPtr<>(&local_3c,param_9);
        local_8 = CONCAT31(local_8._1_3_,0x16);
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 0x3b4))(local_3c,&local_38);
        }
        (**(code **)(*param_11 + 0xb4))(param_11,local_38 * param_6);
        if (local_44 != (int *)0x0) {
          (**(code **)(*local_44 + 0x16c))(local_44,local_38);
        }
        uVar5 = 1;
        local_8._0_1_ = 9;
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 8))(local_3c);
        }
        local_8._0_1_ = 8;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        (*pcVar6)(local_14[0]);
        (*pcVar6)(local_24);
      }
      local_8._0_1_ = 5;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))();
      }
      VariantClear(&local_78);
    }
    local_8._0_1_ = 3;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))();
    }
    (*pcVar6)();
  }
  local_8._0_1_ = 1;
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_11 != (int *)0x0) {
    (**(code **)(*param_11 + 8))();
  }
LAB_4242319a:
  (*pcVar6)();
  return uVar5;
}


