// Source: CLCSTextBasedField.dll @ 42425c36; FUN_42425c36

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_42425c36(int *param_1,undefined4 *param_2,HDC param_3,int *param_4,char param_5)

{
  BYTE BVar1;
  undefined1 uVar2;
  int *piVar3;
  UINT UVar4;
  HRESULT HVar5;
  int iVar6;
  int iVar7;
  HFONT pHVar8;
  HGDIOBJ pvVar9;
  BSTR pOVar10;
  code *pcVar11;
  int iVar12;
  undefined1 local_138 [4];
  undefined1 local_134 [4];
  VARIANTARG local_130;
  _union_2683 local_120;
  tagSIZE local_110;
  tagSIZE local_108;
  int local_100;
  undefined4 *local_fc;
  _union_2683 local_f8;
  int local_e8;
  int *local_e4;
  int local_e0;
  int local_dc;
  int *local_d8;
  int local_d4;
  uint local_d0;
  OLECHAR *local_cc;
  BSTR local_c8;
  int *local_c4;
  LPCWSTR local_c0;
  BSTR local_bc;
  BSTR local_b8;
  char local_b1;
  BSTR local_b0;
  tagTEXTMETRICW local_ac;
  LOGFONTW local_70;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x128;
  local_fc = param_2;
  local_8 = 0;
  FUN_4246d990((uint *)&local_70,0,0x5c);
  pcVar11 = GetDeviceCaps_exref;
  GetDeviceCaps(param_3,0x16);
  local_c0 = (LPCWSTR)0x0;
  local_8._0_1_ = 2;
  (**(code **)(*param_1 + 0xa8))(param_1,&local_c0);
  local_dc = 0;
  (**(code **)(*param_4 + 0x184))(param_4,&local_dc);
  if (local_dc == 1) {
    FUN_4240391a(&local_b0,local_c0);
    local_8._0_1_ = 3;
    FUN_42427fd5(&DAT_424bfaec,&local_b0);
    piVar3 = FUN_424037d2(&local_bc,local_b0);
    FUN_4241115f(&local_c0,piVar3);
    SysFreeString(local_bc);
    FUN_42403ad1((int *)&local_b0);
  }
  local_b1 = '\0';
  FUN_42403802((uint *)&local_120);
  local_8._0_1_ = 4;
  (**(code **)(*param_4 + 0x474))(param_4,&local_120);
  CComQIPtr<>(&local_e4,(undefined4 *)local_120._8_4_);
  local_8._0_1_ = 5;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 5;
  if (local_120.n2.vt != 0) {
    FUN_42403802((uint *)&local_f8);
    local_8._0_1_ = 6;
    (**(code **)(*local_e4 + 0x30))(local_e4,local_c0,&local_f8);
    if (local_f8.n2.vt != 0) {
      CComQIPtr<>(&local_c4,(undefined4 *)local_f8._8_4_);
      if (local_c4 != (int *)0x0) {
        local_b8 = (BSTR)0x0;
        local_8._0_1_ = 8;
        (**(code **)(*local_c4 + 0xac))(local_c4,&local_b8);
        UVar4 = SysStringLen(local_b8);
        if (UVar4 != 0) {
          FUN_4246f507(local_70.lfFaceName,0x20,local_b8,0x1f);
          local_b1 = '\x01';
        }
        SysFreeString(local_b8);
      }
      local_8._0_1_ = 6;
      if (local_c4 != (int *)0x0) {
        (**(code **)(*local_c4 + 8))(local_c4);
      }
    }
    local_8._0_1_ = 5;
    VariantClear((VARIANTARG *)&local_f8.n2);
    uVar2 = (undefined1)local_8;
    if (local_b1 != '\0') goto LAB_42425e3a;
  }
  local_8._0_1_ = uVar2;
  FUN_4246f507(local_70.lfFaceName,0x20,local_c0,0x1f);
LAB_42425e3a:
  (**(code **)(*param_1 + 0xc0))(param_1,&local_100);
  if (local_100 == 0) {
    local_70.lfWeight = 400;
  }
  else {
    FUN_42403802((uint *)&local_130);
    local_8._0_1_ = 9;
    (**(code **)(*param_4 + 0x474))(param_4,&local_130);
    CComQIPtr<>(&local_c4,(undefined4 *)local_130.n1._8_4_);
    local_8._0_1_ = 10;
    (**(code **)(*local_c4 + 0x24))(local_c4,&local_bc);
    local_cc = (OLECHAR *)0x0;
    local_b8 = (BSTR)0x0;
    pOVar10 = (OLECHAR *)0x0;
    if (0 < (int)local_bc) {
      do {
        FUN_42403802((uint *)&local_f8);
        local_b8 = (BSTR)((int)local_b8 + 1);
        local_8._0_1_ = 0xc;
        (**(code **)(*local_c4 + 0x20))(local_c4,local_b8,&local_f8);
        CComQIPtr<>(&local_b0,(undefined4 *)local_f8._8_4_);
        local_c8 = (BSTR)0x0;
        local_8._0_1_ = 0xe;
        (**(code **)(*(int *)local_b0 + 0x1c))(local_b0,&local_c8);
        HVar5 = VarBstrCmp(local_c8,local_c0,0x400,0);
        pOVar10 = local_b0;
        if (HVar5 == 1) {
          local_cc = local_b0;
          if (local_b0 != (OLECHAR *)0x0) {
            (**(code **)(*(int *)local_b0 + 4))(local_b0);
          }
          SysFreeString(local_c8);
          local_8._0_1_ = 0xc;
          if (local_b0 != (OLECHAR *)0x0) {
            (**(code **)(*(int *)local_b0 + 8))(local_b0);
          }
          local_8._0_1_ = 0xb;
          VariantClear((VARIANTARG *)&local_f8.n2);
          if (pOVar10 != (OLECHAR *)0x0) {
            (**(code **)(*(int *)pOVar10 + 0x5c))(pOVar10,&local_c8);
            local_b0 = (BSTR)0x0;
            local_8._0_1_ = 0xf;
            (**(code **)(*(int *)pOVar10 + 100))(pOVar10,&local_b0);
            if (local_c8 == (BSTR)0x1) {
              UVar4 = SysStringLen(local_b0);
              if (UVar4 == 0) goto LAB_42426060;
              FUN_4246f507(local_70.lfFaceName,0x20,local_b0,0x1f);
            }
            else {
LAB_42426060:
              local_70.lfWeight = 900;
            }
            SysFreeString(local_b0);
            goto LAB_42425f81;
          }
          break;
        }
        SysFreeString(local_c8);
        local_8._0_1_ = 0xc;
        if (local_b0 != (OLECHAR *)0x0) {
          (**(code **)(*(int *)local_b0 + 8))(local_b0);
        }
        VariantClear((VARIANTARG *)&local_f8.n2);
        pOVar10 = (OLECHAR *)0x0;
      } while ((int)local_b8 < (int)local_bc);
    }
    local_70.lfWeight = 900;
LAB_42425f81:
    local_8._0_1_ = 10;
    if (pOVar10 != (OLECHAR *)0x0) {
      (**(code **)(*(int *)pOVar10 + 8))(pOVar10);
    }
    local_8._0_1_ = 9;
    if (local_c4 != (int *)0x0) {
      (**(code **)(*local_c4 + 8))(local_c4);
    }
    local_8._0_1_ = 5;
    VariantClear(&local_130);
    pcVar11 = GetDeviceCaps_exref;
  }
  local_70.lfCharSet = '\x01';
  local_70.lfOutPrecision = '\a';
  local_70.lfQuality = '\x01';
  (**(code **)(*param_1 + 0x3c))(param_1,local_134);
  local_70.lfOrientation = 0;
  local_70.lfEscapement = 0;
  local_e8 = 0;
  (**(code **)(*param_1 + 0xb0))(param_1,&local_e8);
  local_e0 = 1;
  CComQIPtr<>(&local_d8,param_1);
  local_8 = CONCAT31(local_8._1_3_,0x10);
  if (local_d8 != (int *)0x0) {
    (**(code **)(*local_d8 + 0x168))(local_d8,&local_e0);
  }
  iVar7 = local_e8;
  if (param_5 == '\0') {
    (**(code **)(*param_4 + 0x34))(param_4,&local_cc);
    iVar6 = FUN_424264fb((float)local_cc * _DAT_424983f0);
  }
  else {
    (**(code **)(*param_1 + 0x3c))(param_1,&local_bc);
    if ((local_bc == (BSTR)0x0) || (local_bc == (BSTR)0xb4)) {
      (*pcVar11)(param_3,0x5a);
      iVar6 = (*pcVar11)(param_3,10);
      iVar12 = 6;
    }
    else {
      (*pcVar11)(param_3,0x58);
      iVar6 = (*pcVar11)(param_3,8);
      iVar12 = 4;
    }
    iVar12 = GetDeviceCaps(param_3,iVar12);
    iVar6 = (int)((double)((float)(iVar6 * 0xfe) / (float)iVar12) / DAT_424983e8);
  }
  local_108.cx = 0;
  local_108.cy = 0;
  local_110.cx = 0;
  local_110.cy = 0;
  GetViewportExtEx(param_3,&local_108);
  GetWindowExtEx(param_3,&local_110);
  iVar7 = MulDiv(iVar7,iVar6,0x11b);
  local_70.lfHeight = -(iVar7 / local_e0);
  pHVar8 = CreateFontIndirectW(&local_70);
  pvVar9 = SelectObject(param_3,pHVar8);
  GetTextMetricsW(param_3,&local_ac);
  pvVar9 = SelectObject(param_3,pvVar9);
  DeleteObject(pvVar9);
  BVar1 = local_ac.tmPitchAndFamily;
  local_d0 = 0;
  (**(code **)(*param_1 + 0x124))(param_1,&local_d0);
  if (local_d0 != 2) {
    local_d0 = (uint)((BVar1 & 6) != 0);
    (**(code **)(*param_1 + 0x128))(param_1,local_d0);
  }
  local_d4 = 0;
  (**(code **)(*param_1 + 0x3c))(param_1,&local_d4);
  if ((local_d4 == 0) || (local_d4 == 0xb4)) {
    (**(code **)(*param_4 + 0x2c))(param_4,&local_cc);
    (**(code **)(*param_4 + 0x34))(param_4,&local_bc);
  }
  (**(code **)(*param_1 + 0xb8))(param_1,local_138);
  (**(code **)(*param_1 + 0x100))(param_1,local_ac.tmPitchAndFamily & 0xf0);
  pHVar8 = CreateFontIndirectW(&local_70);
  local_8._0_1_ = 5;
  *local_fc = pHVar8;
  if (local_d8 != (int *)0x0) {
    (**(code **)(*local_d8 + 8))(local_d8);
  }
  local_8._0_1_ = 4;
  if (local_e4 != (int *)0x0) {
    (**(code **)(*local_e4 + 8))(local_e4);
  }
  VariantClear((VARIANTARG *)&local_120.n2);
  SysFreeString(local_c0);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  local_8 = 0xffffffff;
  if (param_4 != (int *)0x0) {
    (**(code **)(*param_4 + 8))(param_4);
  }
  FUN_4246ecf6();
  return;
}


