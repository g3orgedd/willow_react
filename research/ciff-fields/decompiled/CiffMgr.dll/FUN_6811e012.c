// Source: CiffMgr.dll @ 6811e012; FUN_6811e012

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_6811e012(void *this,int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  void *this_00;
  uint uVar2;
  int iVar3;
  DWORD DVar4;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  undefined4 bstrString;
  _union_2683 local_84;
  _union_2683 local_74;
  _union_2683 local_64;
  int local_54;
  uint local_50;
  undefined4 local_4c;
  BSTR local_48;
  int local_44;
  DWORD local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  void *local_18;
  undefined1 local_11;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x6811e01e;
  if (param_1 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    local_54 = *(int *)((int)this + 0xb34);
    local_34 = 0;
    iVar7 = 0;
    local_44 = 0;
    local_18 = this;
    do {
      local_40 = GetTickCount();
      local_24 = (int *)0x0;
      local_8 = 0;
      uVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_24);
      local_50 = uVar2;
      if ((uVar2 == 0) && (local_24 != (int *)0x0)) {
        local_30 = (int *)0x0;
        local_8._0_1_ = 1;
        local_2c = (**(code **)(*local_24 + 0x44))(local_24,&local_30);
        bstrString = (BSTR)0x0;
        local_48 = (BSTR)0x0;
        local_8._0_1_ = 2;
        local_11 = 0;
        if ((-1 < (int)local_2c) && (local_30 != (int *)0x0)) {
          local_28 = (int *)0x0;
          local_8._0_1_ = 3;
          local_2c = (**(code **)(*local_30 + 0x1c))(local_30,PTR_u_Name_68160030,&local_28);
          if ((-1 < (int)local_2c) && (local_28 != (int *)0x0)) {
            local_2c = (**(code **)(*local_28 + 0x20))(local_28,&local_84);
            uVar1 = local_84._8_4_;
            if ((local_84.n2.vt == 8) &&
               (((BSTR)local_84._8_4_ != (BSTR)0x0 && (*(OLECHAR *)local_84._8_4_ != L'\0')))) {
              SysFreeString((BSTR)0x0);
              local_48 = (BSTR)uVar1;
              local_84.n2.vt = 0;
              bstrString = uVar1;
            }
            else {
              VariantClear((VARIANTARG *)&local_84.n2);
            }
            local_1c = (int *)0x0;
            local_8._0_1_ = 4;
            iVar3 = (**(code **)(*local_30 + 0x1c))(local_30,PTR_u_TXField_681600d0,&local_1c);
            if ((iVar3 == 0) && (local_1c != (int *)0x0)) {
              FUN_68132710((uint *)&local_74,0,0x10);
              VariantInit((VARIANTARG *)&local_74.n2);
              local_8._0_1_ = 5;
              local_2c = (**(code **)(*local_1c + 0x20))(local_1c,&local_74);
              if (local_74.n2.vt == 8) {
                iVar3 = FUN_6812e988((wchar_t *)local_74._8_4_);
                local_11 = iVar3 != 0;
              }
              VariantClear((VARIANTARG *)&local_74.n2);
            }
            local_8._0_1_ = 3;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
          }
          local_8._0_1_ = 2;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
        DVar4 = GetTickCount();
        *(int *)((int)local_18 + 0xb3c) = *(int *)((int)local_18 + 0xb3c) + (DVar4 - local_40);
        if ((local_2c == 0) && ((BSTR)bstrString != (BSTR)0x0)) {
          DVar4 = GetTickCount();
          iVar7 = FUN_68119d96((int *)&local_24,&local_4c);
          DVar5 = GetTickCount();
          *(int *)((int)local_18 + 0xb34) = *(int *)((int)local_18 + 0xb34) + (DVar5 - DVar4);
          FUN_68132710((uint *)&local_64,0,0x10);
          VariantInit((VARIANTARG *)&local_64.n2);
          local_8._0_1_ = 6;
          DVar4 = GetTickCount();
          local_2c = (**(code **)(*param_1 + 0x28))(param_1,iVar7,bstrString,local_4c,&local_64);
          DVar5 = GetTickCount();
          this_00 = local_18;
          *(int *)((int)local_18 + 0xb40) = *(int *)((int)local_18 + 0xb40) + (DVar5 - DVar4);
          if ((-1 < (int)local_2c) && (local_64.n2.vt == 9)) {
            CComQIPtr<>(&local_3c,(undefined4 *)local_64._8_4_);
            CComQIPtr<>(&local_38,(undefined4 *)local_64._8_4_);
            local_8._0_1_ = 8;
            if (local_38 != (int *)0x0) {
              (**(code **)(*local_38 + 0x18))(local_38,local_11);
            }
            local_20 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,9);
            local_2c = (**(code **)(*local_24 + 0x30))(local_24,&local_20);
            if ((-1 < (int)local_2c) && (local_20 != (int *)0x0)) {
              DVar4 = GetTickCount();
              local_2c = FUN_6811d9a6(this_00,local_3c,&local_20);
              DVar5 = GetTickCount();
              local_34 = local_34 + (DVar5 - DVar4);
            }
            local_8._0_1_ = 8;
            if (local_20 != (int *)0x0) {
              (**(code **)(*local_20 + 8))(local_20);
            }
            local_8._0_1_ = 7;
            if (local_38 != (int *)0x0) {
              (**(code **)(*local_38 + 8))(local_38);
            }
            local_8._0_1_ = 6;
            if (local_3c != (int *)0x0) {
              (**(code **)(*local_3c + 8))(local_3c);
            }
          }
          VariantClear((VARIANTARG *)&local_64.n2);
          uVar6 = local_2c;
          iVar7 = local_44;
          uVar2 = local_50;
        }
        else {
          uVar6 = 0x80030104;
        }
        if ((int)uVar6 < 0) {
          uVar2 = uVar6;
        }
        SysFreeString((BSTR)bstrString);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_30 != (int *)0x0) {
          (**(code **)(*local_30 + 8))(local_30);
        }
      }
      DVar4 = GetTickCount();
      local_8 = 0xffffffff;
      iVar7 = iVar7 + (DVar4 - local_40);
      local_44 = iVar7;
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 8))(local_24);
      }
    } while (uVar2 == 0);
    *(int *)((int)local_18 + 0xb38) =
         *(int *)((int)local_18 + 0xb38) +
         ((iVar7 - *(int *)((int)local_18 + 0xb34)) - local_34) + local_54;
    if (uVar2 == 1) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


