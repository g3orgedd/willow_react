// Source: CLCSTextBasedField.dll @ 424231a9; FUN_424231a9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1
FUN_424231a9(BSTR param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            undefined4 param_6,int *param_7)

{
  int *piVar1;
  undefined4 *puVar2;
  UINT UVar3;
  VARIANTARG local_44;
  int local_34;
  int *local_30;
  BSTR local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  BSTR local_1c;
  int *local_18;
  undefined1 local_11;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0;
  local_11 = 0;
  if (param_7 != (int *)0x0) {
    CComQIPtr<>(&param_7,param_7);
    if (param_7 != (int *)0x0) {
      CComQIPtr<>(&local_30,param_7);
      local_8._0_1_ = 2;
      FUN_42420b4b(&local_2c,(GUID *)&DAT_42496ecc);
      local_8._0_1_ = 3;
      (**(code **)(*param_7 + 0x74))(param_7,local_2c);
      local_20 = (int *)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*param_7 + 0x5c))(param_7,&local_20);
      (**(code **)(*param_7 + 0x6c))(param_7,L"FixedText");
      if (local_20 != (int *)0x0) {
        FUN_42403802((uint *)&local_44);
        local_8._0_1_ = 5;
        (**(code **)(*local_20 + 0x28))(local_20,0,0,1,0,&local_44);
        CComQIPtr<>(&local_18,(undefined4 *)local_44.n1._8_4_);
        local_8._0_1_ = 6;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 0x54))(local_18,0);
          puVar2 = FUN_4245a2d5(&local_34,0x600f);
          local_8._0_1_ = 7;
          FUN_424037d2(&local_1c,(OLECHAR *)*puVar2);
          local_8._0_1_ = 9;
          FUN_42403ad1(&local_34);
          piVar1 = local_18;
          UVar3 = SysStringLen(local_1c);
          (**(code **)(*piVar1 + 0x98))(piVar1,UVar3);
          (**(code **)(*local_18 + 0x5c))(local_18,local_1c);
          (**(code **)(*local_18 + 100))(local_18,local_1c);
          (**(code **)(*param_7 + 0xac))(param_7,param_1);
          local_24 = 1;
          CComQIPtr<>(&local_28,param_5);
          local_8 = CONCAT31(local_8._1_3_,10);
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 0x3b4))(local_28,&local_24);
          }
          (**(code **)(*param_7 + 0xb4))(param_7,local_24 * param_2);
          if (local_30 != (int *)0x0) {
            (**(code **)(*local_30 + 0x16c))(local_30,local_24);
          }
          local_11 = 1;
          local_8._0_1_ = 9;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
          SysFreeString(local_1c);
        }
        local_8._0_1_ = 5;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        VariantClear(&local_44);
      }
      local_8._0_1_ = 3;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      SysFreeString(local_2c);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 8))(local_30);
      }
    }
    local_8 = local_8 & 0xffffff00;
    if (param_7 != (int *)0x0) {
      (**(code **)(*param_7 + 8))(param_7);
    }
  }
  SysFreeString(param_1);
  return local_11;
}


