// Source: CLCSTextBasedField.dll @ 4244ee4d; FUN_4244ee4d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_4244ee4d(void *param_1)

{
  void *this;
  bool bVar1;
  WPARAM WVar2;
  undefined4 *puVar3;
  OLECHAR *pOVar4;
  LRESULT LVar5;
  int iVar6;
  BSTR extraout_ECX;
  BSTR pOVar7;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  code *pcVar8;
  OLECHAR *pOVar9;
  LPCWSTR *ppWVar10;
  OLECHAR **ppOVar11;
  int *piVar12;
  uint *puVar13;
  uint uVar14;
  undefined4 local_bc [18];
  VARIANTARG local_74;
  _union_2683 local_64;
  int *local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  OLECHAR *local_40;
  int local_3c;
  int local_38;
  LPCWSTR local_34;
  uint local_30;
  int local_2c;
  BSTR local_28;
  int *local_24;
  BSTR local_20;
  OLECHAR *local_1c;
  int *local_18;
  OLECHAR *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_40 = (OLECHAR *)PTR_DAT_424b9014;
  ppOVar11 = &local_40;
  local_8 = 0;
  WVar2 = SendMessageW(*(HWND *)((int)param_1 + 0x150),0x147,0,0);
  FUN_42409978((undefined4 *)((int)param_1 + 0x150),WVar2,ppOVar11);
  local_44 = 0;
  (**(code **)(**(int **)((int)param_1 + 0x168) + 0x184))();
  if (local_44 == 1) {
    FUN_4244ec50(&DAT_424bfaec,&local_40);
  }
  local_4c = 0;
  CComQIPtr<>(&local_50,*(undefined4 **)((int)param_1 + 0x160));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 0x124))();
  }
  local_48 = 0;
  if (*(int *)((int)param_1 + 0x168) != 0) {
    (**(code **)(**(int **)((int)param_1 + 0x168) + 0x29c))();
  }
  if ((local_4c == 2) && (local_48 == 1)) goto LAB_4244f365;
  FUN_42403802((uint *)&local_74);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)param_1 + 0x168) + 0x474))();
  CComQIPtr<>(&local_24,(undefined4 *)local_74.n1._8_4_);
  FUN_42403802((uint *)&local_64);
  piVar12 = local_24;
  local_8._0_1_ = 4;
  puVar3 = FUN_424037d2(&local_28,local_40);
  local_8._0_1_ = 5;
  (**(code **)(*piVar12 + 0x30))(piVar12,*puVar3);
  SysFreeString(local_28);
  if (local_64.n2.vt != 0) {
    CComQIPtr<>(&local_18,(undefined4 *)local_64._8_4_);
    local_8._0_1_ = 6;
    local_2c = 0;
    (**(code **)(*local_18 + 0x74))();
    local_38 = 0;
    (**(code **)(*local_18 + 0x6c))(local_18);
    local_20 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,7);
    (**(code **)(*local_18 + 0x9c))(local_18,&local_20);
    bVar1 = FUN_42403bfa(&local_20,L"TrueType");
    pcVar8 = EnableWindow_exref;
    if (bVar1) {
      EnableWindow(*(HWND *)((int)param_1 + 0x144),1);
      EnableWindow(*(HWND *)((int)param_1 + 0x148),1);
      if ((0 < local_38) && (0 < local_2c)) {
        if (local_2c == local_38) {
          EnableWindow(*(HWND *)((int)param_1 + 0x144),0);
        }
        FUN_42450ccc((int)param_1);
        local_3c = 1;
        if (*(int *)((int)param_1 + 0x168) != 0) {
          (**(code **)(**(int **)((int)param_1 + 0x168) + 0x3b4))();
        }
        FUN_42450d96((int)param_1);
      }
      local_14 = (OLECHAR *)0xffffffff;
      local_1c = (OLECHAR *)0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 0xcc))();
        (**(code **)(*local_18 + 0xd4))(local_18);
        if (((-1 < (int)local_14) && (-1 < (int)local_1c)) && (local_14 == local_1c)) {
          SetDlgItemInt(*(HWND *)((int)param_1 + 0x30),0xe6,(UINT)local_14,0);
          EnableWindow(*(HWND *)((int)param_1 + 0x148),0);
        }
        pOVar4 = (OLECHAR *)GetDlgItemInt(*(HWND *)((int)param_1 + 0x30),0xe6,(BOOL *)0x0,0);
        pOVar9 = local_14;
        if (-1 < (int)local_14) {
          if ((int)pOVar4 < (int)local_14) {
            SetDlgItemInt(*(HWND *)((int)param_1 + 0x30),0xe6,(UINT)local_14,0);
            pOVar4 = pOVar9;
          }
          pOVar9 = local_1c;
          if ((int)local_1c < (int)pOVar4) goto LAB_4244f20d;
        }
      }
    }
    else {
      local_14 = (OLECHAR *)0x0;
      (**(code **)(*local_18 + 0x3c))();
      local_3c = 1;
      if (*(int *)((int)param_1 + 0x168) != 0) {
        (**(code **)(**(int **)((int)param_1 + 0x168) + 0x3b4))();
      }
      pcVar8 = EnableWindow_exref;
      local_1c = (OLECHAR *)(local_3c * (int)local_1c);
      EnableWindow(*(HWND *)((int)param_1 + 0x144),0);
      FUN_42450d96((int)param_1);
      bVar1 = FUN_42403bfa(&local_20,L"ZFBF");
      if ((((bVar1) && (local_18 != (int *)0x0)) &&
          ((**(code **)(*local_18 + 0xfc))(), local_14 != (OLECHAR *)0x0)) &&
         ((EnableWindow(*(HWND *)((int)param_1 + 0x144),1), 0 < local_38 && (0 < local_2c)))) {
        if (local_2c == local_38) {
          EnableWindow(*(HWND *)((int)param_1 + 0x144),0);
        }
        else {
          FUN_42450ccc((int)param_1);
          local_28 = (BSTR)0x1;
          if (*(int *)((int)param_1 + 0x168) != 0) {
            (**(code **)(**(int **)((int)param_1 + 0x168) + 0x3b4))();
          }
          FUN_42450d96((int)param_1);
        }
      }
      EnableWindow(*(HWND *)((int)param_1 + 0x148),0);
      pOVar9 = (OLECHAR *)0x64;
LAB_4244f20d:
      SetDlgItemInt(*(HWND *)((int)param_1 + 0x30),0xe6,(UINT)pOVar9,0);
    }
    local_30 = 1;
    if ((local_18 == (int *)0x0) || ((**(code **)(*local_18 + 0xbc))(), local_30 != 0)) {
LAB_4244f262:
      bVar1 = FUN_4244ece4((int)param_1);
      if (!bVar1) {
        (**(code **)(*local_18 + 0x4c))();
        if (local_28 == (BSTR)0x0) {
          (*pcVar8)(*(undefined4 *)((int)param_1 + 0x154));
        }
        else {
          (*pcVar8)(*(undefined4 *)((int)param_1 + 0x154));
          SendMessageW(*(HWND *)((int)param_1 + 0x154),0xf1,1,0);
        }
      }
    }
    else {
      (*pcVar8)();
      SendMessageW(*(HWND *)((int)param_1 + 0x154),0xf1,0,0);
      if (local_30 != 0) goto LAB_4244f262;
    }
    if (local_18 != (int *)0x0) {
      local_14 = (OLECHAR *)0x1;
      (**(code **)(*local_18 + 0xe4))();
      ShowWindow(*(HWND *)((int)param_1 + 0x1d4),(uint)(1 < (int)local_14));
      (*pcVar8)(*(undefined4 *)((int)param_1 + 0x1d4));
      ShowWindow(*(HWND *)((int)param_1 + 0x1d8),(uint)(1 < (int)local_14));
      (*pcVar8)(*(undefined4 *)((int)param_1 + 0x1d8),1 < (int)local_14);
      if (1 < (int)local_14) {
        FUN_4244f83b(param_1,(int)local_14);
      }
    }
    SysFreeString(local_20);
    local_8._0_1_ = 4;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
  }
  VariantClear((VARIANTARG *)&local_64.n2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))();
  }
  VariantClear(&local_74);
LAB_4244f365:
  CComQIPtr<>(&local_54,*(undefined4 **)((int)param_1 + 0x160));
  local_1c = (OLECHAR *)PTR_DAT_424b9014;
  ppOVar11 = &local_1c;
  local_8._0_1_ = 9;
  WVar2 = SendMessageW(*(HWND *)((int)param_1 + 0x150),0x147,0,0);
  FUN_42409978((undefined4 *)((int)param_1 + 0x150),WVar2,ppOVar11);
  FUN_424037d2(&local_34,local_1c);
  piVar12 = *(int **)((int)param_1 + 0x168);
  local_8._0_1_ = 10;
  pOVar7 = (BSTR)0x0;
  local_24 = (int *)&stack0xffffff28;
  if (piVar12 != (int *)0x0) {
    local_24 = (int *)&stack0xffffff28;
    (**(code **)(*piVar12 + 4))();
    pOVar7 = extraout_ECX;
  }
  ppWVar10 = &local_34;
  local_8._0_1_ = 0xb;
  FUN_42403768(&stack0xffffff20,(int *)ppWVar10);
  this = (void *)((int)param_1 + 0x6c);
  local_8._0_1_ = 10;
  FUN_4245aeba(pOVar7,ppWVar10,piVar12);
  LVar5 = SendMessageW(*(HWND *)((int)param_1 + 0x1b8),0xf0,0,0);
  if (LVar5 == 0) {
    puVar3 = FUN_4240391a(&local_24,local_34);
    local_8._0_1_ = 0xe;
    FUN_4245ac12(this,puVar3);
    local_8 = CONCAT31(local_8._1_3_,10);
    FUN_42403ad1((int *)&local_24);
    iVar6 = FUN_4244ec23((int)param_1);
    if (0 < iVar6) {
      FUN_4245acfa(this,iVar6);
    }
  }
  else {
    FUN_42467b8d(local_bc);
    puVar13 = &local_30;
    local_8._0_1_ = 0xc;
    local_30 = 0;
    pOVar7 = extraout_ECX_00;
    FUN_42403768(&stack0xffffff24,(int *)&local_34);
    FUN_42467f17(local_bc,pOVar7,puVar13);
    FUN_424038c5(&local_20,"");
    local_8._0_1_ = 0xd;
    FUN_424054a8(&local_20,L"%d");
    SetWindowTextW(*(HWND *)((int)param_1 + 0x1c8),local_20);
    pOVar7 = extraout_ECX_01;
    uVar14 = local_30;
    FUN_42403768(&stack0xffffff24,(int *)&local_34);
    FUN_4245ae83(this,pOVar7,uVar14);
    FUN_42403ad1((int *)&local_20);
    local_8 = CONCAT31(local_8._1_3_,10);
    FUN_42467c23(local_bc);
  }
  InvalidateRect(*(HWND *)((int)param_1 + 0x70),(RECT *)0x0,1);
  FUN_4244f6ba(param_1);
  SysFreeString(local_34);
  FUN_42403ad1((int *)&local_1c);
  local_8._0_1_ = 1;
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_50 != (int *)0x0) {
    (**(code **)(*local_50 + 8))();
  }
  FUN_42403ad1((int *)&local_40);
  return 0;
}


