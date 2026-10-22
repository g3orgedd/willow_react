// Source: CLCSTextBasedField.dll @ 42424518; FUN_42424518

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_42424518(void *this,HDC param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined4 param_6,undefined4 param_7,ULONG param_8,
            undefined4 *param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 *param_13,undefined4 param_14,COLORREF param_15)

{
  int *piVar1;
  undefined1 uVar2;
  int *piVar3;
  UINT UVar4;
  uint uVar5;
  int iVar6;
  HBRUSH pHVar7;
  HBRUSH pHVar8;
  undefined4 uVar9;
  HBITMAP h;
  int iVar10;
  BSTR extraout_ECX;
  uint uVar11;
  LONG LVar12;
  LONG LVar13;
  code *pcVar14;
  bool bVar15;
  BSTR pOVar16;
  int *piVar17;
  OLECHAR **ppOVar18;
  HDC pHVar19;
  char cVar20;
  undefined1 local_3d4 [4];
  int local_3d0;
  int local_3cc;
  int *local_3bc;
  undefined4 local_3b8;
  undefined4 uStack_3b4;
  undefined4 *local_3b0;
  undefined4 uStack_3ac;
  tagSIZE local_3a8;
  tagSIZE local_3a0;
  undefined4 local_398;
  undefined4 uStack_394;
  undefined4 *local_390;
  undefined4 uStack_38c;
  undefined4 local_388;
  tagSIZE local_384;
  _union_2683 local_37c;
  tagSIZE local_36c;
  tagSIZE local_364;
  int local_35c;
  int local_358;
  int local_354;
  int local_350;
  undefined4 local_34c;
  tagSIZE local_348;
  tagPOINT local_340;
  tagPOINT local_338;
  tagSIZE local_330;
  tagSIZE local_328;
  tagSIZE local_320;
  HDC local_318;
  int local_314;
  int *local_310;
  int *local_30c;
  int local_308;
  int local_304;
  int *local_300;
  COLORREF local_2fc;
  int local_2f8;
  int local_2f4;
  int local_2f0;
  uint local_2ec;
  HBITMAP local_2e8;
  int *local_2e4;
  int local_2e0;
  void *local_2dc;
  int local_2d8 [2];
  HGDIOBJ local_2d0;
  int *local_2cc;
  BSTR local_2c8;
  LPCWSTR local_2c4;
  COLORREF local_2c0;
  int *local_2bc;
  BSTR local_2b8;
  BSTR local_2b4;
  LONG local_2b0;
  LONG local_2ac;
  OLECHAR *local_2a8;
  BSTR local_2a4;
  BSTR local_2a0;
  int *local_29c;
  int *local_298;
  HDC local_294;
  undefined4 local_290 [130];
  tagTEXTMETRICW local_88;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c4;
  local_8 = 0x42424527;
  local_318 = param_1;
  local_398 = param_3;
  uStack_394 = param_4;
  local_390 = param_5;
  uStack_38c = param_6;
  local_37c._0_4_ = param_7;
  local_37c.decVal.Hi32 = param_8;
  local_37c._8_4_ = param_9;
  local_37c._12_4_ = param_10;
  local_3b8 = param_11;
  uStack_3b4 = param_12;
  local_3b0 = param_13;
  uStack_3ac = param_14;
  local_2dc = this;
  if ((DAT_424bfb3c & 1) == 0) {
    DAT_424bfb3c = DAT_424bfb3c | 1;
    local_8 = 0;
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_424bfb24,
               "CCLCSTextBasedFieldObj::DrawTrueType");
    FUN_4246f3f8(&LAB_42493ec1);
    local_8 = 0xffffffff;
  }
  if ((short)local_398 == 9) {
    local_294 = CreateCompatibleDC((HDC)0x0);
    CComQIPtr<>(&local_310,local_390);
    local_8 = 2;
    local_298 = local_310;
    if (local_310 != (int *)0x0) {
      (**(code **)(*local_310 + 4))();
    }
    local_29c = (int *)0x0;
    CComQIPtr<>(&local_300,(undefined4 *)local_37c._8_4_);
    local_8._0_1_ = 4;
    local_29c = local_300;
    if (local_300 != (int *)0x0) {
      (**(code **)(*local_300 + 4))();
    }
    CComQIPtr<>(&local_30c,local_3b0);
    piVar1 = local_30c;
    local_8._0_1_ = 6;
    local_3bc = local_30c;
    if (local_30c != (int *)0x0) {
      (**(code **)(*local_30c + 4))();
    }
    local_384.cx = 0;
    local_384.cy = 0;
    local_36c.cx = 0;
    local_36c.cy = 0;
    local_3a8.cx = 0;
    local_3a8.cy = 0;
    local_3a0.cx = 0;
    local_3a0.cy = 0;
    local_2c4 = (LPCWSTR)0x0;
    local_8._0_1_ = 7;
    (**(code **)(*local_298 + 0xa8))();
    local_308 = 0;
    (**(code **)(*local_29c + 0x184))();
    pcVar14 = SysFreeString_exref;
    if (local_308 == 1) {
      FUN_4240391a(&local_2a8,local_2c4);
      local_8._0_1_ = 8;
      FUN_42427fd5(&DAT_424bfaec,&local_2a8);
      piVar3 = FUN_424037d2(&local_2b8,local_2a8);
      FUN_4241115f(&local_2c4,piVar3);
      SysFreeString(local_2b8);
      FUN_42403ad1((int *)&local_2a8);
    }
    SetMapMode(local_294,1);
    pHVar19 = local_318;
    GetViewportExtEx(local_318,&local_3a8);
    GetWindowExtEx(pHVar19,&local_3a0);
    SetMapMode(local_294,8);
    SetViewportExtEx(local_294,100,100,&local_384);
    SetWindowExtEx(local_294,100,100,&local_36c);
    uVar11 = 0;
    local_2a8 = (OLECHAR *)0x0;
    local_8 = CONCAT31(local_8._1_3_,9);
    cVar20 = '\0';
    piVar3 = local_29c;
    if (local_29c != (int *)0x0) {
      cVar20 = '\0';
      (**(code **)(*local_29c + 4))();
    }
    ppOVar18 = &local_2a8;
    piVar17 = local_298;
    pHVar19 = local_294;
    if (local_298 != (int *)0x0) {
      (**(code **)(*local_298 + 4))();
    }
    FUN_42425c36(piVar17,ppOVar18,pHVar19,piVar3,cVar20);
    local_2b4 = (BSTR)0x0;
    local_8._0_1_ = 10;
    (**(code **)(*local_298 + 0x98))();
    local_314 = 0;
    (**(code **)(*local_298 + 0x10c))();
    local_2c8 = (BSTR)0x0;
    local_8._0_1_ = 0xb;
    uVar2 = (undefined1)local_8;
    local_8._0_1_ = 0xb;
    if (local_314 == 1) {
      UVar4 = SysStringLen(local_2b4);
      local_2b8 = (BSTR)(UVar4 * 2 + -1);
      if (0 < (int)local_2b8) {
        do {
          uVar5 = uVar11 & 0x80000001;
          bVar15 = uVar5 == 0;
          if ((int)uVar5 < 0) {
            bVar15 = (uVar5 - 1 | 0xfffffffe) == 0xffffffff;
          }
          if (bVar15) {
            FUN_42407163(&local_2a0,(uint)(ushort)local_2b4[(int)uVar11 / 2]);
            local_8._0_1_ = 0xc;
            iVar6 = FUN_42403ee7(&local_2c8,local_2a0);
            if (iVar6 < 0) goto LAB_4242485d;
            local_8._0_1_ = 0xb;
            SysFreeString(local_2a0);
          }
          else {
            iVar6 = FUN_42403dcc(&local_2c8,L" ");
            if (iVar6 < 0) {
LAB_4242485d:
                    /* WARNING: Subroutine does not return */
              FUN_42403fdf(iVar6);
            }
          }
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < (int)local_2b8);
      }
    }
    else {
      local_8._0_1_ = uVar2;
      FUN_42403b34(&local_2c8,(int *)&local_2b4);
    }
    pOVar16 = local_2c8;
    UVar4 = SysStringLen(local_2c8);
    if (UVar4 == 0) {
      DeleteDC(local_294);
    }
    else {
      local_2d0 = SelectObject(local_294,local_2a8);
      GetTextMetricsW(local_294,&local_88);
      local_2b0 = 0;
      local_2ac = 0;
      FUN_4240391a(local_2d8,pOVar16);
      local_8 = CONCAT31(local_8._1_3_,0xd);
      (**(code **)(*(int *)((int)local_2dc + 8) + 0x30))();
      local_24.right = local_2b0;
      local_24.bottom = local_2ac;
      local_24.left = 0;
      local_24.top = 0;
      local_348.cx = 0;
      local_348.cy = 0;
      local_330.cx = 0;
      local_330.cy = 0;
      GetViewportExtEx(local_294,&local_348);
      GetWindowExtEx(local_294,&local_330);
      (**(code **)(*local_298 + 0x3c))();
      (**(code **)(*local_298 + 0x4c))();
      local_338.x = local_2b0;
      local_338.y = local_2ac;
      LPtoDP(local_294,&local_338,1);
      local_2e8 = FUN_42421ed2(local_294,local_338.x,local_338.y,1);
      local_2b8 = SelectObject(local_294,local_2e8);
      pHVar7 = GetStockObject(0);
      pHVar8 = GetStockObject(4);
      (**(code **)(*local_298 + 0x44))();
      if (local_35c == 0) {
        local_2fc = SetTextColor(local_294,param_15);
        local_2c0 = SetBkColor(local_294,0xffffff);
        pHVar8 = pHVar7;
      }
      else {
        local_2fc = SetTextColor(local_294,0xffffff);
        local_2c0 = SetBkColor(local_294,param_15);
      }
      FillRect(local_294,&local_24,pHVar8);
      local_2cc = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,0xe);
      (**(code **)(*local_298 + 0x5c))();
      local_2e0 = 0;
      if (local_2cc != (int *)0x0) {
        (**(code **)(*local_2cc + 0x1c))(local_2cc);
        iVar6 = 0;
        if (0 < local_2e0) {
          do {
            FUN_42403802((uint *)&local_37c);
            iVar6 = iVar6 + 1;
            local_8._0_1_ = 0xf;
            (**(code **)(*local_2cc + 0x24))(local_2cc,iVar6);
            CComQIPtr<>(&local_2a0,(undefined4 *)local_37c._8_4_);
            bVar15 = local_2a0 == (BSTR)0x0;
            if (!bVar15) {
              local_2a4 = (BSTR)0x0;
              local_8._0_1_ = 0x11;
              (**(code **)(*(int *)local_2a0 + 0x80))(local_2a0);
              UVar4 = SysStringLen(local_2a4);
              if (UVar4 != 0) {
                FUN_42459fc4(&local_2bc);
                local_8._0_1_ = 0x12;
                pOVar16 = extraout_ECX;
                FUN_42403768(&stack0xfffffba0,(int *)&local_2a4);
                FUN_4245a13f(pOVar16);
                local_8._0_1_ = 0x11;
                FUN_42459fcd(&local_2bc);
              }
              SysFreeString(local_2a4);
              bVar15 = local_2a0 == (BSTR)0x0;
            }
            local_8 = CONCAT31(local_8._1_3_,0xf);
            if (!bVar15) {
              (**(code **)(*(int *)local_2a0 + 8))();
            }
            VariantClear((VARIANTARG *)&local_37c.n2);
          } while (iVar6 < local_2e0);
        }
      }
      CComQIPtr<>(&local_2e4,local_298);
      local_8._0_1_ = 0x13;
      local_2f0 = 0;
      if ((local_2e4 != (int *)0x0) &&
         ((**(code **)(*local_2e4 + 0x134))(local_2e4), local_2f0 == 1)) {
        local_2a4 = (BSTR)0x0;
        local_8._0_1_ = 0x14;
        CoCreateInstance((IID *)&DAT_42495e00,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_424980f0,&local_2a4);
        if (local_2a4 != (BSTR)0x0) {
          (**(code **)(*(int *)local_2a4 + 0xa0))
                    (local_2a4,&local_398,local_3b8,uStack_3b4,local_3b0,uStack_3ac);
          CComQIPtr<>(&local_2bc,local_390);
          local_2a0 = (BSTR)0x0;
          local_8._0_1_ = 0x16;
          (**(code **)(*local_2bc + 0x98))(local_2bc,&local_2a0);
          FUN_42403b34(&local_2b4,(int *)&local_2a0);
          SysFreeString(local_2a0);
          local_8._0_1_ = 0x14;
          if (local_2bc != (int *)0x0) {
            (**(code **)(*local_2bc + 8))();
          }
        }
        local_8._0_1_ = 0x13;
        if (local_2a4 != (BSTR)0x0) {
          (**(code **)(*(int *)local_2a4 + 8))();
        }
      }
      FUN_4243b049(local_290,0);
      local_8._0_1_ = 0x17;
      FUN_4243b74c(local_290,0xffffffff);
      local_2bc = (int *)FUN_4243b625(&local_298,&local_29c);
      uVar9 = FUN_4243b6de(&local_298);
      (**(code **)(*local_298 + 0xb8))(local_298);
      (**(code **)(*local_29c + 0x34))(local_29c,&local_34c);
      iVar6 = FUN_424258a9((int *)&local_2e4,(int *)&local_29c);
      FUN_4243b73c(local_290,iVar6);
      piVar3 = local_2bc;
      FUN_4243b75c(local_290,local_2c4,0,local_2bc,local_388,uVar9,local_34c);
      FUN_4243b7d4(local_290,local_2f0 == 1);
      FUN_4243b7e1(local_290,0,piVar3);
      FUN_4243b453(local_290,local_294,local_2b4,(undefined8 *)&local_24,0,0);
      SelectObject(local_294,local_2d0);
      SetTextColor(local_294,local_2fc);
      SetBkColor(local_294,local_2c0);
      (**(code **)(*local_298 + 0x2c))(local_298,&local_354);
      (**(code **)(*local_298 + 0x34))(local_298,&local_358);
      local_2f8 = local_354;
      if (param_2 != 0) {
        local_2f8 = 0;
        local_358 = 0;
      }
      local_2f4 = local_358;
      (**(code **)(*piVar1 + 0x54))(piVar1,&local_304);
      if (local_304 == 0) {
        FUN_42458671(&local_2c0);
        local_8._0_1_ = 0x18;
        piVar3 = local_29c;
        if (local_29c != (int *)0x0) {
          (**(code **)(*local_29c + 4))(local_29c);
        }
        FUN_42458960(&local_2f8,piVar3);
        local_8._0_1_ = 0x17;
        FUN_42458752(&local_2c0);
      }
      local_328.cx = 0;
      local_328.cy = 0;
      local_320.cx = 0;
      local_320.cy = 0;
      local_364.cx = 0;
      local_364.cy = 0;
      SetViewportExtEx(local_294,1,1,&local_328);
      SetWindowExtEx(local_294,1,1,&local_320);
      FUN_4245d25e(&local_4c);
      local_48 = 0;
      local_44 = 0;
      local_8 = CONCAT31(local_8._1_3_,0x19);
      FUN_4245d2bb(&local_4c,local_294,local_2b8);
      FUN_4245d35c((int)&local_4c);
      if (local_2ec != 0) {
        FUN_4245db52(&local_4c,local_2ec);
      }
      FUN_4245d591(&local_4c,(int *)&local_294,&local_2e8,(undefined4 *)0x0,(undefined4 *)0x0);
      SetMapMode(local_294,8);
      SetViewportExtEx(local_294,local_328.cx,local_328.cy,&local_364);
      SetWindowExtEx(local_294,local_320.cx,local_320.cy,&local_364);
      pHVar19 = local_318;
      SetViewportExtEx(local_318,local_348.cx,local_348.cy,&local_384);
      SetWindowExtEx(pHVar19,local_330.cx,local_330.cy,&local_36c);
      GetObjectW(local_2e8,0x18,local_3d4);
      h = CreateCompatibleBitmap(pHVar19,local_3d0,local_3cc);
      SelectObject(pHVar19,h);
      pHVar8 = GetStockObject(0);
      local_340.x = local_3d0;
      local_340.y = local_3cc;
      DPtoLP(pHVar19,&local_340,1);
      SetRect(&local_24,0,0,local_340.x,local_340.y);
      local_2b0 = local_24.right - local_24.left;
      local_2ac = local_24.bottom - local_24.top;
      FillRect(pHVar19,&local_24,pHVar8);
      if (local_350 == 0) {
        BitBlt(pHVar19,local_2f8,local_2f4,local_2b0,local_2ac,local_294,0,0,0xcc0020);
      }
      else {
        StretchBlt(pHVar19,local_2f8,local_2f4,local_2b0,local_2ac,local_294,local_2b0 + -1,0,
                   -local_2b0,local_2ac,0xcc0020);
      }
      if ((local_2ec == 0x5a) || (LVar13 = local_2b0, local_2ec == 0x10e)) {
        LVar13 = local_2ac;
      }
      if ((local_2ec == 0x5a) || (LVar12 = local_2ac, local_2ec == 0x10e)) {
        LVar12 = local_2b0;
      }
      if (local_304 == 0) {
        FUN_42458671(&local_2d0);
        local_8 = CONCAT31(local_8._1_3_,0x1a);
        piVar3 = local_29c;
        if (local_29c != (int *)0x0) {
          (**(code **)(*local_29c + 4))(local_29c);
        }
        iVar6 = FUN_42458843(LVar13,1.4013e-45,piVar3);
        piVar3 = local_29c;
        if (local_29c != (int *)0x0) {
          (**(code **)(*local_29c + 4))(local_29c);
        }
        iVar10 = FUN_42458843(LVar12,0.0,piVar3);
        (**(code **)(*local_298 + 0x7c))(local_298,iVar6);
        (**(code **)(*local_298 + 0x84))(local_298,iVar10);
        local_8 = CONCAT31(local_8._1_3_,0x19);
        FUN_42458752(&local_2d0);
      }
      else {
        (**(code **)(*local_298 + 0x7c))(local_298,LVar13);
        (**(code **)(*local_298 + 0x84))(local_298,LVar12);
      }
      SelectObject(local_294,local_2b8);
      DeleteObject(local_2a8);
      DeleteObject(local_2e8);
      DeleteDC(local_294);
      local_8._0_1_ = 0x17;
      FUN_4245d291(&local_4c);
      local_8._0_1_ = 0x13;
      FUN_4243b0be(local_290);
      local_8._0_1_ = 0xe;
      if (local_2e4 != (int *)0x0) {
        (**(code **)(*local_2e4 + 8))();
      }
      local_8._0_1_ = 0xd;
      if (local_2cc != (int *)0x0) {
        (**(code **)(*local_2cc + 8))();
      }
      FUN_42403ad1(local_2d8);
      pcVar14 = SysFreeString_exref;
    }
    (*pcVar14)();
    (*pcVar14)();
    if (local_2a8 != (OLECHAR *)0x0) {
      DeleteObject(local_2a8);
    }
    (*pcVar14)();
    local_8._0_1_ = 5;
    if (local_30c != (int *)0x0) {
      (**(code **)(*local_30c + 8))();
    }
    local_8._0_1_ = 4;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))();
    }
    local_8._0_1_ = 3;
    if (local_300 != (int *)0x0) {
      (**(code **)(*local_300 + 8))();
    }
    local_8._0_1_ = 2;
    if (local_29c != (int *)0x0) {
      (**(code **)(*local_29c + 8))();
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_298 != (int *)0x0) {
      (**(code **)(*local_298 + 8))();
    }
    local_8 = 0xffffffff;
    if (local_310 != (int *)0x0) {
      (**(code **)(*local_310 + 8))();
    }
  }
  FUN_4246ecf6();
  return;
}


