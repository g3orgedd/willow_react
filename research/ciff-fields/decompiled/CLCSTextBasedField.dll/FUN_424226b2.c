// Source: CLCSTextBasedField.dll @ 424226b2; FUN_424226b2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1
FUN_424226b2(BSTR param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            undefined4 param_6,int *param_7)

{
  undefined1 uVar1;
  VARIANTARG local_54;
  VARIANTARG local_44;
  BSTR local_34;
  int *local_30;
  BSTR local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  undefined1 uVar2;
  
  uStack_4 = 0x44;
  local_8 = 0;
  uVar2 = 0;
  uVar1 = 0;
  if (param_7 != (int *)0x0) {
    CComQIPtr<>(local_14,param_7);
    CComQIPtr<>(&local_30,local_14[0]);
    local_8._0_1_ = 2;
    uVar1 = uVar2;
    if (local_14[0] != (int *)0x0) {
      FUN_42420b4b(&local_2c,(GUID *)&DAT_42496ecc);
      local_8._0_1_ = 3;
      (**(code **)(*local_14[0] + 0x74))(local_14[0],local_2c);
      (**(code **)(*local_14[0] + 0x6c))(local_14[0],L"CounterText");
      local_20 = (int *)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*local_14[0] + 0x5c))(local_14[0],&local_20);
      if (local_20 != (int *)0x0) {
        FUN_42403802((uint *)&local_54);
        local_8._0_1_ = 5;
        (**(code **)(*local_20 + 0x28))(local_20,5,0,0,1,&local_54);
        CComQIPtr<>(&local_18,(undefined4 *)local_54.n1._8_4_);
        local_8._0_1_ = 6;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 0x54))(local_18,4);
          FUN_424037d2(&local_34,L"0");
          FUN_42403802((uint *)&local_44);
          local_8._0_1_ = 8;
          (**(code **)(*local_18 + 0x124))(local_18,0,0,0x30,0,&local_44);
          CComQIPtr<>(&param_7,(undefined4 *)local_44.n1._8_4_);
          local_8._0_1_ = 9;
          if (param_7 != (int *)0x0) {
            (**(code **)(*param_7 + 0x80))(param_7,1);
            (**(code **)(*param_7 + 0x28))(param_7,0);
            (**(code **)(*param_7 + 0x48))(param_7,&DAT_42498014);
            (**(code **)(*param_7 + 0x50))(param_7,L"9999");
            (**(code **)(*param_7 + 0x60))(param_7,1);
            (**(code **)(*param_7 + 0x38))(param_7,4);
            (**(code **)(*param_7 + 0xa4))(param_7,0);
            (**(code **)(*param_7 + 0x70))(param_7,&DAT_42495874);
            (**(code **)(*local_18 + 0x108))(local_18,1);
            local_1c = (BSTR)0x0;
            local_8._0_1_ = 10;
            (**(code **)(*param_7 + 0x44))(param_7,&local_1c);
            (**(code **)(*local_18 + 100))(local_18,local_1c);
            (**(code **)(*local_18 + 0x5c))(local_18,local_1c);
            (**(code **)(*local_14[0] + 0xac))(local_14[0],param_1);
            local_24 = 1;
            CComQIPtr<>(&local_28,param_5);
            local_8 = CONCAT31(local_8._1_3_,0xb);
            if (local_28 != (int *)0x0) {
              (**(code **)(*local_28 + 0x3b4))(local_28,&local_24);
            }
            (**(code **)(*local_14[0] + 0xb4))(local_14[0],local_24 * param_2);
            if (local_30 != (int *)0x0) {
              (**(code **)(*local_30 + 0x16c))(local_30,local_24);
            }
            uVar1 = 1;
            local_8._0_1_ = 10;
            if (local_28 != (int *)0x0) {
              (**(code **)(*local_28 + 8))(local_28);
            }
            SysFreeString(local_1c);
          }
          local_8._0_1_ = 8;
          if (param_7 != (int *)0x0) {
            (**(code **)(*param_7 + 8))(param_7);
          }
          VariantClear(&local_44);
          SysFreeString(local_34);
        }
        local_8._0_1_ = 5;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        VariantClear(&local_54);
      }
      local_8._0_1_ = 3;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      SysFreeString(local_2c);
    }
    local_8._0_1_ = 1;
    if (local_30 != (int *)0x0) {
      (**(code **)(*local_30 + 8))(local_30);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  SysFreeString(param_1);
  return uVar1;
}


