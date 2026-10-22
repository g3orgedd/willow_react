// Source: CiffMgr.dll @ 68122545; FUN_68122545

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

DWORD __thiscall FUN_68122545(void *this,int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  DWORD DVar3;
  int iVar4;
  DWORD DVar5;
  UINT UVar6;
  DWORD DVar7;
  undefined4 bstrString;
  _union_2683 local_48;
  DWORD local_38;
  BSTR local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  BSTR local_20;
  void *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x68122551;
  local_1c = this;
  do {
    local_38 = GetTickCount();
    local_18 = (int *)0x0;
    local_8 = 0;
    DVar3 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_18);
    if ((DVar3 == 0) && (local_18 != (int *)0x0)) {
      local_2c = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = (**(code **)(*local_18 + 0x44))(local_18,&local_2c);
      bstrString = (BSTR)0x0;
      local_20 = (BSTR)0x0;
      if ((-1 < iVar4) && (local_2c != (int *)0x0)) {
        local_30 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,3);
        iVar4 = (**(code **)(*local_2c + 0x1c))(local_2c,PTR_u_ImageReference_68160044,&local_30);
        if ((iVar4 < 0) || (local_30 == (int *)0x0)) {
          FUN_68102644(&local_20,L"1");
          bstrString = local_20;
        }
        else {
          (**(code **)(*local_30 + 0x20))(local_30,&local_48);
          uVar1 = local_48._8_4_;
          if (((local_48.n2.vt == 8) && ((BSTR)local_48._8_4_ != (BSTR)0x0)) &&
             (*(OLECHAR *)local_48._8_4_ != L'\0')) {
            SysFreeString((BSTR)0x0);
            local_20 = (BSTR)uVar1;
            local_48.n2.vt = 0;
            bstrString = uVar1;
          }
          else {
            VariantClear((VARIANTARG *)&local_48.n2);
          }
        }
        local_8._0_1_ = 2;
        if (local_30 != (int *)0x0) {
          (**(code **)(*local_30 + 8))(local_30);
        }
      }
      local_14[0] = (int *)0x0;
      local_8._0_1_ = 4;
      DVar5 = (**(code **)(*local_18 + 0x90))(local_18,PTR_u_Field_6815fcd8,local_14);
      if ((int)DVar5 < 0) {
LAB_6812276a:
        DVar3 = DVar5;
      }
      else {
        if (local_14[0] != (int *)0x0) {
          local_34 = (BSTR)0x0;
          iVar4 = (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_34);
          local_28 = (int *)0x0;
          local_8._0_1_ = 5;
          uVar2 = (undefined1)local_8;
          local_8._0_1_ = 5;
          if ((iVar4 == 0) &&
             (UVar6 = SysStringLen((BSTR)bstrString), uVar2 = (undefined1)local_8, UVar6 != 0)) {
            local_24 = (int *)0x0;
            local_8._0_1_ = 6;
            DVar5 = (**(code **)(*local_18 + 0x94))(local_18,PTR_u_SubHeader_6815fcb4,&local_24);
            if (DVar5 == 0) {
              if (local_24 != (int *)0x0) {
                DVar5 = FUN_68121a2a(param_1,(CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
                                              *)&local_28,(BSTR)&local_24,(int *)&local_20,local_34)
                ;
                local_8._0_1_ = 5;
                if (local_24 != (int *)0x0) {
                  (**(code **)(*local_24 + 8))(local_24);
                }
                goto LAB_681226f5;
              }
            }
            else if ((DVar5 != 1) && (local_24 != (int *)0x0)) goto LAB_681227cc;
            DVar5 = 0x80030104;
LAB_681227cc:
            local_8._0_1_ = 5;
            if (local_24 != (int *)0x0) {
              (**(code **)(*local_24 + 8))(local_24);
            }
            local_8._0_1_ = 4;
            if (local_28 != (int *)0x0) {
              (**(code **)(*local_28 + 8))(local_28);
            }
            local_8._0_1_ = 2;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            SysFreeString((BSTR)bstrString);
            local_8 = (uint)local_8._1_3_ << 8;
            if (local_2c != (int *)0x0) {
              (**(code **)(*local_2c + 8))(local_2c);
            }
            local_8 = 0xffffffff;
            if (local_18 == (int *)0x0) {
              return DVar5;
            }
            (**(code **)(*local_18 + 8))(local_18);
            return DVar5;
          }
          local_8._0_1_ = uVar2;
          DVar5 = 0x80030104;
LAB_681226f5:
          DVar7 = GetTickCount();
          *(int *)((int)local_1c + 0xb28) = *(int *)((int)local_1c + 0xb28) + (DVar7 - local_38);
          local_38 = GetTickCount();
          if (-1 < (int)DVar5) {
            DVar5 = GetTickCount();
            *(int *)((int)local_1c + 0xb2c) = *(int *)((int)local_1c + 0xb2c) + (DVar5 - local_38);
            DVar5 = GetTickCount();
            local_38 = FUN_6811e012(local_1c,local_28,local_14);
            DVar7 = GetTickCount();
            *(int *)((int)local_1c + 0xb30) = *(int *)((int)local_1c + 0xb30) + (DVar7 - DVar5);
            DVar5 = local_38;
          }
          local_8._0_1_ = 4;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
        if ((int)DVar5 < 0) goto LAB_6812276a;
      }
      local_8._0_1_ = 2;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      SysFreeString((BSTR)bstrString);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
      }
    }
    local_8 = 0xffffffff;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    if (DVar3 != 0) {
      if (DVar3 == 1) {
        DVar3 = 0;
      }
      return DVar3;
    }
  } while( true );
}


