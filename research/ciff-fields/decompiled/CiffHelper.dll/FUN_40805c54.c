// Source: CiffHelper.dll @ 40805c54; FUN_40805c54

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __cdecl FUN_40805c54(undefined4 *param_1,BSTR param_2)

{
  HRESULT HVar1;
  VARIANTARG *pVVar2;
  undefined1 uVar3;
  code *pcVar4;
  code *pcVar5;
  uint local_8c [2];
  undefined4 *local_84;
  VARIANTARG local_7c;
  VARIANTARG local_6c;
  VARIANTARG local_5c;
  int local_4c;
  int *local_48;
  BSTR local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  uVar3 = 0;
  local_8 = 0;
  FUN_40802e76(local_8c);
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_8c);
  CComQIPtr<>(&local_48,local_84);
  local_28 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(*local_48 + 0x1c))(local_48,&local_28);
  pcVar5 = SysFreeString_exref;
  local_24 = (int *)0x0;
  pcVar4 = VariantClear_exref;
  if (0 < local_28) {
    do {
      FUN_40802e76((uint *)&local_5c);
      local_24 = (int *)((int)local_24 + 1);
      local_8._0_1_ = 3;
      (**(code **)(*local_48 + 0x30))(local_48,local_24,&local_5c);
      CComQIPtr<>(&local_20,(undefined4 *)local_5c.n1._8_4_);
      local_14[0] = (BSTR)0x0;
      local_8._0_1_ = 5;
      (**(code **)(*local_20 + 0xbc))(local_20,local_14);
      HVar1 = VarBstrCmp(local_14[0],param_2,0x400,0);
      pcVar4 = VariantClear_exref;
      if (HVar1 == 1) {
        SysFreeString(local_14[0]);
        local_8 = CONCAT31(local_8._1_3_,3);
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
        }
        pVVar2 = &local_5c;
LAB_40805fa9:
        (*pcVar4)(pVVar2);
        uVar3 = 1;
        goto LAB_40805fae;
      }
      SysFreeString(local_14[0]);
      local_8._0_1_ = 3;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      VariantClear(&local_5c);
    } while ((int)local_24 < local_28);
  }
  local_40 = 0;
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_40);
  local_3c = 0;
  if (0 < local_40) {
    do {
      FUN_40802e76((uint *)&local_7c);
      local_3c = local_3c + 1;
      local_8._0_1_ = 6;
      (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,local_3c,&local_7c);
      CComQIPtr<>(&local_24,(undefined4 *)local_7c.n1._8_4_);
      local_38 = 0;
      local_8 = CONCAT31(local_8._1_3_,7);
      (**(code **)(*local_24 + 0x1c))(local_24,&local_38);
      local_34 = 0;
      pcVar4 = VariantClear_exref;
      if (0 < local_38) {
        do {
          FUN_40802e76((uint *)&local_6c);
          local_34 = local_34 + 1;
          local_8._0_1_ = 8;
          (**(code **)(*local_24 + 0x24))(local_24,local_34,&local_6c);
          CComQIPtr<>(&local_20,(undefined4 *)local_6c.n1._8_4_);
          local_44 = (BSTR)0x0;
          local_8._0_1_ = 10;
          (**(code **)(*local_20 + 0x68))(local_20,&local_44);
          local_14[0] = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xb);
          (**(code **)(*local_20 + 0x5c))(local_20,local_14);
          local_30 = 0;
          (**(code **)(*(int *)local_14[0] + 0x1c))(local_14[0],&local_30);
          pcVar5 = SysFreeString_exref;
          local_2c = 0;
          if (0 < local_30) {
            do {
              FUN_40802e76((uint *)&local_5c);
              local_2c = local_2c + 1;
              local_8._0_1_ = 0xc;
              (**(code **)(*(int *)local_14[0] + 0x24))(local_14[0],local_2c,&local_5c);
              CComQIPtr<>(&local_1c,(undefined4 *)local_5c.n1._8_4_);
              local_8._0_1_ = 0xd;
              (**(code **)(*local_1c + 0x28))(local_1c,&local_4c);
              pcVar4 = VariantClear_exref;
              if (local_4c == 4) {
                local_18 = (BSTR)0x0;
                local_8._0_1_ = 0xe;
                (**(code **)(*local_1c + 0xb4))(local_1c,&local_18);
                HVar1 = VarBstrCmp(local_18,param_2,0x400,0);
                if (HVar1 == 1) {
                  SysFreeString(local_18);
                  local_8._0_1_ = 0xc;
                  if (local_1c != (int *)0x0) {
                    (**(code **)(*local_1c + 8))(local_1c);
                  }
                  VariantClear(&local_5c);
                  local_8._0_1_ = 10;
                  if (local_14[0] != (BSTR)0x0) {
                    (**(code **)(*(int *)local_14[0] + 8))(local_14[0]);
                  }
                  SysFreeString(local_44);
                  local_8._0_1_ = 8;
                  if (local_20 != (int *)0x0) {
                    (**(code **)(*local_20 + 8))(local_20);
                  }
                  VariantClear(&local_6c);
                  local_8 = CONCAT31(local_8._1_3_,6);
                  if (local_24 != (int *)0x0) {
                    (**(code **)(*local_24 + 8))(local_24);
                  }
                  pVVar2 = &local_7c;
                  goto LAB_40805fa9;
                }
                SysFreeString(local_18);
              }
              local_8 = CONCAT31(local_8._1_3_,0xc);
              if (local_1c != (int *)0x0) {
                (**(code **)(*local_1c + 8))(local_1c);
              }
              VariantClear(&local_5c);
            } while (local_2c < local_30);
          }
          local_8._0_1_ = 10;
          if (local_14[0] != (BSTR)0x0) {
            (**(code **)(*(int *)local_14[0] + 8))(local_14[0]);
          }
          SysFreeString(local_44);
          local_8 = CONCAT31(local_8._1_3_,8);
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          (*pcVar4)(&local_6c);
        } while (local_34 < local_38);
      }
      local_8 = CONCAT31(local_8._1_3_,6);
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 8))(local_24);
      }
      (*pcVar4)(&local_7c);
    } while (local_3c < local_40);
  }
LAB_40805fae:
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_48 != (int *)0x0) {
    (**(code **)(*local_48 + 8))(local_48);
  }
  (*pcVar4)(local_8c);
  (*pcVar5)(param_2);
  return uVar3;
}


