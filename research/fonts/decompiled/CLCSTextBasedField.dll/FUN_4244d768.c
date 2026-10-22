// Source: CLCSTextBasedField.dll @ 4244d768; FUN_4244d768

BSTR FUN_4244d768(int *param_1)

{
  int *this;
  bool bVar1;
  char cVar2;
  WPARAM WVar3;
  wchar_t *pwVar4;
  int iVar5;
  UINT UVar6;
  HRESULT HVar7;
  LRESULT LVar8;
  int iVar9;
  BSTR pOVar10;
  code *pcVar11;
  BSTR pOVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  HWND hWnd;
  wchar_t **ppwVar18;
  undefined4 local_d4 [18];
  _union_2683 local_8c;
  _union_2683 local_7c;
  int local_6c;
  _union_2683 local_68;
  VARIANTARG local_58;
  int local_48;
  int local_44;
  int local_40;
  OLECHAR *local_3c;
  int local_38;
  int local_34;
  BSTR local_30;
  BSTR local_2c;
  BSTR local_28;
  BSTR local_24;
  int local_20;
  BSTR local_1c;
  int local_18;
  char local_14;
  undefined3 uStack_13;
  wchar_t *local_10;
  wchar_t *local_c;
  BSTR local_8;
  
  this = param_1;
  pcVar11 = SendMessageW_exref;
  SendMessageW((HWND)param_1[0x78],0x40d,0,0);
  FUN_4244e4ed(this);
  local_1c = (BSTR)FUN_42450ccc((int)this);
  FUN_42450d96((int)this);
  local_30 = (BSTR)0x0;
  local_3c = (OLECHAR *)PTR_DAT_424b9014;
  WVar3 = SendMessageW((HWND)this[0x54],0x147,0,0);
  local_40 = 0;
  if (-1 < (int)WVar3) {
    FUN_42409978(this + 0x54,WVar3,&local_3c);
  }
  FUN_4244ec50(&DAT_424bfaec,&local_3c);
  FUN_42403b70(&local_30,local_3c);
  pwVar4 = (wchar_t *)GetDlgItemInt((HWND)this[0xc],0xe6,(BOOL *)0x0,0);
  local_48 = 0;
  local_10 = pwVar4;
  if (this[0x5a] != 0) {
    pwVar4 = (wchar_t *)(**(code **)(*(int *)this[0x5a] + 0x29c))((int *)this[0x5a],&local_48);
  }
  local_14 = local_48 == 0;
  local_18 = 3;
  local_20 = 0x9c4;
  uStack_13 = (undefined3)((uint)pwVar4 >> 8);
  if (local_48 == 0) {
    local_24 = (BSTR)0x1;
    (**(code **)(*(int *)this[0x5a] + 0x184))((int *)this[0x5a],&local_6c);
    if (this[0x5a] != 0) {
      (**(code **)(*(int *)this[0x5a] + 0x3b4))((int *)this[0x5a],&local_24);
    }
    if (local_6c == 0) {
      FUN_42403802((uint *)&local_68);
      (**(code **)(*(int *)this[0x5a] + 0x474))((int *)this[0x5a],&local_68);
      CComQIPtr<>(&local_c,(undefined4 *)local_68._8_4_);
      FUN_42403802((uint *)&local_58);
      pOVar12 = local_30;
      iVar5 = (**(code **)(*(int *)local_c + 0x30))(local_c,local_30,&local_58);
      if (iVar5 < 0) {
        pOVar10 = (BSTR)0x80004005;
      }
      else {
        CComQIPtr<>(&param_1,(undefined4 *)local_58.n1._8_4_);
        local_28 = (BSTR)0x0;
        (**(code **)(*param_1 + 0x9c))(param_1,&local_28);
        bVar1 = FUN_42403bfa(&local_28,L"TrueType");
        if (!bVar1) {
LAB_4244da03:
          bVar1 = FUN_42403bfa(&local_28,L"ZFBF");
          piVar13 = param_1;
          if ((bVar1) && (param_1 != (int *)0x0)) {
            (**(code **)(*param_1 + 4))(param_1);
            (**(code **)(*piVar13 + 0xfc))(piVar13,&local_40);
            if (local_40 != 0) {
              (**(code **)(*param_1 + 0x74))(param_1,&local_20);
              (**(code **)(*param_1 + 0x6c))(param_1,&local_18);
              if (((int)local_1c / (int)local_24 < local_18) ||
                 (local_20 < (int)local_1c / (int)local_24)) {
                FUN_4244e42d(this,local_18,local_20);
                SetFocus((HWND)this[0x51]);
                local_8 = (BSTR)0xffffffff;
                (**(code **)(*piVar13 + 8))(piVar13);
                pOVar10 = local_8;
                goto LAB_4244da97;
              }
            }
            (**(code **)(*piVar13 + 8))(piVar13);
          }
          local_2c = (BSTR)0x0;
          (**(code **)(*param_1 + 0x1c))(param_1,&local_2c);
          FUN_42403b34(&local_30,(int *)&local_2c);
          SysFreeString(local_2c);
          SysFreeString(local_28);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
          VariantClear(&local_58);
          if (local_c != (wchar_t *)0x0) {
            (**(code **)(*(int *)local_c + 8))(local_c);
          }
          VariantClear((VARIANTARG *)&local_68.n2);
          pcVar11 = SendMessageW_exref;
          goto LAB_4244db99;
        }
        (**(code **)(*param_1 + 0x74))(param_1,&local_20);
        (**(code **)(*param_1 + 0x6c))(param_1,&local_18);
        if (((int)local_1c / (int)local_24 < local_18) || (local_20 < (int)local_1c / (int)local_24)
           ) {
          FUN_4244e42d(this,local_18,local_20);
          hWnd = (HWND)this[0x51];
LAB_4244db24:
          SetFocus(hWnd);
          pOVar10 = (BSTR)0xffffffff;
        }
        else {
          local_34 = -1;
          local_38 = -1;
          local_8 = (BSTR)CONCAT31(local_8._1_3_,1);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 0xcc))(param_1,&local_34);
            (**(code **)(*param_1 + 0xd4))(param_1,&local_38);
            cVar2 = (char)local_8;
            if ((local_34 != -1) && ((int)local_10 < local_34)) {
              cVar2 = '\0';
            }
            if ((local_38 != -1) && (local_38 < (int)local_10)) {
              cVar2 = '\0';
            }
            if (cVar2 == '\0') {
              FUN_4244e42d(this,local_18,local_20);
              hWnd = (HWND)this[0x52];
              goto LAB_4244db24;
            }
          }
          local_8 = (BSTR)0x0;
          FUN_42409be8(this + 0x72,&local_8);
          pOVar10 = local_8;
          UVar6 = SysStringLen(local_8);
          if (UVar6 == 0) {
            local_8 = (BSTR)0x0;
          }
          else {
            local_8 = (BSTR)FUN_4246e5e6(pOVar10);
          }
          iVar5 = FUN_4244e153(this,(int)local_8);
          if ((iVar5 <= (int)local_8) && ((int)local_8 <= iVar5)) {
            SysFreeString(pOVar10);
            goto LAB_4244da03;
          }
          local_10 = (wchar_t *)0x0;
          local_8 = (BSTR)0x0;
          FUN_4244ebf6(this + 0x73,(int *)&local_10,(int *)&local_8);
          FUN_4244e36d(this,(int)local_10,local_8);
          SetFocus((HWND)this[0x72]);
          SysFreeString(pOVar10);
          pOVar10 = (BSTR)0xffffffff;
        }
LAB_4244da97:
        SysFreeString(local_28);
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      VariantClear(&local_58);
      if (local_c != (wchar_t *)0x0) {
        (**(code **)(*(int *)local_c + 8))(local_c);
      }
      VariantClear((VARIANTARG *)&local_68.n2);
      goto LAB_4244e139;
    }
    if (((int)local_1c / (int)local_24 < local_18) || (local_20 < (int)local_1c / (int)local_24)) {
      FUN_4244e42d(this,local_18,local_20);
      SetFocus((HWND)this[0x51]);
      pOVar10 = (BSTR)0xffffffff;
      pOVar12 = local_30;
      goto LAB_4244e139;
    }
  }
LAB_4244db99:
  pOVar12 = local_30;
  if (local_14 == '\0') {
    local_2c = (BSTR)0x0;
    (**(code **)(*(int *)this[0x59] + 0xa8))((int *)this[0x59],&local_2c);
    pOVar12 = local_30;
    HVar7 = VarBstrCmp(local_2c,local_30,0x400,0);
    if (HVar7 == 1) {
      local_8 = (BSTR)0x0;
      (**(code **)(*(int *)this[0x59] + 0xc0))((int *)this[0x59],&local_8);
      pOVar10 = (BSTR)(*pcVar11)(this[0x55],0xf0,0,0);
      if (local_8 == pOVar10) {
        CComQIPtr<>(&param_1,(undefined4 *)this[0x58]);
        if (param_1 != (int *)0x0) {
          FUN_424037d2(&local_c,L"999");
          WVar3 = (*pcVar11)(this[0x71],0x147,0,0);
          pwVar4 = local_c;
          SendMessageW((HWND)this[0x71],0x148,WVar3,(LPARAM)local_c);
          local_38 = 0;
          (**(code **)(*param_1 + 0x158))(param_1,&local_38);
          iVar5 = FUN_4246e5e6(pwVar4);
          if (local_38 == iVar5) {
            local_34 = 1;
            (**(code **)(*param_1 + 0x160))(param_1,&local_34);
            LVar8 = SendMessageW((HWND)this[0x76],0x147,0,0);
            if (local_34 != LVar8 + 1) goto LAB_4244dcdf;
            FUN_42409be8(this + 0x72,&local_c);
            pwVar4 = local_c;
            UVar6 = SysStringLen(local_c);
            if (UVar6 == 0) {
              local_24 = (BSTR)0x0;
            }
            else {
              local_24 = (BSTR)FUN_4246e5e6(pwVar4);
            }
            (**(code **)(*(int *)this[0x57] + 0x54))((int *)this[0x57],&local_44);
            if (local_44 == 0) {
              FUN_42458671(&local_c);
              piVar13 = (int *)this[0x5a];
              if (piVar13 != (int *)0x0) {
                (**(code **)(*piVar13 + 4))(piVar13);
              }
              local_24 = (BSTR)FUN_42459405((int)local_24,0.0,piVar13);
              FUN_42458752(&local_c);
            }
            local_28 = (BSTR)0x0;
            (**(code **)(*param_1 + 0x150))(param_1,&local_28);
            if (local_28 != local_24) {
              local_14 = '\x01';
            }
            uStack_13 = 0;
          }
          else {
LAB_4244dcdf:
            local_14 = '\x01';
          }
          SysFreeString(pwVar4);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
      }
      else {
        local_14 = '\x01';
      }
    }
    else {
      local_14 = '\x01';
    }
    SysFreeString(local_2c);
  }
  if (this[0x59] != 0) {
    (**(code **)(*(int *)this[0x59] + 0xac))((int *)this[0x59],pOVar12);
    (**(code **)(*(int *)this[0x59] + 0xb4))((int *)this[0x59],local_1c);
    iVar5 = 0;
    LVar8 = SendMessageW((HWND)this[0x55],0xf0,0,0);
    piVar13 = (int *)this[0x59];
    if (LVar8 == 0) {
      (**(code **)(*piVar13 + 0xc4))(piVar13,0);
      uVar14 = 1;
    }
    else {
      (**(code **)(*piVar13 + 0xc4))(piVar13,1);
      uVar14 = 2;
    }
    (**(code **)(*(int *)this[0x59] + 0x108))((int *)this[0x59],uVar14);
    LVar8 = SendMessageW((HWND)this[0x56],0xf0,0,0);
    (**(code **)(*(int *)this[0x59] + 0x110))((int *)this[0x59],LVar8 != 0);
    (**(code **)(*(int *)this[0x59] + 0xbc))((int *)this[0x59],local_10);
    UVar6 = GetDlgItemInt((HWND)this[0xc],0xe7,(BOOL *)0x0,0);
    (**(code **)(*(int *)this[0x59] + 0x120))((int *)this[0x59],UVar6);
    CComQIPtr<>(&local_c,(undefined4 *)this[0x58]);
    if (local_c != (wchar_t *)0x0) {
      (**(code **)(*(int *)local_c + 0x138))(local_c,*(char *)((int)this + 0x1e5) != '\x01');
    }
    CComQIPtr<>(&param_1,(undefined4 *)this[0x58]);
    local_8 = (BSTR)0x0;
    iVar9 = (**(code **)(*(int *)this[0x5a] + 0x354))((int *)this[0x5a],&local_8);
    if ((-1 < iVar9) && (local_8 != (BSTR)0x0)) {
      local_1c = (BSTR)0x0;
      FUN_42409be8(this + 0x72,&local_1c);
      UVar6 = SysStringLen(local_1c);
      if (UVar6 != 0) {
        iVar5 = FUN_4246e5e6(local_1c);
      }
      (**(code **)(*(int *)this[0x57] + 0x54))((int *)this[0x57],&local_44);
      if (local_44 == 0) {
        FUN_42458671(&local_10);
        piVar13 = (int *)this[0x5a];
        if (piVar13 != (int *)0x0) {
          (**(code **)(*piVar13 + 4))(piVar13);
        }
        iVar5 = FUN_42459405(iVar5,0.0,piVar13);
        FUN_42458752(&local_10);
      }
      (**(code **)(*param_1 + 0x154))(param_1,iVar5);
      SysFreeString(local_1c);
    }
    LVar8 = SendMessageW((HWND)this[0x6e],0xf0,0,0);
    piVar13 = (int *)this[0x59];
    if (LVar8 == 1) {
      (**(code **)(*piVar13 + 0x128))(piVar13,2);
      if (param_1 != (int *)0x0) {
        local_10 = (wchar_t *)PTR_DAT_424b9014;
        ppwVar18 = &local_10;
        WVar3 = SendMessageW((HWND)this[0x71],0x147,0,0);
        FUN_42409978(this + 0x71,WVar3,ppwVar18);
        if (*(int *)(local_10 + -4) == 0) {
          uVar14 = 0;
        }
        else {
          uVar14 = FUN_4246e5e6(local_10);
        }
        (**(code **)(*param_1 + 0x15c))(param_1,uVar14);
        LVar8 = SendMessageW((HWND)this[0x76],0x147,0,0);
        if (-1 < LVar8) {
          (**(code **)(*param_1 + 0x164))(param_1,LVar8 + 1);
        }
        if ((local_14 != '\0') && (local_40 == 0)) {
          local_8c._8_4_ = this[0x57];
          local_8c.n2.vt = 9;
          if ((int *)local_8c._8_4_ != (int *)0x0) {
            (**(code **)(*(int *)local_8c._8_4_ + 4))(local_8c._8_4_);
          }
          local_7c._8_4_ = this[0x5a];
          local_7c.n2.vt = 9;
          if ((int *)local_7c._8_4_ != (int *)0x0) {
            (**(code **)(*(int *)local_7c._8_4_ + 4))(local_7c._8_4_);
          }
          local_68.n2.vt = 9;
          local_68._8_4_ = param_1;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 4))(param_1);
          }
          FUN_42467b8d(local_d4);
          uVar14 = local_7c._0_4_;
          uVar15 = local_7c._8_4_;
          uVar16 = local_8c._0_4_;
          uVar17 = local_8c._8_4_;
          FUN_42467c7e(local_d4,(undefined1 *)((int)&local_58.n1 + 8),local_68._0_4_,
                       local_68.decVal.Hi32,(undefined4 *)local_68._8_4_);
          (**(code **)(*param_1 + 0x7c))
                    (param_1,local_58.n1._8_4_,local_68._12_4_,uVar14,local_7c.decVal.Hi32,uVar15,
                     local_7c._12_4_,uVar16,local_8c.decVal.Hi32,uVar17,local_8c._12_4_);
          (**(code **)(*param_1 + 0x84))(param_1,local_58.n1._12_4_);
          FUN_42467c23(local_d4);
          VariantClear((VARIANTARG *)&local_68.n2);
          VariantClear((VARIANTARG *)&local_7c.n2);
          VariantClear((VARIANTARG *)&local_8c.n2);
        }
        FUN_42403ad1((int *)&local_10);
        goto LAB_4244e0ff;
      }
    }
    else {
      (**(code **)(*piVar13 + 0x128))(piVar13,1);
LAB_4244e0ff:
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
    if (local_c != (wchar_t *)0x0) {
      (**(code **)(*(int *)local_c + 8))(local_c);
    }
  }
  pOVar10 = (BSTR)0x0;
  PostMessageW((HWND)this[0x78],0x402,0,0);
  FUN_42439cad(this,0);
  pOVar12 = local_30;
LAB_4244e139:
  FUN_42403ad1((int *)&local_3c);
  SysFreeString(pOVar12);
  return pOVar10;
}


