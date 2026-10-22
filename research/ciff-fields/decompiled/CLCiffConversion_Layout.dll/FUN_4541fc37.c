// Source: CLCiffConversion_Layout.dll @ 4541fc37; FUN_4541fc37

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_4541fc37(void *this,IUnknownVtbl *param_1,IUnknownVtbl *param_2)

{
  int *piVar1;
  IUnknownVtbl *pIVar2;
  bool bVar3;
  HDC pHVar4;
  BOOL BVar5;
  UINT UVar6;
  IUnknown IVar7;
  size_t sVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 *puVar11;
  HDC pHVar12;
  int extraout_EAX;
  BSTR extraout_ECX;
  int iVar13;
  IUnknownVtbl *pIVar14;
  BSTR pOVar15;
  int *piVar16;
  int *local_2c4;
  undefined4 uStack_2c0;
  ULONG UStack_2bc;
  int *piStack_2b8;
  _union_2683 local_2b4;
  int *local_2a4;
  undefined1 local_2a0 [16];
  BSTR local_290;
  HDC local_28c;
  HDC local_288;
  undefined4 local_284;
  uint local_280;
  OLECHAR *local_27c;
  IUnknownVtbl *local_278;
  int *local_274;
  IUnknownVtbl *local_270;
  HDC local_26c;
  char local_265;
  IUnknownVtbl *local_264;
  IUnknown local_260;
  IUnknownVtbl *local_25c;
  IUnknownVtbl *local_258;
  undefined4 local_254 [122];
  undefined4 local_6c [3];
  uint local_60 [4];
  undefined4 local_50;
  byte local_44 [32];
  _union_2683 local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2a4;
  local_8._0_1_ = 0x46;
  local_8._1_3_ = 0x4541fc;
  local_258 = param_1;
  local_264 = param_2;
  local_274 = this;
  if ((param_1 == (IUnknownVtbl *)0x0) || (param_2 == (IUnknownVtbl *)0x0)) goto LAB_45420546;
  FUN_4541cded((int)param_2);
  FUN_4541c774(param_2,&local_27c);
  local_8 = 0;
  local_265 = FUN_4541c69f((int)param_2);
  local_26c = (HDC)FUN_4541cd14((int)param_2);
  FUN_4541cb40((int)param_2);
  iVar13 = 0;
  FUN_4541d03c(local_258,&local_290);
  local_8._0_1_ = 1;
  bVar3 = FUN_4541e8f1(local_258);
  if (bVar3) {
    local_288 = GetDC((HWND)0x0);
    local_284 = 0;
    local_8._0_1_ = 2;
    if (local_288 != (HDC)0x0) {
      local_8._0_1_ = 3;
      pHVar4 = CreateCompatibleDC(local_288);
      local_28c = pHVar4;
      if (pHVar4 != (HDC)0x0) {
        local_2a0._8_4_ = (int *)0x0;
        local_2a0._12_4_ = 0;
        iVar13 = SetMapMode(pHVar4,8);
        if (((iVar13 != 0) &&
            (BVar5 = SetWindowExtEx(pHVar4,1,1,(LPSIZE)(local_2a0 + 8)), BVar5 != 0)) &&
           (BVar5 = SetViewportExtEx(pHVar4,1,1,(LPSIZE)(local_2a0 + 8)), BVar5 != 0)) {
          FUN_45429f70(local_60,0,0x3c);
          pIVar14 = local_258;
          FUN_4541db3e(local_258,&local_260);
          local_8 = CONCAT31(local_8._1_3_,4);
          bVar3 = FUN_4541c6c2(&pIVar14->QueryInterface);
          if (bVar3) {
            bVar3 = FUN_4541c6e1(&pIVar14->QueryInterface);
            if (bVar3) {
              FUN_4541db3e(pIVar14,&local_258);
              if ((local_258 != (IUnknownVtbl *)0x0) &&
                 (UVar6 = SysStringLen((BSTR)local_258), UVar6 != 0)) {
                SysFreeString((BSTR)local_260.lpVtbl);
                pIVar2 = local_258;
                local_260.lpVtbl = (IUnknownVtbl *)0x0;
                local_270 = local_258;
                local_258 = (IUnknownVtbl *)0x0;
                if (pIVar2 != (IUnknownVtbl *)0x0) {
                  SysFreeString((BSTR)0x0);
                  local_260.lpVtbl = local_270;
                }
              }
              SysFreeString((BSTR)local_258);
            }
            else {
              local_50 = 900;
            }
          }
          else {
            local_50 = 0;
          }
          FUN_4541cd68(pIVar14,&local_25c);
          local_8._0_1_ = 5;
          if (((local_25c == (IUnknownVtbl *)0x0) ||
              (UVar6 = SysStringLen((BSTR)local_25c), IVar7.lpVtbl = local_25c, UVar6 == 0)) &&
             ((local_260.lpVtbl == (IUnknownVtbl *)0x0 ||
              (UVar6 = SysStringLen((BSTR)local_260.lpVtbl), IVar7.lpVtbl = local_260.lpVtbl,
              UVar6 == 0)))) {
            sVar8 = _wcslen(L"Arial");
            iVar13 = sVar8 + 1;
            if (0x3fffffff < iVar13) goto LAB_4541feb2;
            pIVar14 = (IUnknownVtbl *)L"Arial";
LAB_4541feca:
            pbVar9 = (byte *)AtlW2AHelper((char *)&local_2c4,(wchar_t *)pIVar14,iVar13 * 2,3);
          }
          else {
            local_270 = IVar7.lpVtbl;
            if (IVar7.lpVtbl != (IUnknownVtbl *)0x0) {
              sVar8 = _wcslen((wchar_t *)IVar7.lpVtbl);
              iVar13 = sVar8 + 1;
              pIVar14 = local_270;
              if (iVar13 < 0x40000000) goto LAB_4541feca;
            }
LAB_4541feb2:
            pbVar9 = (byte *)0x0;
          }
          iVar13 = FUN_4542a6d4(local_44,0x20,pbVar9,0x1f);
          if (iVar13 == 0) {
            if (local_265 == '\0') {
              FUN_45401be8(local_254,0);
              local_8._0_1_ = 6;
              FUN_45402004(local_254,0xffffffff);
              iVar13 = FUN_4541cded((int)local_264);
              iVar10 = FUN_4541ce0c((int)local_264);
              bVar3 = FUN_4541d38b((int)local_264);
              local_270 = (IUnknownVtbl *)(uint)bVar3;
              local_258 = (IUnknownVtbl *)
                          FUN_45401f8f(iVar13,iVar10,
                                       (undefined4 *)
                                       ((int)local_274 + *(int *)(*local_274 + 4) + 0x38));
              piVar16 = local_274;
              local_270 = (IUnknownVtbl *)FUN_45401fd1((int)local_270);
              pIVar14 = local_264;
              local_280 = FUN_4541d480((int)local_264);
              (**(code **)(**(int **)(*(int *)(*piVar16 + 4) + 0x38 + (int)piVar16) + 0x34))();
              puVar11 = FUN_45402bbb(&local_278,(OLECHAR *)local_260.lpVtbl);
              local_8._0_1_ = 7;
              if ((undefined4 *)*puVar11 == (undefined4 *)0x0) {
                pbVar9 = (byte *)0x0;
              }
              else {
                pbVar9 = (byte *)FUN_4541d9e9((undefined4 *)*puVar11);
              }
              FUN_45402014(local_254,pbVar9,0,local_258,local_280,local_270,local_2a4);
              local_8._0_1_ = 6;
              if (local_278 != (IUnknownVtbl *)0x0) {
                FUN_45404021((int *)local_278);
              }
              iVar13 = FUN_4541da6a((int)pIVar14);
              FUN_4540208b(local_254,iVar13 == 1);
              FUN_45402098(local_254,0,local_258);
              local_24._0_4_ = 0;
              local_24.decVal.Hi32 = 0;
              local_24._8_4_ = (int *)0x0;
              local_24._12_4_ = 0;
              FUN_45401d5f(local_254,pHVar4,local_27c,(LPRECT)&local_24.n2,0,0);
              local_26c = (HDC)(local_24._8_4_ - local_24._0_4_);
              local_8._0_1_ = 5;
              FUN_45401c70(local_254);
            }
            SysFreeString((BSTR)local_25c);
            SysFreeString((BSTR)local_260.lpVtbl);
            DeleteDC(pHVar4);
            local_8._0_1_ = 1;
            FUN_45413151((int *)&local_288);
            param_2 = local_264;
            goto LAB_454200e0;
          }
          SysFreeString((BSTR)local_25c);
          SysFreeString((BSTR)local_260.lpVtbl);
        }
        DeleteDC(pHVar4);
      }
    }
    FUN_45413151((int *)&local_288);
  }
  else {
    bVar3 = FUN_45402d4b(&local_290,L"ZFBF");
    if (bVar3) {
      FUN_4540e34a(local_6c);
      local_2b4._8_4_ = param_2->AddRef;
      local_8._0_1_ = 8;
      local_2b4.n2.vt = 9;
      if ((_func_5022 *)local_2b4._8_4_ != (_func_5022 *)0x0) {
        (**(code **)(*(int *)local_2b4._8_4_ + 4))();
      }
      piVar16 = local_274;
      local_8._0_1_ = 9;
      local_2a4 = *(int **)(*(int *)(*local_274 + 4) + 0x38 + (int)local_274);
      local_2a0._0_2_ = 9;
      local_2a0._8_4_ = local_2a4;
      if (local_2a4 != (int *)0x0) {
        local_2b4._12_4_ = 0x454201f8;
        (**(code **)(*local_2a4 + 4))();
      }
      local_8._0_1_ = 10;
      local_2a4 = *(int **)(*(int *)(*piVar16 + 4) + 0x34 + (int)piVar16);
      local_24.n2.vt = 9;
      local_24._8_4_ = local_2a4;
      if (local_2a4 != (int *)0x0) {
        local_2b4._12_4_ = 0x45420219;
        (**(code **)(*local_2a4 + 4))();
      }
      local_8._0_1_ = 0xb;
      local_288 = (HDC)0x0;
      local_284 = 0;
      local_2b4.decVal.Hi32 = local_24._0_4_;
      local_2b4._8_4_ = local_24.decVal.Hi32;
      local_2b4._12_4_ = local_24._8_4_;
      local_2a4 = (int *)local_24._12_4_;
      uStack_2c0 = local_2a0._0_4_;
      UStack_2bc = local_2a0._4_4_;
      piStack_2b8 = (int *)local_2a0._8_4_;
      local_2b4._0_4_ = local_2a0._12_4_;
      local_2c4 = (int *)local_24._8_4_;
      iVar13 = FUN_4540e43b(local_6c,&local_288,local_2a0._12_4_,local_24._0_4_,
                            (undefined4 *)local_24.decVal.Hi32);
      if (-1 < iVar13) {
        local_26c = local_288;
        FUN_45402881(&local_278);
        piVar1 = local_274;
        local_8._0_1_ = 0xc;
        piVar16 = *(int **)(*(int *)(*local_274 + 4) + 0x38 + (int)local_274);
        if (piVar16 != (int *)0x0) {
          (**(code **)(*piVar16 + 4))();
        }
        FUN_45403583((int)local_26c,0.0,piVar16);
        pIVar14 = local_264;
        (**(code **)(*(int *)local_264->AddRef + 0x7c))();
        CComQIPtr<>(&local_258,(undefined4 *)pIVar14->AddRef);
        if (local_258 != (IUnknownVtbl *)0x0) {
          CComQIPtr<>(&local_25c,&local_258->QueryInterface);
          local_8._0_1_ = 0xe;
          if (local_25c != (IUnknownVtbl *)0x0) {
            local_260.lpVtbl = *(IUnknownVtbl **)(*(int *)(*piVar1 + 4) + 0x38 + (int)piVar1);
            if (local_260.lpVtbl != (IUnknownVtbl *)0x0) {
              (**(code **)((local_260.lpVtbl)->QueryInterface + 4))();
            }
            local_8._0_1_ = 0xf;
            FUN_454063b5((int *)&local_25c,&local_260);
            local_8._0_1_ = 0xe;
            if (local_260.lpVtbl != (IUnknownVtbl *)0x0) {
              (**(code **)((local_260.lpVtbl)->QueryInterface + 8))();
            }
          }
          local_8._0_1_ = 0xd;
          if (local_25c != (IUnknownVtbl *)0x0) {
            (**(code **)(local_25c->QueryInterface + 8))();
          }
        }
        local_8._0_1_ = 0xc;
        if (local_258 != (IUnknownVtbl *)0x0) {
          (**(code **)(local_258->QueryInterface + 8))();
        }
        local_8._0_1_ = 0xb;
        FUN_45402c42(&local_278);
      }
      VariantClear((VARIANTARG *)&local_24.n2);
      VariantClear((VARIANTARG *)local_2a0);
      VariantClear((VARIANTARG *)&local_2b4.n2);
      local_8._0_1_ = 1;
      FUN_4540e3e0(local_6c);
      param_2 = local_264;
    }
    else if (*(int *)(*(int *)(*local_274 + 4) + 0xdc + (int)local_274) != 0) {
      bVar3 = FUN_4541d38b((int)param_2);
      local_260.lpVtbl = (IUnknownVtbl *)(uint)bVar3;
      bVar3 = FUN_4541cb1d((int)param_2);
      local_280 = (uint)bVar3;
      FUN_4541db3e(local_258,&local_264);
      local_8 = CONCAT31(local_8._1_3_,0x10);
      if (local_260.lpVtbl != (IUnknownVtbl *)0x0) {
        iVar13 = 1;
        FUN_4541dad8(local_258,&local_25c);
        if ((local_25c != (IUnknownVtbl *)0x0) &&
           (UVar6 = SysStringLen((BSTR)local_25c), UVar6 != 0)) {
          SysFreeString((BSTR)local_264);
          pIVar14 = local_25c;
          local_264 = (IUnknownVtbl *)0x0;
          local_278 = local_25c;
          local_25c = (IUnknownVtbl *)0x0;
          if (pIVar14 != (IUnknownVtbl *)0x0) {
            SysFreeString((BSTR)0x0);
            local_264 = local_278;
          }
        }
        SysFreeString((BSTR)local_25c);
      }
      pIVar14 = local_258;
      if (local_280 != 0) {
        iVar13 = 3 - (uint)(iVar13 != 1);
      }
      iVar10 = FUN_45414de7((int *)local_258);
      if (iVar10 == 1) {
        pOVar15 = extraout_ECX;
        IVar7.lpVtbl = local_260.lpVtbl;
        FUN_4540288a(&stack0xfffffd34,(int *)&local_27c);
        local_26c = (HDC)FUN_4541c617(pIVar14,pOVar15,(int)IVar7.lpVtbl);
      }
      else {
        piVar16 = *(int **)(*(int *)(*local_274 + 4) + 0xdc + (int)local_274);
        (**(code **)(*piVar16 + 0x20))(piVar16,local_264,iVar13);
      }
      FUN_4541d9ab(&pIVar14->QueryInterface);
      local_8._0_1_ = 1;
      SysFreeString((BSTR)local_264);
      param_2 = param_2;
    }
LAB_454200e0:
    if (local_265 == '\0') {
      pHVar12 = (HDC)FUN_4541cd14((int)param_2);
      FUN_45421dd2((void *)(*(int *)(*local_274 + 4) + (int)local_274),(int)local_26c,'\x01',
                   (void *)0x1);
      local_26c = (HDC)extraout_EAX;
      iVar13 = FUN_4541d480((int)param_2);
      local_26c = (HDC)(int)((float)(int)local_26c * ((float)iVar13 / _DAT_4544748c));
      (**(code **)(*(int *)param_2->AddRef + 0x7c))();
      pHVar4 = local_26c;
      iVar13 = FUN_4541cbf2((int)param_2);
      if (pHVar12 != pHVar4) {
        if (iVar13 == 0x10e) {
          FUN_4541cd4c((int)param_2);
          (**(code **)(*(int *)param_2->AddRef + 0x38))();
        }
        else if (iVar13 == 0xb4) {
          FUN_4541cd30((int)param_2);
          (**(code **)(*(int *)param_2->AddRef + 0x30))();
        }
      }
    }
  }
  SysFreeString(local_290);
  SysFreeString(local_27c);
LAB_45420546:
  FUN_4542a957();
  return;
}


