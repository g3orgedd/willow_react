// Source: CLCSTextBasedField.dll @ 4242296c; FUN_4242296c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1
FUN_4242296c(BSTR param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            undefined4 param_6,int *param_7)

{
  undefined1 uVar1;
  VARIANTARG local_3c;
  int *local_2c;
  BSTR local_28;
  BSTR local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0;
  uVar1 = 0;
  if (param_7 != (int *)0x0) {
    CComQIPtr<>(&param_7,param_7);
    CComQIPtr<>(&local_2c,param_7);
    local_8._0_1_ = 2;
    if (param_7 != (int *)0x0) {
      FUN_42420b4b(&local_28,(GUID *)&DAT_42496ecc);
      local_8._0_1_ = 3;
      (**(code **)(*param_7 + 0x74))(param_7,local_28);
      (**(code **)(*param_7 + 0x6c))(param_7,L"DateText");
      local_18 = (int *)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*param_7 + 0x5c))(param_7,&local_18);
      if (local_18 != (int *)0x0) {
        FUN_42403802((uint *)&local_3c);
        local_8._0_1_ = 5;
        (**(code **)(*local_18 + 0x28))(local_18,0,0,0,1,&local_3c);
        CComQIPtr<>(local_14,(undefined4 *)local_3c.n1._8_4_);
        local_8._0_1_ = 6;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 0x54))(local_14[0],2);
          FUN_424037d2(&local_24,L"dd\'/\'MM\'/\'yyyy");
          local_8._0_1_ = 7;
          (**(code **)(*local_14[0] + 0x98))(local_14[0],0);
          (**(code **)(*local_14[0] + 0x5c))(local_14[0],local_24);
          (**(code **)(*param_7 + 0xac))(param_7,param_1);
          local_1c = 1;
          CComQIPtr<>(&local_20,param_5);
          local_8 = CONCAT31(local_8._1_3_,8);
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 0x3b4))(local_20,&local_1c);
          }
          (**(code **)(*param_7 + 0xb4))(param_7,local_1c * param_2);
          if (local_2c != (int *)0x0) {
            (**(code **)(*local_2c + 0x16c))(local_2c,local_1c);
          }
          uVar1 = 1;
          local_8._0_1_ = 7;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          SysFreeString(local_24);
        }
        local_8._0_1_ = 5;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        VariantClear(&local_3c);
      }
      local_8._0_1_ = 3;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      SysFreeString(local_28);
    }
    local_8._0_1_ = 1;
    if (local_2c != (int *)0x0) {
      (**(code **)(*local_2c + 8))(local_2c);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (param_7 != (int *)0x0) {
      (**(code **)(*param_7 + 8))(param_7);
    }
  }
  SysFreeString(param_1);
  return uVar1;
}


