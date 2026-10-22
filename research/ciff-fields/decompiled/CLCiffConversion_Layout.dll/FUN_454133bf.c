// Source: CLCiffConversion_Layout.dll @ 454133bf; FUN_454133bf

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_454133bf(void *this,int param_1,int param_2)

{
  undefined1 uVar1;
  bool bVar2;
  UINT UVar3;
  HDC pHVar4;
  size_t sVar5;
  byte *pbVar6;
  HGDIOBJ h;
  HFONT extraout_EAX;
  int extraout_EAX_00;
  int *piVar7;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  int iVar8;
  code *pcVar9;
  HFONT _Str;
  uint uVar10;
  int iVar11;
  int *piVar12;
  float10 fVar13;
  HFONT pHVar14;
  BSTR pOVar15;
  int *piStack_1d8;
  int *piStack_1d4;
  int **ppiStack_1d0;
  int *piStack_1cc;
  int iStack_1c8;
  int *piStack_1c4;
  int iStack_1c0;
  int *piStack_1bc;
  undefined4 uStack_1b8;
  int *piStack_1b4;
  undefined4 uStack_1b0;
  HFONT pHStack_1ac;
  undefined1 *puStack_1a8;
  HDC pHVar16;
  BSTR pOVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  VARIANTARG local_128;
  VARIANTARG local_118;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  _union_2683 local_f8;
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  int local_c4;
  int local_c0;
  HDC local_bc;
  BSTR local_b8;
  int *local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  BSTR local_a4;
  int local_a0;
  int *local_9c;
  undefined4 local_98;
  int *local_94;
  BSTR local_90;
  BSTR local_8c;
  BSTR local_88;
  int local_84;
  HDC local_80;
  char local_79;
  HDC local_78;
  int local_74;
  int local_70;
  byte local_69;
  BSTR local_68;
  BSTR local_64;
  HFONT local_60;
  HFONT local_5c;
  int *local_58;
  HFONT local_54;
  LOGFONTA local_50;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x118;
  local_8 = 0x454133ce;
  local_54 = (HFONT)((uint)local_54 & 0xffffff00);
  local_68 = this;
  FUN_45429f70((uint *)&local_118,0,0x10);
  VariantInit(&local_118);
  local_8 = 0;
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
  FUN_454028ee(&local_64,L"##DEMO_FIELD##");
  local_8._0_1_ = 1;
  (**(code **)(*piVar12 + 0x28))();
  SysFreeString(local_64);
  FUN_45429f70((uint *)&local_128,0,0x10);
  VariantInit(&local_128);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this) + 0x474))();
  CComQIPtr<>(&local_b4,(undefined4 *)local_128.n1._8_4_);
  local_8._0_1_ = 3;
  FUN_454028ee(&local_b8,L"Arial");
  local_a8 = 0;
  local_b0 = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this) + 0x3c))();
  (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this) + 0x3c))();
  (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x34 + (int)this) + 0x54))();
  iVar8 = local_b0;
  if (local_c0 == 0) {
    fVar13 = FUN_45406d0a(*(int *)(*(int *)this + 4) + (int)this);
    local_64 = (BSTR)(float)fVar13;
    local_b0 = (int)((float)iVar8 / (float)local_64 + DAT_45447488);
  }
  iVar8 = local_a8;
  if (local_b0 < local_a8) {
    iVar8 = local_b0;
  }
  if (local_c0 == 1) {
    local_a8 = iVar8;
    fVar13 = FUN_45406d0a(*(int *)(*(int *)this + 4) + (int)this);
    local_64 = (BSTR)(float)fVar13;
    iVar8 = (int)((float)iVar8 / (float)local_64 + DAT_45447488);
  }
  local_a4 = (BSTR)(iVar8 / 0xfa);
  if (iVar8 / 0xfa < 0xf) {
    local_a4 = (BSTR)0xf;
  }
  piVar12 = (int *)0x0;
  local_9c = (int *)0x0;
  local_a8 = iVar8;
  (**(code **)(*local_b4 + 0x24))();
  local_80 = (HDC)0x0;
  pOVar15 = extraout_ECX;
  pcVar9 = VariantClear_exref;
  if (0 < local_c4) {
    do {
      FUN_45429f70((uint *)&local_f8,0,0x10);
      VariantInit((VARIANTARG *)&local_f8.n2);
      local_80 = (HDC)((int)&local_80->unused + 1);
      local_8._0_1_ = 5;
      (**(code **)(*local_b4 + 0x20))();
      piVar12 = local_9c;
      if (local_f8.n2.vt != 0) {
        CComQIPtr<>(&local_78,(undefined4 *)local_f8._8_4_);
        local_88 = (BSTR)0x0;
        local_8._0_1_ = 7;
        (**(code **)(local_78->unused + 0x1c))();
        UVar3 = SysStringLen(local_88);
        if (UVar3 != 0) {
          FUN_45404d15(&local_b8,(int *)&local_88);
          local_90 = (BSTR)0x0;
          local_8._0_1_ = 8;
          (**(code **)(local_78->unused + 0x9c))();
          bVar2 = FUN_45402d4b(&local_90,L"FixedBitmap");
          if (bVar2) {
            (**(code **)(local_78->unused + 0x3c))();
            FUN_45429f70((uint *)local_e4,0,0x10);
            VariantInit((VARIANTARG *)local_e4);
            local_8._0_1_ = 9;
            (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x6c + (int)this) + 0x7c))();
            if (local_e4._0_2_ != 0) {
              CComQIPtr<>(&local_60,(undefined4 *)local_e4._8_4_);
              local_8._0_1_ = 10;
              if (local_60 != (HFONT)0x0) {
                local_5c = (HFONT)0x0;
                (**(code **)(local_60->unused + 0x24))();
                if (0 < (int)local_5c) {
                  puStack_1a8 = (undefined1 *)0x4541372e;
                  FUN_45429f70((uint *)local_d4,0,0x10);
                  VariantInit((VARIANTARG *)local_d4);
                  local_8._0_1_ = 0xb;
                  puStack_1a8 = (undefined1 *)0x45413755;
                  (**(code **)(local_60->unused + 0x30))();
                  puStack_1a8 = local_d4;
                  if (local_d4._0_2_ == 0) {
                    pHStack_1ac = (HFONT)0x45413768;
                    (*pcVar9)();
                    local_8._0_1_ = 9;
                    if (local_60 != (HFONT)0x0) {
                      pHStack_1ac = local_60;
                      uStack_1b0 = 0x45413779;
                      (**(code **)(local_60->unused + 8))();
                    }
                    pHStack_1ac = (HFONT)local_e4;
                    uStack_1b0 = 0x45413782;
                    (*pcVar9)();
                    SysFreeString(local_90);
                    goto LAB_4541380c;
                  }
                  pHStack_1ac = (HFONT)0x45413792;
                  (*pcVar9)();
                }
              }
              local_8._0_1_ = 9;
              if (local_60 != (HFONT)0x0) {
                (**(code **)(local_60->unused + 8))();
              }
            }
            local_a4 = local_64;
            local_8._0_1_ = 8;
            (*pcVar9)();
          }
          (**(code **)(local_78->unused + 0x4c))();
          pHVar4 = local_78;
          local_54 = (HFONT)((uint)local_54 & 0xff);
          if (local_104 != 0) {
            local_54 = (HFONT)0x1;
          }
          local_bc = local_78;
          if (local_78 != (HDC)0x0) {
            (**(code **)(local_78->unused + 4))();
          }
          local_8._0_1_ = 0xc;
          if (pHVar4 != (HDC)0x0) {
            pOVar15 = (BSTR)FUN_454298b4(4);
            local_8._0_1_ = 0xd;
            local_64 = pOVar15;
            if (pOVar15 == (BSTR)0x0) {
              local_9c = (int *)0x0;
            }
            else {
              pHVar16 = pHVar4;
              (**(code **)(pHVar4->unused + 4))();
              local_9c = FUN_45412a60(pOVar15,&pHVar16->unused);
            }
            piVar12 = local_9c;
            local_8._0_1_ = 8;
            (**(code **)(pHVar4->unused + 8))();
            SysFreeString(local_90);
            SysFreeString(local_88);
            local_8._0_1_ = 5;
            if (local_78 != (HDC)0x0) {
              (**(code **)(local_78->unused + 8))();
            }
            local_8 = CONCAT31(local_8._1_3_,4);
            VariantClear((VARIANTARG *)&local_f8.n2);
            pOVar15 = extraout_ECX_01;
            break;
          }
          SysFreeString(local_90);
          pcVar9 = VariantClear_exref;
        }
LAB_4541380c:
        SysFreeString(local_88);
        local_8._0_1_ = 5;
        if (local_78 != (HDC)0x0) {
          (**(code **)(local_78->unused + 8))();
        }
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      (*pcVar9)();
      pOVar15 = extraout_ECX_00;
    } while ((int)local_80 < local_c4);
  }
  uVar19 = 0x32;
  pOVar17 = local_a4;
  uVar18 = local_118.n1._8_4_;
  FUN_4540288a(&stack0xfffffe7c,(int *)&local_b8);
  FUN_4541ae0c(this,pOVar15,pOVar17,(undefined4 *)uVar18,uVar19);
  CComQIPtr<>(&local_58,(undefined4 *)local_118.n1._8_4_);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  (**(code **)(*local_58 + 0xc4))();
  (**(code **)(*local_58 + 0x110))();
  (**(code **)(*local_58 + 0x28))();
  (**(code **)(*local_58 + 0x48))();
  (**(code **)(*local_58 + 0x50))();
  puStack_1a8 = (undefined1 *)0x45413945;
  (**(code **)(*local_58 + 0x40))();
  puStack_1a8 = (undefined1 *)0x3;
  pHStack_1ac = (HFONT)local_58;
  uStack_1b0 = 0x45413950;
  (**(code **)(*local_58 + 0x58))();
  uStack_1b0 = 0;
  piStack_1b4 = local_58;
  uStack_1b8 = 0x4541395d;
  (**(code **)(*local_58 + 0x94))();
  uStack_1b8 = 0;
  piStack_1bc = local_58;
  iStack_1c0 = 0x4541396a;
  (**(code **)(*local_58 + 0xcc))();
  iStack_1c0 = param_1;
  piStack_1c4 = local_58;
  iStack_1c8 = 0x45413976;
  (**(code **)(*local_58 + 0x30))();
  iStack_1c8 = param_2;
  piStack_1cc = local_58;
  ppiStack_1d0 = (int **)0x45413982;
  (**(code **)(*local_58 + 0x38))();
  if (*(char *)((int)this + 4) != '\0') {
    ppiStack_1d0 = (int **)0x1;
    piStack_1d4 = local_58;
    piStack_1d8 = (int *)0x45413996;
    (**(code **)(*local_58 + 0x8c))();
  }
  local_70 = 0;
  local_54 = (HFONT)0x0;
  ppiStack_1d0 = (int **)0x454139a7;
  FUN_45412a39(&local_98);
  ppiStack_1d0 = &local_94;
  piStack_1d4 = (int *)&DAT_454486ec;
  piStack_1d8 = local_58;
  local_8._0_1_ = 0xf;
  (**(code **)*local_58)();
  FUN_4541c774(&local_98,&local_8c);
  local_8._0_1_ = 0x10;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 0x10;
  if ((piVar12 == (int *)0x0) ||
     (bVar2 = FUN_4541e8f1(piVar12), uVar1 = (undefined1)local_8, !bVar2)) {
    local_8._0_1_ = uVar1;
    if ((*(int *)(*(int *)(*(int *)this + 4) + 0xdc + (int)this) != 0) && (piVar12 != (int *)0x0)) {
      local_69 = FUN_4541d38b((int)&local_98);
      local_79 = FUN_4541cb1d((int)&local_98);
      FUN_4541db3e(piVar12,&local_5c);
      bVar2 = local_69 != 0;
      local_8 = CONCAT31(local_8._1_3_,0x14);
      if (bVar2) {
        piVar7 = FUN_4541dad8(piVar12,&local_68);
        FUN_454066f3(&local_5c,piVar7);
        SysFreeString(local_68);
      }
      uVar10 = (uint)bVar2;
      if (local_79 != '\0') {
        uVar10 = 3 - (uVar10 != 1);
      }
      iVar8 = FUN_45414de7(piVar12);
      if (iVar8 == 1) {
        uVar10 = (uint)local_69;
        pOVar15 = (BSTR)0x1;
        FUN_4540288a(&stack0xfffffe20,(int *)&local_8c);
        local_70 = FUN_4541c617(piVar12,pOVar15,uVar10);
      }
      else {
        piVar7 = *(int **)(*(int *)(*(int *)this + 4) + 0xdc + (int)this);
        (**(code **)(*piVar7 + 0x20))(piVar7,local_5c,uVar10);
      }
      local_54 = (HFONT)FUN_4541d9ab(piVar12);
      local_8._0_1_ = 0x10;
      SysFreeString((BSTR)local_5c);
    }
    goto LAB_45413d50;
  }
  local_bc = GetDC((HWND)0x0);
  pHVar4 = CreateCompatibleDC(local_bc);
  local_e4._8_4_ = (undefined4 *)0x0;
  local_e4._12_4_ = 0;
  local_80 = pHVar4;
  SetMapMode(pHVar4,8);
  SetWindowExtEx(pHVar4,1,1,(LPSIZE)(local_e4 + 8));
  SetViewportExtEx(pHVar4,1,1,(LPSIZE)(local_e4 + 8));
  FUN_45429f70((uint *)&local_50,0,0x3c);
  _Str = (HFONT)0x0;
  local_60 = (HFONT)0x0;
  local_8._0_1_ = 0x11;
  bVar2 = FUN_4541c6c2(piVar12);
  if (bVar2) {
    FUN_4541dad8(piVar12,&local_54);
    local_8 = CONCAT31(local_8._1_3_,0x12);
    bVar2 = FUN_4541c6e1(piVar12);
    if ((bVar2) && (UVar3 = SysStringLen((BSTR)local_54), UVar3 != 0)) {
      FUN_45404d15(&local_60,(int *)&local_54);
      _Str = local_60;
    }
    else {
      local_50.lfWeight = 900;
    }
    local_8._0_1_ = 0x11;
    SysFreeString((BSTR)local_54);
  }
  else {
    piVar7 = FUN_4541db3e(piVar12,&local_54);
    FUN_454066f3(&local_60,piVar7);
    SysFreeString((BSTR)local_54);
    local_50.lfWeight = 0;
    _Str = local_60;
  }
  FUN_4541cd68(piVar12,&local_5c);
  local_8 = CONCAT31(local_8._1_3_,0x13);
  UVar3 = SysStringLen((BSTR)local_5c);
  if (UVar3 == 0) {
    if (_Str != (HFONT)0x0) {
      sVar5 = _wcslen((wchar_t *)_Str);
      iVar8 = sVar5 + 1;
      pHVar14 = _Str;
      if (iVar8 < 0x40000000) goto LAB_45413b43;
    }
LAB_45413b2f:
    pbVar6 = (byte *)0x0;
  }
  else {
    local_54 = local_5c;
    if (local_5c == (HFONT)0x0) goto LAB_45413b2f;
    sVar5 = _wcslen((wchar_t *)local_5c);
    iVar8 = sVar5 + 1;
    pHVar14 = local_54;
    if (0x3fffffff < iVar8) goto LAB_45413b2f;
LAB_45413b43:
    pbVar6 = (byte *)AtlW2AHelper((char *)&piStack_1d8,(wchar_t *)pHVar14,iVar8 * 2,3);
  }
  FUN_4542a6d4((byte *)local_50.lfFaceName,0x20,pbVar6,0x1f);
  local_50.lfCharSet = '\x01';
  (**(code **)(**(int **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this) + 0x2c))();
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this);
  (**(code **)(*piVar12 + 0x34))(piVar12,&local_64);
  local_64 = (BSTR)((float)local_64 * _DAT_4544748c * _DAT_45447a30);
  iVar8 = FUN_45404072((float)local_64);
  local_50.lfHeight = MulDiv((int)local_a4,iVar8,0x48);
  local_50.lfHeight = -local_50.lfHeight;
  local_60 = CreateFontIndirectA(&local_50);
  h = SelectObject(local_80,local_60);
  UVar3 = SysStringLen(local_8c);
  local_d4._8_4_ = 0;
  local_d4._12_4_ = (HFONT)0x0;
  GetTextExtentPoint32W(local_80,local_8c,UVar3,(LPSIZE)(local_d4 + 8));
  pHVar4 = local_80;
  local_70 = (local_d4._8_4_ * 0x32) / 100;
  local_54 = (HFONT)local_d4._12_4_;
  SelectObject(local_80,h);
  DeleteObject(local_60);
  DeleteDC(pHVar4);
  ReleaseDC((HWND)0x0,local_bc);
  SysFreeString((BSTR)local_5c);
  local_8._0_1_ = 0x10;
  SysFreeString((BSTR)_Str);
  this = local_68;
  piVar12 = local_9c;
LAB_45413d50:
  FUN_45421dd2((void *)(*(int *)(*(int *)this + 4) + (int)this),(int)local_54,'\0',(void *)0x1);
  local_54 = extraout_EAX;
  (**(code **)(*local_94 + 0x84))();
  FUN_45421dd2((void *)(*(int *)(*(int *)this + 4) + (int)this),local_70,'\x01',(void *)0x1);
  local_70 = extraout_EAX_00;
  (**(code **)(*local_94 + 0x7c))(local_94,extraout_EAX_00);
  if (piVar12 != (int *)0x0) {
    local_5c = (HFONT)0x0;
    local_8 = CONCAT31(local_8._1_3_,0x15);
    bVar2 = FUN_4541e626(this);
    if (bVar2) {
      piVar7 = FUN_45409640(&local_68);
      FUN_454066f3(&local_5c,piVar7);
      SysFreeString(local_68);
    }
    FUN_454214e8(&local_98,piVar12,local_a4,(int *)&local_5c);
    local_8._0_1_ = 0x10;
    SysFreeString((BSTR)local_5c);
    FUN_45412f4b(piVar12);
    FID_conflict__free(piVar12);
  }
  FUN_4541cd30((int)&local_98);
  FUN_4541cd14((int)&local_98);
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
  (**(code **)(*piVar12 + 0x3c))(piVar12,&local_a0);
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
  (**(code **)(*piVar12 + 0x44))(piVar12,&local_ac);
  local_74 = 0;
  local_84 = 0;
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this);
  (**(code **)(*piVar12 + 0x3c))(piVar12,&local_74);
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this);
  (**(code **)(*piVar12 + 0x44))(piVar12,&local_84);
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
  (**(code **)(*piVar12 + 0x5c))(piVar12,&local_100);
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
  (**(code **)(*piVar12 + 100))(piVar12,&local_108);
  piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x34 + (int)this);
  (**(code **)(*piVar12 + 0x54))(piVar12,&local_fc);
  iVar8 = local_74;
  if (local_fc == 0) {
    fVar13 = FUN_45406d0a(*(int *)(*(int *)this + 4) + (int)this);
    iVar11 = local_84;
    local_68 = (BSTR)(float)fVar13;
    local_74 = (int)((float)iVar8 / (float)local_68 + DAT_45447488);
    fVar13 = FUN_45406d0a(*(int *)(*(int *)this + 4) + (int)this);
    local_68 = (BSTR)(float)fVar13;
    local_84 = (int)((float)iVar11 / (float)local_68 + DAT_45447488);
  }
  if (local_a0 < local_100) {
    local_100 = local_a0;
  }
  local_a0 = local_74;
  if (local_100 < local_74) {
    local_a0 = local_100;
  }
  if (local_ac < local_108) {
    local_108 = local_ac;
  }
  local_ac = local_84;
  if (local_108 < local_84) {
    local_ac = local_108;
  }
  if ((char)*(BSTR)((int)this + 4) == '\0') {
    local_68 = (BSTR)((int)&local_54->unused + param_2);
    iVar8 = local_70 + param_1;
    (**(code **)(*local_58 + 0x30))(local_58,param_1);
    (**(code **)(*local_58 + 0x38))(local_58,param_2);
    if ((0 < local_74) && (local_74 < iVar8)) {
      param_1 = local_74 - local_70;
      (**(code **)(*local_58 + 0x30))(local_58,param_1);
    }
    if ((0 < local_84) && (local_84 < (int)local_68)) {
      param_2 = local_84 - (int)local_54;
      (**(code **)(*local_58 + 0x38))(local_58,param_2);
    }
    iVar8 = (int)&local_54->unused + param_2;
    if (local_ac < iVar8) {
      iVar11 = local_84;
      if (iVar8 < local_84) {
        iVar11 = iVar8;
      }
      piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
      (**(code **)(*piVar12 + 0x48))(piVar12,iVar11);
      piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
      (**(code **)(*piVar12 + 0x68))(piVar12,iVar11);
    }
  }
  iVar8 = local_70 + param_1;
  if (local_a0 < iVar8) {
    local_70 = local_74;
    if (iVar8 < local_74) {
      local_70 = iVar8;
    }
    piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
    (**(code **)(*piVar12 + 0x40))(piVar12,local_70);
    piVar12 = *(int **)(*(int *)(*(int *)this + 4) + 0x5c + (int)this);
    (**(code **)(*piVar12 + 0x60))(piVar12,local_70);
  }
  SysFreeString(local_8c);
  local_8._0_1_ = 0xe;
  if (local_94 != (int *)0x0) {
    (**(code **)(*local_94 + 8))(local_94);
  }
  local_8._0_1_ = 4;
  if (local_58 != (int *)0x0) {
    (**(code **)(*local_58 + 8))(local_58);
  }
  SysFreeString(local_b8);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_b4 != (int *)0x0) {
    (**(code **)(*local_b4 + 8))(local_b4);
  }
  VariantClear(&local_128);
  VariantClear(&local_118);
  FUN_4542a957();
  return;
}


