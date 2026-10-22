// Source: CLCSTextBasedField.dll @ 424504b4; FUN_424504b4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_424504b4(void *this,int *param_1)

{
  undefined4 *this_00;
  wchar_t *pwVar1;
  bool bVar2;
  LRESULT LVar3;
  HRESULT HVar4;
  wchar_t *pwVar5;
  int iVar6;
  WPARAM wParam;
  uint bEnable;
  BOOL bEnable_00;
  VARIANTARG local_8c;
  _union_2683 local_7c;
  int local_6c;
  int local_68;
  int *local_64;
  int local_60;
  int local_5c;
  UINT local_58;
  UINT local_54 [3];
  wchar_t *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int *local_38;
  wchar_t *local_34;
  int local_30;
  BSTR local_2c;
  BSTR local_28;
  LPCWSTR local_24;
  BSTR local_20;
  wchar_t *local_1c;
  wchar_t *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_28 = (BSTR)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xa8))(param_1,&local_28);
  }
  local_24 = (LPCWSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(**(int **)((int)this + 0x168) + 0x184))(*(int **)((int)this + 0x168),&local_68);
  local_3c = 0;
  if (*(int *)((int)this + 0x168) != 0) {
    (**(code **)(**(int **)((int)this + 0x168) + 0x29c))(*(int **)((int)this + 0x168),&local_3c);
  }
  LVar3 = SendMessageW(*(HWND *)((int)this + 0x1b8),0xf0,0,0);
  if ((LVar3 == 1) && (local_3c == 1)) {
    FUN_4244e18c(this);
    FUN_42403b34(&local_24,(int *)&local_28);
  }
  else {
    ShowWindow(*(HWND *)((int)this + 0x144),1);
    ShowWindow(*(HWND *)((int)this + 0x148),1);
    ShowWindow(*(HWND *)((int)this + 0x14c),1);
    ShowWindow(*(HWND *)((int)this + 0x58),1);
    ShowWindow(*(HWND *)((int)this + 0x5c),1);
    ShowWindow(*(HWND *)((int)this + 0x60),1);
    if (local_68 == 0) {
      FUN_42403802((uint *)&local_8c);
      local_8._0_1_ = 3;
      (**(code **)(**(int **)((int)this + 0x168) + 0x474))(*(int **)((int)this + 0x168),&local_8c);
      CComQIPtr<>(&local_38,(undefined4 *)local_8c.n1._8_4_);
      local_8._0_1_ = 4;
      (**(code **)(*local_38 + 0x24))(local_38,&local_40);
      iVar6 = 0;
      if (0 < local_40) {
        do {
          FUN_42403802((uint *)&local_7c);
          iVar6 = iVar6 + 1;
          local_8._0_1_ = 5;
          (**(code **)(*local_38 + 0x20))(local_38,iVar6,&local_7c);
          if (local_7c.n2.vt != 0) {
            CComQIPtr<>(local_14,(undefined4 *)local_7c._8_4_);
            local_2c = (BSTR)0x0;
            local_8._0_1_ = 7;
            (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_2c);
            HVar4 = VarBstrCmp(local_2c,local_28,0x400,0);
            if (HVar4 == 1) {
              (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_24);
              local_20 = (BSTR)0x0;
              local_8 = CONCAT31(local_8._1_3_,8);
              (**(code **)(*local_14[0] + 0x9c))(local_14[0],&local_20);
              local_44 = 0;
              bVar2 = FUN_42403bfa(&local_20,L"ZFBF");
              if ((bVar2) && (local_14[0] != (int *)0x0)) {
                (**(code **)(*local_14[0] + 0xfc))(local_14[0],&local_44);
              }
              bVar2 = FUN_42403bfa(&local_20,L"TrueType");
              if ((bVar2) || (local_44 != 0)) {
                local_18 = (wchar_t *)0x0;
                (**(code **)(*local_14[0] + 0x74))(local_14[0],&local_18);
                local_48 = (wchar_t *)0x0;
                (**(code **)(*local_14[0] + 0x6c))(local_14[0],&local_48);
                if ((local_18 == local_48) && ((0 < (int)local_18 && (0 < (int)local_48)))) {
                  bEnable_00 = 0;
                }
                else {
                  bEnable_00 = 1;
                }
                EnableWindow(*(HWND *)((int)this + 0x144),bEnable_00);
                bVar2 = FUN_42403bfa(&local_20,L"TrueType");
                bEnable = (uint)bVar2;
              }
              else {
                EnableWindow(*(HWND *)((int)this + 0x144),0);
                bEnable = 0;
              }
              EnableWindow(*(HWND *)((int)this + 0x148),bEnable);
              local_30 = 1;
              if ((local_14[0] == (int *)0x0) ||
                 ((**(code **)(*local_14[0] + 0xbc))(local_14[0],&local_30), local_30 != 0)) {
LAB_4245077c:
                bVar2 = FUN_4244ece4((int)this);
                if (!bVar2) {
                  (**(code **)(*local_14[0] + 0x4c))(local_14[0],&local_48);
                  if (local_48 == (wchar_t *)0x0) {
                    EnableWindow(*(HWND *)((int)this + 0x154),1);
                  }
                  else {
                    SendMessageW(*(HWND *)((int)this + 0x154),0xf1,1,0);
                    EnableWindow(*(HWND *)((int)this + 0x154),0);
                    if (param_1 != (int *)0x0) {
                      (**(code **)(*param_1 + 0xc4))(param_1,local_48);
                    }
                  }
                }
              }
              else {
                EnableWindow(*(HWND *)((int)this + 0x154),0);
                SendMessageW(*(HWND *)((int)this + 0x154),0xf1,0,0);
                if (local_30 != 0) goto LAB_4245077c;
              }
              local_1c = (wchar_t *)0xffffffff;
              local_34 = (wchar_t *)0xffffffff;
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 0xcc))(local_14[0],&local_1c);
                (**(code **)(*local_14[0] + 0xd4))(local_14[0],&local_34);
                if (((-1 < (int)local_1c) && (-1 < (int)local_34)) && (local_1c == local_34)) {
                  SetDlgItemInt(*(HWND *)((int)this + 0x148),0xe6,(UINT)local_1c,0);
                  EnableWindow(*(HWND *)((int)this + 0x148),0);
                  if (param_1 != (int *)0x0) {
                    (**(code **)(*param_1 + 0xbc))(param_1,local_1c);
                  }
                }
                pwVar5 = (wchar_t *)GetDlgItemInt(*(HWND *)((int)this + 0x30),0xe6,(BOOL *)0x0,0);
                pwVar1 = local_1c;
                if (-1 < (int)local_1c) {
                  if (((int)pwVar5 < (int)local_1c) &&
                     (SetDlgItemInt(*(HWND *)((int)this + 0x30),0xe6,(UINT)local_1c,0),
                     pwVar5 = pwVar1, param_1 != (int *)0x0)) {
                    (**(code **)(*param_1 + 0xbc))(param_1,pwVar1);
                  }
                  local_48 = local_34;
                  if (((int)local_34 < (int)pwVar5) &&
                     (SetDlgItemInt(*(HWND *)((int)this + 0x30),0xe6,(UINT)local_34,0),
                     param_1 != (int *)0x0)) {
                    (**(code **)(*param_1 + 0xbc))(param_1,local_48);
                  }
                }
                if (local_14[0] != (int *)0x0) {
                  local_18 = (wchar_t *)0x1;
                  (**(code **)(*local_14[0] + 0xe4))(local_14[0],&local_18);
                  ShowWindow(*(HWND *)((int)this + 0x1d4),(uint)(1 < (int)local_18));
                  EnableWindow(*(HWND *)((int)this + 0x1d4),(uint)(1 < (int)local_18));
                  ShowWindow(*(HWND *)((int)this + 0x1d8),(uint)(1 < (int)local_18));
                  EnableWindow(*(HWND *)((int)this + 0x1d8),(uint)(1 < (int)local_18));
                  if (1 < (int)local_18) {
                    FUN_4244f83b(this,(int)local_18);
                  }
                }
              }
              SysFreeString(local_20);
              SysFreeString(local_2c);
              local_8._0_1_ = 5;
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 8))(local_14[0]);
              }
              VariantClear((VARIANTARG *)&local_7c.n2);
              break;
            }
            SysFreeString(local_2c);
            local_8._0_1_ = 5;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
          }
          VariantClear((VARIANTARG *)&local_7c.n2);
        } while (iVar6 < local_40);
      }
      local_8._0_1_ = 3;
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      VariantClear(&local_8c);
    }
    else {
      EnableWindow(*(HWND *)((int)this + 0x144),1);
      EnableWindow(*(HWND *)((int)this + 0x148),1);
      FUN_42403b34(&local_24,(int *)&local_28);
    }
  }
  FUN_4240391a(&local_34,local_24);
  local_54[2] = 0;
  local_8 = CONCAT31(local_8._1_3_,9);
  (**(code **)(**(int **)((int)this + 0x168) + 0x184))(*(int **)((int)this + 0x168),local_54 + 2);
  if (local_54[2] == 1) {
    FUN_42427fd5(&DAT_424bfaec,&local_34);
  }
  this_00 = (undefined4 *)((int)this + 0x150);
  local_48 = (wchar_t *)SendMessageW((HWND)*this_00,0x146,0,0);
  pwVar1 = local_34;
  local_38 = (int *)0x0;
  if (0 < (int)local_48) {
    do {
      local_2c = (BSTR)PTR_DAT_424b9014;
      local_8._0_1_ = 10;
      FUN_42409978(this_00,(WPARAM)local_38,&local_2c);
      iVar6 = _wcscmp(pwVar1,local_2c);
      if (iVar6 == 0) {
        SendMessageW((HWND)*this_00,0x14e,(WPARAM)local_38,0);
        local_8 = CONCAT31(local_8._1_3_,9);
        FUN_42403ad1((int *)&local_2c);
        goto LAB_42450aa8;
      }
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_42403ad1((int *)&local_2c);
      local_38 = (int *)((int)local_38 + 1);
    } while ((int)local_38 < (int)local_48);
  }
  if (*(int *)(pwVar1 + -4) == 0) {
    SendMessageW((HWND)*this_00,0x14e,0,0);
  }
  else {
    SendMessageW((HWND)*this_00,0x143,0,(LPARAM)pwVar1);
    wParam = SendMessageW((HWND)*this_00,0x158,0,(LPARAM)pwVar1);
    SendMessageW((HWND)*this_00,0x14e,wParam,0);
  }
LAB_42450aa8:
  local_54[0] = 0;
  local_58 = 0;
  local_54[1] = 0;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xb0))(param_1,local_54 + 1);
    (**(code **)(*param_1 + 0xb8))(param_1,local_54);
    (**(code **)(*param_1 + 0x11c))(param_1,&local_58);
  }
  FUN_42450d96((int)this);
  SetDlgItemInt(*(HWND *)((int)this + 0x30),0xe6,local_54[0],1);
  SetDlgItemInt(*(HWND *)((int)this + 0x30),0xe7,local_58,1);
  local_5c = 0;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0xc0))(param_1,&local_5c);
  }
  CheckDlgButton(*(HWND *)((int)this + 0x30),0xe9,(uint)(local_5c != 0));
  local_60 = 0;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x10c))(param_1,&local_60);
  }
  CheckDlgButton(*(HWND *)((int)this + 0x30),0xf1,(uint)(local_60 != 0));
  (**(code **)(**(int **)((int)this + 0x168) + 0x19c))(*(int **)((int)this + 0x168),&local_6c);
  EnableWindow(*(HWND *)((int)this + 0x158),(uint)(local_6c != 0));
  CComQIPtr<>(&local_64,*(undefined4 **)((int)this + 0x160));
  local_8._0_1_ = 0xb;
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 0x134))(local_64,&local_48);
    FUN_4244f5dc(this,local_48 == (wchar_t *)0x0);
  }
  FUN_4244e4ed(this);
  local_8 = CONCAT31(local_8._1_3_,9);
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 8))(local_64);
  }
  FUN_42403ad1((int *)&local_34);
  SysFreeString(local_24);
  SysFreeString(local_28);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return;
}


