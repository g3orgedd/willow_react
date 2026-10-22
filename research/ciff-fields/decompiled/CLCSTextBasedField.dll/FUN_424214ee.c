// Source: CLCSTextBasedField.dll @ 424214ee; FUN_424214ee

int FUN_424214ee(void *self,void *outSize,VARIANTARG field,VARIANTARG coderCapabilities,
                VARIANTARG ciffFile)

{
  bool bVar1;
  HDC pHVar2;
  int *piVar3;
  void *this;
  UINT UVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  OLECHAR *pOVar8;
  BSTR extraout_ECX;
  code *pcVar9;
  BSTR bstrString;
  BSTR pOVar10;
  BSTR pOVar11;
  BSTR *ppOVar12;
  HDC pHVar13;
  BSTR pOVar14;
  char cVar15;
  int *piVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  _union_2683 local_2d4;
  tagSIZE local_2c4;
  tagSIZE local_2bc;
  int local_2b4;
  _union_2683 local_2b0;
  int *local_2a0;
  BSTR local_29c;
  int local_298;
  int *local_294;
  int local_290;
  BSTR local_28c;
  int local_288;
  int local_284;
  tagSIZE local_280;
  int *local_278;
  int local_274;
  HDC local_270;
  BSTR local_26c;
  int *local_268;
  int *local_264;
  BSTR local_260;
  BSTR local_25c;
  uint local_258;
  LPCWSTR local_254;
  OLECHAR *local_250;
  BSTR local_24c;
  int *local_248;
  BSTR local_244;
  int *local_240;
  char local_239;
  undefined4 local_238 [130];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [24];
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  local_248 = self;
  local_18.left = field.n1._0_4_;
  local_268 = outSize;
  local_18.top = field.n1.decVal.Hi32;
  local_18.right = field.n1._8_4_;
  local_18.bottom = field.n1._12_4_;
  local_2b0._0_4_ = coderCapabilities.n1._0_4_;
  local_2b0.decVal.Hi32 = coderCapabilities.n1.decVal.Hi32;
  local_2b0._8_4_ = coderCapabilities.n1._8_4_;
  local_2b0._12_4_ = coderCapabilities.n1._12_4_;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCLCSTextBasedFieldObj::CalculateSize");
  CComQIPtr<>(&local_2a0,(undefined4 *)local_18.right);
  local_240 = local_2a0;
  if (local_2a0 != (int *)0x0) {
    (**(code **)(*local_2a0 + 4))();
  }
  local_298 = 0;
  (**(code **)(*local_240 + 0x124))();
  local_284 = 0;
  (**(code **)(*local_240 + 0xa8))();
  pcVar9 = SysFreeString_exref;
  if (local_298 == 2) {
LAB_42421d7d:
    CComQIPtr<>(&local_244,local_240);
    if (local_244 == (BSTR)0x0) goto LAB_42421de2;
    FUN_42467c7e(local_248 + 0x1d,local_268,local_18.left,local_18.top,(undefined4 *)local_18.right)
    ;
    local_29c = local_244;
  }
  else {
    local_264 = local_248 + -2;
    pOVar14 = extraout_ECX;
    uVar7 = local_2b0._0_4_;
    uVar17 = local_2b0.decVal.Hi32;
    uVar18 = local_2b0._8_4_;
    FUN_42403768(&stack0xfffffcfc,&local_284);
    bVar1 = FUN_42425abf(local_264,pOVar14,uVar7,uVar17,(IUnknown *)uVar18);
    if (bVar1) goto LAB_42421d7d;
    pHVar2 = GetDC((HWND)0x0);
    local_270 = pHVar2;
    GetViewportExtEx(pHVar2,&local_2bc);
    GetWindowExtEx(pHVar2,&local_2c4);
    (**(code **)(*local_240 + 0x3c))();
    if ((local_288 == 0x5a) || (local_288 == 0x10e)) {
      SetViewportExtEx(pHVar2,local_2bc.cy,local_2bc.cx,&local_280);
      SetWindowExtEx(pHVar2,local_2c4.cy,local_2c4.cx,&local_280);
    }
    CComQIPtr<>(&local_29c,(undefined4 *)local_2b0._8_4_);
    local_25c = local_29c;
    if (local_29c != (BSTR)0x0) {
      (**(code **)(*(int *)local_29c + 4))();
    }
    local_254 = (LPCWSTR)0x0;
    (**(code **)(*local_240 + 0xa8))();
    local_290 = 0;
    (**(code **)(*(int *)local_25c + 0x184))();
    if (local_290 == 1) {
      FUN_4240391a(&local_250,local_254);
      FUN_42427fd5(&DAT_424bfaec,&local_250);
      piVar3 = FUN_424037d2(&local_244,local_250);
      FUN_4241115f(&local_254,piVar3);
      SysFreeString(local_244);
      FUN_42403ad1((int *)&local_250);
    }
    FUN_42403802((uint *)&local_2d4);
    (**(code **)(*(int *)local_25c + 0x474))();
    local_250 = (OLECHAR *)0x0;
    if (local_2d4.n2.vt == 0) {
      local_239 = '\x01';
    }
    else {
      CComQIPtr<>(&local_294,(undefined4 *)local_2d4._8_4_);
      FUN_42403802((uint *)&local_2b0);
      (**(code **)(*local_294 + 0x30))();
      if (local_2b0.n2.vt == 0) {
        local_239 = '\x01';
      }
      else {
        CComQIPtr<>(&local_278,(undefined4 *)local_2b0._8_4_);
        local_28c = (BSTR)0x0;
        (**(code **)(*local_278 + 0x9c))();
        bVar1 = FUN_42403bfa(&local_28c,L"TrueType");
        piVar3 = local_278;
        if (bVar1) {
          local_239 = '\x01';
        }
        else {
          if (local_278 != (int *)0x0) {
            (**(code **)(*local_278 + 4))();
          }
          this = (void *)FUN_4246d133(4);
          if (this == (void *)0x0) {
            local_250 = (OLECHAR *)0x0;
          }
          else {
            piVar16 = piVar3;
            if (piVar3 != (int *)0x0) {
              (**(code **)(*piVar3 + 4))();
            }
            local_250 = (OLECHAR *)FUN_42420b25(this,piVar16);
          }
          local_239 = '\0';
          pHVar2 = local_270;
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 8))();
            pHVar2 = local_270;
          }
        }
        SysFreeString(local_28c);
        if (local_278 != (int *)0x0) {
          (**(code **)(*local_278 + 8))();
        }
      }
      VariantClear((VARIANTARG *)&local_2b0.n2);
      if (local_294 != (int *)0x0) {
        (**(code **)(*local_294 + 8))();
      }
    }
    local_24c = (BSTR)0x0;
    if (local_239 != '\0') {
      cVar15 = '\0';
      pOVar14 = local_25c;
      if (local_25c != (BSTR)0x0) {
        cVar15 = '\0';
        (**(code **)(*(int *)local_25c + 4))();
      }
      ppOVar12 = &local_24c;
      piVar3 = local_240;
      pHVar13 = pHVar2;
      if (local_240 != (int *)0x0) {
        (**(code **)(*local_240 + 4))();
      }
      FUN_42425c36(piVar3,ppOVar12,pHVar13,(int *)pOVar14,cVar15);
    }
    pOVar14 = local_24c;
    local_280.cy = (LONG)SelectObject(pHVar2,local_24c);
    local_26c = (BSTR)0x0;
    (**(code **)(*local_240 + 0x98))();
    local_24c = (BSTR)0x0;
    (**(code **)(*local_240 + 0x10c))();
    if (local_2b4 == 0) {
      FUN_42403b34(&local_24c,(int *)&local_26c);
      bstrString = local_24c;
    }
    else {
      UVar4 = SysStringLen(local_26c);
      local_258 = 0;
      pOVar11 = (BSTR)(UVar4 * 2 + -1);
      bstrString = (BSTR)0x0;
      local_244 = pOVar11;
      if (0 < (int)pOVar11) {
        do {
          uVar5 = local_258 & 0x80000001;
          bVar1 = uVar5 == 0;
          if ((int)uVar5 < 0) {
            bVar1 = (uVar5 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if (bVar1) {
            FUN_42407163(&local_260,(uint)(ushort)local_26c[(int)local_258 / 2]);
            iVar6 = FUN_42403ee7(&local_24c,local_260);
            if (iVar6 < 0) goto LAB_42421e2d;
            SysFreeString(local_260);
          }
          else {
            iVar6 = FUN_42403dcc(&local_24c,L" ");
            if (iVar6 < 0) {
LAB_42421e2d:
                    /* WARNING: Subroutine does not return */
              FUN_42403fdf(iVar6);
            }
          }
          local_258 = local_258 + 1;
          bstrString = local_24c;
        } while ((int)local_258 < (int)pOVar11);
      }
    }
    if (local_239 == '\0') {
      (**(code **)(*local_240 + 0x10c))();
      uVar7 = 0;
      if (local_258 != 0) {
        uVar7 = 2;
      }
      (**(code **)(*local_240 + 0xc0))();
      if (local_260 != (BSTR)0x0) {
        uVar7 = 1;
      }
      if ((local_258 != 0) && (local_260 != (BSTR)0x0)) {
        uVar7 = 3;
      }
      pOVar8 = FUN_42459daa();
      FUN_424037d2(&local_244,pOVar8);
      (**(code **)(*(int *)local_248[0x3b] + 0x30))();
      if ((local_250 == (OLECHAR *)0x0) || (iVar6 = FUN_42421180((int *)local_250), iVar6 != 1)) {
        (**(code **)(*(int *)local_248[0x3b] + 0x20))((int *)local_248[0x3b],local_254,uVar7);
      }
      else {
        pOVar10 = (BSTR)0x1;
        pOVar11 = local_260;
        FUN_42403768(&stack0xfffffcc0,(int *)&local_24c);
        iVar6 = FUN_4242575b(local_250,pOVar10,(int)pOVar11);
        *local_268 = iVar6;
      }
      piVar3 = local_268 + 1;
      (**(code **)(*local_240 + 0xb0))();
      local_274 = 1;
      CComQIPtr<>(&local_264,local_240);
      if (local_264 != (int *)0x0) {
        (**(code **)(*local_264 + 0x168))();
      }
      *piVar3 = *piVar3 / local_274;
      if (local_264 != (int *)0x0) {
        (**(code **)(*local_264 + 8))();
      }
      SysFreeString(local_244);
    }
    else {
      FUN_4243b049(local_238,0);
      FUN_4243b74c(local_238,0xffffffff);
      local_260 = (BSTR)FUN_4243b625(&local_240,&local_25c);
      uVar7 = FUN_4243b6de(&local_240);
      (**(code **)(*local_240 + 0xb8))();
      (**(code **)(*(int *)local_25c + 0x34))();
      pOVar11 = local_260;
      FUN_4243b75c(local_238,local_254,0,local_260,local_274,uVar7,local_244);
      CComQIPtr<>(&local_248,local_240);
      local_258 = 0;
      if (local_248 != (int *)0x0) {
        (**(code **)(*local_248 + 0x134))();
      }
      FUN_4243b7d4(local_238,local_258 == 1);
      FUN_4243b7e1(local_238,0,pOVar11);
      iVar6 = FUN_424258a9((int *)&local_248,(int *)&local_25c);
      FUN_4243b73c(local_238,iVar6);
      local_288 = 0;
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      FUN_4243b155(local_238,local_270,bstrString,&local_18,0,0);
      *local_268 = local_18.right - local_18.left;
      local_268[1] = local_18.bottom - local_18.top;
      if (local_248 != (int *)0x0) {
        (**(code **)(*local_248 + 8))();
      }
      FUN_4243b0be(local_238);
    }
    pOVar8 = local_250;
    if (local_250 != (OLECHAR *)0x0) {
      FUN_42420d86((int *)local_250);
      FID_conflict__free(pOVar8);
    }
    pHVar2 = local_270;
    SelectObject(local_270,(HGDIOBJ)local_280.cy);
    DeleteObject(pOVar14);
    ReleaseDC((HWND)0x0,pHVar2);
    pcVar9 = SysFreeString_exref;
    SysFreeString(bstrString);
    SysFreeString(local_26c);
    if (pOVar14 != (BSTR)0x0) {
      DeleteObject(pOVar14);
    }
    VariantClear((VARIANTARG *)&local_2d4.n2);
    SysFreeString(local_254);
    if (local_25c != (BSTR)0x0) {
      (**(code **)(*(int *)local_25c + 8))();
    }
  }
  if (local_29c != (BSTR)0x0) {
    (**(code **)(*(int *)local_29c + 8))();
  }
LAB_42421de2:
  (*pcVar9)();
  if (local_240 != (int *)0x0) {
    (**(code **)(*local_240 + 8))();
  }
  if (local_2a0 != (int *)0x0) {
    (**(code **)(*local_2a0 + 8))();
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  iVar6 = FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return iVar6;
}


