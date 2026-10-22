// Source: CLCiffConversion_Data.dll @ 45029bff; FUN_45029bff

void __cdecl FUN_45029bff(FILE *param_1,WCHAR *param_2,int *param_3,int *param_4)

{
  byte *pbVar1;
  size_t _DstSizeInBytes;
  wchar_t wVar2;
  ushort uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  char *_Dst;
  errno_t eVar7;
  code *pcVar8;
  uint uVar9;
  FILE *pFVar10;
  void *this;
  void *this_00;
  void *this_01;
  FILE *extraout_ECX;
  FILE *extraout_ECX_00;
  WCHAR WVar11;
  char cVar12;
  short sVar13;
  WCHAR WVar14;
  FILE *pFVar15;
  WCHAR *pWVar16;
  uint uVar17;
  uint uVar18;
  WCHAR *pWVar19;
  bool bVar20;
  longlong lVar21;
  char *pcVar22;
  void *pvVar23;
  int local_350 [2];
  int local_348;
  char local_344;
  int local_340;
  int *local_33c;
  int *local_338;
  uint local_334;
  int local_330;
  FILE *local_32c;
  uint local_328;
  int local_324;
  byte local_31d;
  uint local_31c;
  uint local_318;
  int local_314;
  FILE *local_310;
  uint local_30c;
  uint local_308;
  WCHAR *local_304;
  char local_2fd;
  wchar_t *local_2fc;
  char local_2f5;
  uint local_2f4;
  uint *local_2f0;
  uint local_2ec;
  char local_2e5;
  FILE *local_2e4;
  WCHAR *local_2e0;
  char local_2d9;
  FILE *local_2d8;
  uint local_2d4;
  char local_2cd;
  void *local_2cc;
  char local_2c6;
  byte local_2c5;
  wchar_t local_2c4 [350];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_338 = param_4;
  local_2e4 = param_1;
  local_2fc = local_2c4;
  local_2e0 = param_2;
  local_328 = 0x15e;
  local_330 = 0;
  local_2f0 = (uint *)0x0;
  local_340 = 0;
  local_31c = 0;
  local_308 = 0;
  local_33c = (int *)0x0;
  local_2cc = (void *)0x0;
  if ((param_2 == (WCHAR *)0x0) || (param_1 == (FILE *)0x0)) {
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_45027e29();
    lVar21 = CONCAT44(local_308,local_31c);
    goto LAB_4502b010;
  }
  FUN_45021444(local_350,param_3);
  lVar21 = CONCAT44(local_308,local_31c);
  uVar18 = 0;
  local_2c6 = '\0';
  local_2d4 = 0;
  local_2f4 = 0;
  WVar11 = *local_2e0;
  local_324 = 0;
  if (WVar11 != L'\0') {
LAB_45029cce:
    local_308 = (uint)((ulonglong)lVar21 >> 0x20);
    local_31c = (uint)lVar21;
    pFVar10 = (FILE *)0x0;
    pvVar23 = (void *)0x8;
    uVar5 = FUN_45027796(WVar11,8);
    pWVar16 = local_2e0;
    pFVar15 = local_2e4;
    if (uVar5 != 0) {
      local_2f4 = uVar18 - 1;
      uVar18 = __whiteout(pvVar23,(int *)&local_2f4,local_2e4);
      FUN_45029bb4(uVar18 & 0xffff,pFVar15);
      pWVar16 = local_2e0;
      do {
        pWVar16 = pWVar16 + 1;
        uVar18 = FUN_45027796(*pWVar16,8);
        lVar21 = CONCAT44(local_308,local_31c);
      } while (uVar18 != 0);
      local_2d4 = local_2f4;
      uVar18 = local_2f4;
      local_2e0 = pWVar16;
      goto LAB_4502af3c;
    }
    if (*local_2e0 != L'%') {
LAB_4502aec9:
      uVar18 = uVar18 + 1;
      local_2f4 = uVar18;
      local_2d4 = uVar18;
      uVar5 = FUN_45033833(pWVar16,local_2e4);
      lVar21 = CONCAT44(local_308,local_31c);
      pvVar23 = (void *)(uVar5 & 0xffff);
      WVar11 = *local_2e0;
      local_2e0 = local_2e0 + 1;
      local_2cc = pvVar23;
      if (WVar11 != (WCHAR)uVar5) {
LAB_4502af60:
        FUN_45029bb4(local_2cc,pFVar15);
        goto LAB_4502a3b4;
      }
      goto LAB_4502af07;
    }
    if (local_2e0[1] == L'%') {
      if (local_2e0[1] == L'%') {
        local_2e0 = local_2e0 + 1;
      }
      goto LAB_4502aec9;
    }
    local_318 = 0;
    local_334 = 0;
    cVar12 = '\0';
    local_30c = 0;
    local_314 = 0;
    local_2d8 = (FILE *)0x0;
    local_32c = (FILE *)0x0;
    local_31d = 0;
    local_2f5 = '\0';
    local_2cd = '\0';
    local_2fd = '\0';
    local_2e5 = '\0';
    local_2c5 = 0;
    local_2d9 = '\x01';
    local_310 = (FILE *)0x0;
    pFVar15 = pFVar10;
    do {
      pWVar19 = pWVar16 + 1;
      uVar18 = (uint)(ushort)*pWVar19;
      if (((*pWVar19 & 0xff00U) == 0) &&
         (iVar6 = _isdigit(uVar18 & 0xff), pFVar10 = local_310, cVar12 = local_2fd, iVar6 != 0)) {
        local_314 = local_314 + 1;
        pFVar15 = (FILE *)((uVar18 - 0x30) + (int)pFVar15 * 10);
      }
      else if (uVar18 < 0x4f) {
        if (uVar18 != 0x4e) {
          if (uVar18 == 0x2a) {
            local_2cd = local_2cd + '\x01';
          }
          else if (uVar18 != 0x46) {
            if (uVar18 == 0x49) {
              WVar11 = pWVar16[2];
              if ((WVar11 == L'6') && (pWVar16[3] == L'4')) {
                pWVar16 = pWVar16 + 3;
                pFVar10 = local_310;
                goto LAB_45029e49;
              }
              if ((WVar11 == L'3') && (pWVar16[3] == L'2')) {
                pWVar19 = pWVar16 + 3;
                pFVar10 = local_310;
              }
              else {
                pFVar10 = local_310;
                if ((WVar11 != L'd') &&
                   ((((WVar11 != L'i' && (WVar11 != L'o')) && (WVar11 != L'x')) && (WVar11 != L'X'))
                   )) goto LAB_45029f21;
              }
            }
            else if (uVar18 == 0x4c) {
              local_2d9 = local_2d9 + '\x01';
            }
            else {
LAB_45029f21:
              cVar12 = cVar12 + '\x01';
              pFVar10 = local_310;
              local_2fd = cVar12;
            }
          }
        }
      }
      else if (uVar18 == 0x68) {
        local_2d9 = local_2d9 + -1;
        local_2c5 = local_2c5 - 1;
      }
      else {
        if (uVar18 == 0x6c) {
          pWVar16 = pWVar16 + 2;
          if (*pWVar16 == L'l') {
LAB_45029e49:
            local_31c = 0;
            local_310 = (FILE *)((int)&pFVar10->_ptr + 1);
            local_308 = 0;
            pFVar10 = local_310;
            pWVar19 = pWVar16;
            goto LAB_45029e7b;
          }
          local_2d9 = local_2d9 + '\x01';
        }
        else if (uVar18 != 0x77) goto LAB_45029f21;
        local_2c5 = local_2c5 + 1;
      }
LAB_45029e7b:
      uVar5 = local_334;
      pWVar16 = pWVar19;
    } while (cVar12 == '\0');
    if (local_2cd == '\0') {
      local_33c = local_338;
      local_304 = (WCHAR *)*local_338;
      local_338 = local_338 + 1;
    }
    else {
      local_304 = (WCHAR *)0x0;
    }
    uVar17 = (uint)local_2c5;
    if (local_2c5 == 0) {
      if ((*pWVar19 == L'S') || (*pWVar19 == L'C')) {
        uVar17 = 0xff;
      }
      else {
        uVar17 = 1;
      }
    }
    local_2ec = (ushort)*pWVar19 | 0x20;
    uVar9 = local_2d4;
    local_2e0 = pWVar19;
    local_2d8 = pFVar15;
    if (local_2ec != 0x6e) {
      if ((local_2ec == 99) || (local_2ec == 0x7b)) {
        uVar9 = local_2d4 + 1;
        local_2f4 = uVar9;
        local_2d4 = uVar9;
        uVar18 = FUN_45033833(pFVar10,local_2e4);
      }
      else {
        uVar18 = __whiteout(pFVar10,(int *)&local_2f4,local_2e4);
        local_2d4 = local_2f4;
        uVar9 = local_2f4;
      }
      local_2cc = (void *)(uVar18 & 0xffff);
      if ((short)uVar18 != -1) goto LAB_4502a014;
      goto LAB_4502a3b4;
    }
LAB_4502a014:
    pFVar15 = local_2e4;
    lVar21 = CONCAT44(local_308,local_31c);
    if ((local_314 != 0) && (local_2d8 == (FILE *)0x0)) goto LAB_4502af60;
    cVar12 = (char)uVar17;
    if ((local_2cd != '\0') || (((local_2ec != 99 && (local_2ec != 0x73)) && (local_2ec != 0x7b))))
    {
LAB_4502a088:
      WVar11 = (WCHAR)local_2cc;
      pvVar23 = local_2cc;
      uVar18 = uVar9;
      if ((int)local_2ec < 0x70) {
        if (local_2ec == 0x6f) goto LAB_4502aac4;
        if (local_2ec == 99) {
          if (local_314 == 0) {
            local_2d8 = (FILE *)((int)&local_2d8->_ptr + 1);
            local_314 = 1;
          }
          goto LAB_4502a5bf;
        }
        if (local_2ec == 100) goto LAB_4502aac4;
        if ((int)local_2ec < 0x65) {
LAB_4502a722:
          if (*local_2e0 != WVar11) {
            FUN_45029bb4(local_2cc,local_2e4);
            lVar21 = CONCAT44(local_308,local_31c);
            bVar20 = true;
            goto LAB_4502af8e;
          }
          local_2c6 = local_2c6 + -1;
          if (local_2cd == '\0') {
            local_338 = local_33c;
          }
          goto LAB_4502a595;
        }
        if (0x67 < (int)local_2ec) {
          if (local_2ec == 0x69) {
            local_2ec = 100;
            goto LAB_4502a8a4;
          }
          if (local_2ec != 0x6e) goto LAB_4502a722;
          if (local_2cd != '\0') goto LAB_4502a595;
          goto LAB_4502ae6c;
        }
        uVar5 = 0;
        if (WVar11 == L'-') {
          uVar5 = 1;
          *local_2fc = L'-';
LAB_4502a11c:
          local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3);
          uVar9 = uVar9 + 1;
          local_2d4 = uVar9;
          uVar18 = FUN_45033833((void *)0x2d,local_2e4);
          local_2cc = (void *)(uVar18 & 0xffff);
        }
        else if (WVar11 == L'+') goto LAB_4502a11c;
        if (local_314 == 0) {
          local_2d8 = (FILE *)0xffffffff;
        }
        while (((pvVar23 = local_2cc, cVar12 = (char)local_2cc, ((uint)local_2cc & 0xff00) == 0 &&
                (iVar6 = _isdigit((uint)local_2cc & 0xff), iVar6 != 0)) &&
               (pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3),
               bVar20 = local_2d8 != (FILE *)0x0, local_2d8 = pFVar15, bVar20))) {
          local_30c = local_30c + 1;
          local_2fc[uVar5] = (short)cVar12;
          uVar5 = uVar5 + 1;
          iVar6 = FUN_45029b21(uVar5,&local_328,&local_2fc,(undefined8 *)local_2c4,&local_330);
          if (iVar6 == 0) goto LAB_4502a3b4;
          uVar9 = uVar9 + 1;
          local_2d4 = uVar9;
          uVar18 = FUN_45033833(this,local_2e4);
          local_2cc = (void *)(uVar18 & 0xffff);
        }
        wVar2 = **(wchar_t **)(*(int *)(local_350[0] + 0x84) + 0x30);
        if (((uint)(ushort)wVar2 == (int)cVar12) &&
           (pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3), bVar20 = local_2d8 != (FILE *)0x0
           , local_2d8 = pFVar15, bVar20)) {
          local_2d4 = local_2d4 + 1;
          uVar18 = FUN_45033833(pFVar15,local_2e4);
          pvVar23 = (void *)(uVar18 & 0xffff);
          local_2fc[uVar5] = wVar2;
          uVar5 = uVar5 + 1;
          local_2cc = pvVar23;
          iVar6 = FUN_45029b21(uVar5,&local_328,&local_2fc,(undefined8 *)local_2c4,&local_330);
          if (iVar6 == 0) goto LAB_4502a3b4;
          while (((((uint)pvVar23 & 0xff00) == 0 &&
                  (iVar6 = _isdigit((uint)pvVar23 & 0xff), iVar6 != 0)) &&
                 (pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3),
                 bVar20 = local_2d8 != (FILE *)0x0, local_2d8 = pFVar15, bVar20))) {
            local_30c = local_30c + 1;
            local_2fc[uVar5] = (wchar_t)pvVar23;
            uVar5 = uVar5 + 1;
            iVar6 = FUN_45029b21(uVar5,&local_328,&local_2fc,(undefined8 *)local_2c4,&local_330);
            if (iVar6 == 0) goto LAB_4502a3b4;
            local_2d4 = local_2d4 + 1;
            uVar18 = FUN_45033833(this_00,local_2e4);
            pvVar23 = (void *)(uVar18 & 0xffff);
            local_2cc = pvVar23;
          }
        }
        uVar18 = local_2d4;
        if (((local_30c != 0) && (((short)pvVar23 == 0x65 || ((short)pvVar23 == 0x45)))) &&
           (pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3), bVar20 = local_2d8 != (FILE *)0x0
           , local_2d8 = pFVar15, bVar20)) {
          local_2fc[uVar5] = L'e';
          uVar17 = uVar5 + 1;
          iVar6 = FUN_45029b21(uVar17,&local_328,&local_2fc,(undefined8 *)local_2c4,&local_330);
          if (iVar6 != 0) {
            uVar18 = local_2d4 + 1;
            uVar9 = FUN_45033833(this_01,local_2e4);
            pvVar23 = (void *)(uVar9 & 0xffff);
            local_2cc = pvVar23;
            if ((short)uVar9 == 0x2d) {
              local_2fc[uVar17] = L'-';
              uVar17 = uVar5 + 2;
              iVar6 = FUN_45029b21(uVar17,&local_328,&local_2fc,(undefined8 *)local_2c4,&local_330);
              if (iVar6 == 0) goto LAB_4502a3b4;
LAB_4502a423:
              pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3);
              bVar20 = local_2d8 != (FILE *)0x0;
              local_2d8 = pFVar15;
              if (bVar20) goto LAB_4502a49d;
              local_2d8 = (FILE *)0x0;
            }
            else if ((short)uVar9 == 0x2b) goto LAB_4502a423;
            while (((uVar5 = uVar17, ((uint)pvVar23 & 0xff00) == 0 &&
                    (iVar6 = _isdigit((uint)pvVar23 & 0xff), iVar6 != 0)) &&
                   (pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3),
                   bVar20 = local_2d8 != (FILE *)0x0, local_2d8 = pFVar15, bVar20))) {
              local_30c = local_30c + 1;
              local_2fc[uVar17] = (wchar_t)pvVar23;
              uVar17 = uVar17 + 1;
              iVar6 = FUN_45029b21(uVar17,&local_328,&local_2fc,(undefined8 *)local_2c4,&local_330);
              pFVar15 = extraout_ECX;
              if (iVar6 == 0) goto LAB_4502a3b4;
LAB_4502a49d:
              uVar18 = uVar18 + 1;
              uVar5 = FUN_45033833(pFVar15,local_2e4);
              pvVar23 = (void *)(uVar5 & 0xffff);
              local_2cc = pvVar23;
            }
            goto LAB_4502a4c3;
          }
          goto LAB_4502a3b4;
        }
LAB_4502a4c3:
        uVar18 = uVar18 - 1;
        local_2f4 = uVar18;
        local_2d4 = uVar18;
        FUN_45029bb4(pvVar23,local_2e4);
        if (local_30c == 0) goto LAB_4502a3b4;
        lVar21 = CONCAT44(local_308,local_31c);
        if (local_2cd != '\0') goto LAB_4502a595;
        local_324 = local_324 + 1;
        local_2fc[uVar5] = L'\0';
        iVar6 = local_328 * 2;
        _DstSizeInBytes = iVar6 + 2;
        _Dst = FUN_4502df29(_DstSizeInBytes);
        if (_Dst == (char *)0x0) goto LAB_4502a3b4;
        eVar7 = _wcstombs_s((size_t *)0x0,_Dst,_DstSizeInBytes,local_2fc,iVar6 + 1);
        if ((eVar7 != 0) && ((eVar7 == 0x16 || (eVar7 == 0x22)))) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        piVar4 = local_350;
        iVar6 = local_2d9 + -1;
        pWVar16 = local_304;
        pcVar22 = _Dst;
        pcVar8 = DecodePointer(PTR_LAB_450521fc);
        (*pcVar8)(iVar6,pWVar16,pcVar22,piVar4);
        FID_conflict__free(_Dst);
        goto LAB_4502a583;
      }
      if (local_2ec == 0x70) {
        local_2d9 = '\x01';
LAB_4502aac4:
        if (WVar11 == L'-') {
          local_2f5 = '\x01';
        }
        else if (WVar11 != L'+') goto LAB_4502ab1a;
        local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3);
        if ((local_2d8 == (FILE *)0x0) && (local_314 != 0)) {
          uVar17 = (uint)CONCAT11(1,cVar12);
          goto LAB_4502ab1a;
        }
        local_2f4 = uVar9 + 1;
        local_2d4 = local_2f4;
        uVar18 = FUN_45033833(local_2cc,local_2e4);
        local_2cc = (void *)(uVar18 & 0xffff);
LAB_4502a99d:
        cVar12 = (char)(uVar17 >> 8);
      }
      else {
        if (local_2ec == 0x73) {
LAB_4502a5bf:
          pWVar16 = local_2e0;
          if ('\0' < cVar12) {
            local_2e5 = '\x01';
          }
LAB_4502a5ca:
          local_2e0 = pWVar16;
          pvVar23 = local_2cc;
          pWVar16 = local_304;
          local_2f4 = local_2d4 - 1;
          pFVar15 = local_2e4;
          local_2d4 = local_2f4;
          FUN_45029bb4(local_2cc,local_2e4);
          uVar18 = local_2ec;
          if (local_2ec != 99) {
            local_32c = (FILE *)((int)&local_32c[-1]._tmpfname + 3);
          }
          do {
            if ((local_314 != 0) &&
               (pFVar15 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3),
               bVar20 = local_2d8 == (FILE *)0x0, local_2d8 = pFVar15, bVar20)) goto LAB_4502aa72;
            local_2f4 = local_2d4 + 1;
            pFVar10 = local_2e4;
            local_2d4 = local_2f4;
            uVar5 = FUN_45033833(pFVar15,local_2e4);
            pFVar15 = pFVar10;
            pvVar23 = (void *)(uVar5 & 0xffff);
            WVar11 = (WCHAR)uVar5;
            local_2cc = pvVar23;
            if (WVar11 == L'\xffff') goto LAB_4502aa51;
            if (uVar18 != 99) {
              if (uVar18 == 0x73) {
                if (((void *)0x8 < pvVar23) && (pvVar23 < (void *)0xe)) goto LAB_4502aa51;
                if (WVar11 != L' ') goto LAB_4502a6b2;
              }
              if ((uVar18 != 0x7b) ||
                 (pFVar15 = (FILE *)(int)(char)(*(byte *)(((uVar5 & 0xffff) >> 3) + (int)local_2f0)
                                               ^ local_31d),
                 ((uint)pFVar15 & 1 << ((byte)(uVar5 & 0xffff) & 7)) == 0)) goto LAB_4502aa51;
            }
LAB_4502a6b2:
            if (local_2cd == '\0') {
              if (local_32c == (FILE *)0x0) {
LAB_4502afac:
                piVar4 = __errno();
                lVar21 = CONCAT44(local_308,local_31c);
                *piVar4 = 0xc;
                if (local_2e5 != '\0') {
                  *pWVar16 = L'\0';
                  goto LAB_4502a3b4;
                }
                bVar20 = false;
                *(undefined1 *)pWVar16 = 0;
                goto LAB_4502af8e;
              }
              if (local_2e5 == '\0') {
                local_318 = 0;
                iVar6 = FUN_45033dc3((int *)&local_318,(uint *)local_304,(uint)local_32c,WVar11);
                if (iVar6 == 0x22) goto LAB_4502afac;
                pFVar15 = extraout_ECX_00;
                if (0 < (int)local_318) {
                  local_304 = (WCHAR *)((int)local_304 + local_318);
                  local_32c = (FILE *)((int)local_32c - local_318);
                }
              }
              else {
                *local_304 = WVar11;
                local_304 = local_304 + 1;
                pFVar15 = (FILE *)((int)&local_32c[-1]._tmpfname + 3);
                local_32c = pFVar15;
              }
            }
            else {
              pWVar16 = pWVar16 + 1;
            }
          } while( true );
        }
        if (local_2ec == 0x75) goto LAB_4502aac4;
        if (local_2ec != 0x78) {
          if (local_2ec != 0x7b) goto LAB_4502a722;
          if ('\0' < cVar12) {
            local_2e5 = '\x01';
          }
          pWVar16 = local_2e0 + 1;
          if (*pWVar16 == L'^') {
            pWVar16 = local_2e0 + 2;
            local_31d = 0xff;
          }
          if (local_2f0 == (uint *)0x0) {
            local_2f0 = FUN_4502df29(0x2000);
            lVar21 = CONCAT44(local_308,local_31c);
            if (local_2f0 == (uint *)0x0) {
              sVar13 = (short)local_2cc;
              bVar20 = false;
              goto LAB_4502a3c2;
            }
            local_340 = 1;
          }
          FUN_45021c10(local_2f0,0,0x2000);
          lVar21 = CONCAT44(local_308,local_31c);
          if (*pWVar16 == L']') {
            *(undefined1 *)((int)local_2f0 + 0xb) = 0x20;
            uVar5 = 0x5d;
            pWVar16 = pWVar16 + 1;
            local_334 = 0x5d;
          }
          while( true ) {
            bVar20 = false;
            WVar14 = (WCHAR)uVar5;
            WVar11 = *pWVar16;
            uVar18 = (uint)(ushort)WVar11;
            if (WVar11 == L']') break;
            pWVar19 = pWVar16 + 1;
            uVar17 = uVar18;
            if ((WVar11 == L'-') && (WVar14 != L'\0')) {
              WVar11 = *pWVar19;
              if (WVar11 != L']') {
                pWVar19 = pWVar16 + 2;
                uVar18 = (uint)(ushort)WVar11;
                if ((ushort)WVar11 <= (ushort)WVar14) {
                  uVar18 = uVar5 & 0xffff;
                  WVar14 = WVar11;
                  local_334 = (uint)(ushort)WVar11;
                }
                if ((ushort)WVar14 < (ushort)(WCHAR)uVar18) {
                  uVar5 = uVar18 - local_334 & 0xffff;
                  uVar17 = (uint)(ushort)WVar14;
                  do {
                    pbVar1 = (byte *)((uVar17 >> 3) + (int)local_2f0);
                    *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar17 & 7);
                    uVar17 = uVar17 + 1;
                    uVar5 = uVar5 - 1;
                  } while (uVar5 != 0);
                }
                uVar17 = 0;
                local_318 = uVar18;
                local_2e0 = pWVar19;
              }
            }
            pbVar1 = (byte *)((uVar18 >> 3) + (int)local_2f0);
            *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar18 & 7);
            uVar5 = uVar17;
            pWVar16 = pWVar19;
            local_334 = uVar17;
          }
          if (*pWVar16 != L'\0') goto LAB_4502a5ca;
          goto LAB_4502af8e;
        }
LAB_4502a8a4:
        uVar18 = local_2ec;
        uVar5 = local_2d4;
        if (WVar11 == L'-') {
          local_2f5 = '\x01';
LAB_4502a8bd:
          local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3);
          if ((local_2d8 == (FILE *)0x0) && (local_314 != 0)) {
            uVar17 = (uint)CONCAT11(1,cVar12);
          }
          else {
            uVar5 = local_2d4 + 1;
            local_2f4 = uVar5;
            local_2d4 = uVar5;
            uVar9 = FUN_45033833(local_2cc,local_2e4);
            local_2cc = (void *)(uVar9 & 0xffff);
          }
        }
        else if (WVar11 == L'+') goto LAB_4502a8bd;
        cVar12 = (char)(uVar17 >> 8);
        if ((short)local_2cc == 0x30) {
          local_2f4 = uVar5 + 1;
          local_2d4 = local_2f4;
          uVar9 = FUN_45033833(local_2cc,local_2e4);
          pFVar15 = local_2e4;
          local_2cc = (void *)(uVar9 & 0xffff);
          if (((short)uVar9 == 0x78) || ((short)uVar9 == 0x58)) {
            local_2f4 = uVar5 + 2;
            local_2d4 = local_2f4;
            uVar18 = FUN_45033833(local_2cc,local_2e4);
            local_2cc = (void *)(uVar18 & 0xffff);
            if ((local_314 != 0) &&
               (local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 2), (int)local_2d8 < 1)) {
              cVar12 = cVar12 + '\x01';
            }
            local_2ec = 0x78;
          }
          else {
            local_30c = 1;
            if (uVar18 == 0x78) {
              local_2f4 = uVar5;
              local_2d4 = uVar5;
              FUN_45029bb4(local_2cc,local_2e4);
              local_2cc = (void *)0x30;
              goto LAB_4502a99d;
            }
            if ((local_314 != 0) &&
               (local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3), local_2d8 == (FILE *)0x0))
            {
              cVar12 = cVar12 + '\x01';
            }
            local_2ec = 0x6f;
          }
        }
        else {
LAB_4502ab1a:
          cVar12 = (char)(uVar17 >> 8);
          pFVar15 = local_2e4;
        }
      }
      uVar18 = local_2ec;
      if (local_310 == (FILE *)0x0) {
        uVar5 = local_318;
        uVar17 = local_2d4;
        if (cVar12 == '\0') {
          while ((local_2ec != 0x78 && (local_2ec != 0x70))) {
            if ((((uint)local_2cc & 0xff00) != 0) ||
               (iVar6 = _isdigit((uint)local_2cc & 0xff), iVar6 == 0)) goto LAB_4502ae00;
            if (local_2ec == 0x6f) {
              if (0x37 < (ushort)local_2cc) goto LAB_4502ae00;
              iVar6 = uVar5 << 3;
            }
            else {
              iVar6 = uVar5 * 10;
            }
LAB_4502ad99:
            local_30c = local_30c + 1;
            uVar5 = iVar6 + -0x30 + ((uint)local_2cc & 0xffff);
            local_318 = uVar5;
            if ((local_314 != 0) &&
               (local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3), uVar18 = local_2ec,
               local_2d8 == (FILE *)0x0)) goto LAB_4502ae23;
            uVar17 = local_2d4 + 1;
            local_2f4 = uVar17;
            local_2d4 = uVar17;
            uVar18 = FUN_45033833(local_2cc,local_2e4);
            local_2cc = (void *)(uVar18 & 0xffff);
          }
          if ((((uint)local_2cc & 0xff00) == 0) &&
             (iVar6 = _isxdigit((uint)local_2cc & 0xff), iVar6 != 0)) {
            iVar6 = uVar5 << 4;
            uVar3 = __hextodec((uint)local_2cc);
            local_2cc = (void *)(uint)uVar3;
            goto LAB_4502ad99;
          }
LAB_4502ae00:
          uVar18 = local_2ec;
          local_2f4 = uVar17 - 1;
          local_2d4 = local_2f4;
          FUN_45029bb4(local_2cc,local_2e4);
        }
LAB_4502ae23:
        lVar21 = CONCAT44(local_308,local_31c);
        uVar9 = local_318;
        if (local_2f5 != '\0') {
          uVar9 = -local_318;
        }
      }
      else {
        uVar5 = local_2d4;
        if (cVar12 == '\0') {
          do {
            if ((local_2ec == 0x78) || (local_2ec == 0x70)) {
              if ((((uint)local_2cc & 0xff00) == 0) &&
                 (iVar6 = _isxdigit((uint)local_2cc & 0xff), iVar6 != 0)) {
                local_308 = local_308 << 4 | local_31c >> 0x1c;
                local_31c = local_31c << 4;
                uVar3 = __hextodec((uint)local_2cc);
                lVar21 = CONCAT44(local_308,local_31c);
                local_2cc = (void *)(uint)uVar3;
                uVar18 = local_2ec;
                goto LAB_4502ac30;
              }
LAB_4502aca3:
              uVar18 = local_2ec;
              local_2f4 = uVar5 - 1;
              local_2d4 = local_2f4;
              FUN_45029bb4(local_2cc,pFVar15);
              break;
            }
            if ((((uint)local_2cc & 0xff00) != 0) ||
               (iVar6 = _isdigit((uint)local_2cc & 0xff), uVar18 = local_2ec, iVar6 == 0))
            goto LAB_4502aca3;
            if (local_2ec == 0x6f) {
              if (0x37 < (ushort)local_2cc) goto LAB_4502aca3;
              lVar21 = CONCAT44(local_308 << 3 | local_31c >> 0x1d,local_31c << 3);
            }
            else {
              lVar21 = __allmul(local_31c,local_308,10,0);
            }
LAB_4502ac30:
            pFVar15 = local_2e4;
            local_30c = local_30c + 1;
            lVar21 = lVar21 + (int)(((uint)local_2cc & 0xffff) - 0x30);
            local_31c = (uint)lVar21;
            local_308 = (uint)((ulonglong)lVar21 >> 0x20);
            if ((local_314 != 0) &&
               (local_2d8 = (FILE *)((int)&local_2d8[-1]._tmpfname + 3), local_2d8 == (FILE *)0x0))
            goto LAB_4502acd5;
            uVar5 = uVar5 + 1;
            local_2f4 = uVar5;
            local_2d4 = uVar5;
            uVar18 = FUN_45033833((void *)0x30,local_2e4);
            local_2cc = (void *)(uVar18 & 0xffff);
          } while( true );
        }
        lVar21 = CONCAT44(local_308,local_31c);
LAB_4502acd5:
        uVar9 = local_318;
        if (local_2f5 != '\0') {
          lVar21 = CONCAT44(-((int)((ulonglong)lVar21 >> 0x20) + (uint)((int)lVar21 != 0)),
                            -(int)lVar21);
        }
      }
      bVar20 = false;
      if ((-(uint)(uVar18 != 0x46) & local_30c) == 0) goto LAB_4502af8e;
      pvVar23 = local_2cc;
      uVar18 = local_2d4;
      if (local_2cd == '\0') {
        local_324 = local_324 + 1;
LAB_4502ae6c:
        pvVar23 = local_2cc;
        if (local_310 == (FILE *)0x0) {
          if (local_2d9 == '\0') {
            *local_304 = (WCHAR)uVar9;
          }
          else {
            *(uint *)local_304 = uVar9;
          }
        }
        else {
          *(longlong *)local_304 = lVar21;
        }
      }
      goto LAB_4502a595;
    }
    piVar4 = local_33c + 1;
    local_304 = (WCHAR *)*local_33c;
    local_338 = local_33c + 2;
    local_32c = (FILE *)*piVar4;
    local_33c = piVar4;
    if (local_32c != (FILE *)0x0) goto LAB_4502a088;
    if (cVar12 < '\x01') {
      *(undefined1 *)local_304 = 0;
    }
    else {
      *local_304 = L'\0';
    }
    bVar20 = false;
    piVar4 = __errno();
    lVar21 = CONCAT44(local_308,local_31c);
    *piVar4 = 0xc;
LAB_4502af8e:
    sVar13 = (short)local_2cc;
    goto LAB_4502a3c2;
  }
  goto LAB_4502affc;
LAB_4502aa51:
  local_2f4 = local_2d4 - 1;
  local_2d4 = local_2f4;
  FUN_45029bb4(pvVar23,local_2e4);
LAB_4502aa72:
  lVar21 = CONCAT44(local_308,local_31c);
  if (pWVar16 != local_304) {
    if ((local_2cd == '\0') && (local_324 = local_324 + 1, uVar18 != 99)) {
      uVar18 = local_2d4;
      if (local_2e5 == '\0') {
        *(undefined1 *)local_304 = 0;
      }
      else {
        *local_304 = L'\0';
        lVar21 = CONCAT44(local_308,local_31c);
      }
    }
    else {
LAB_4502a583:
      uVar18 = local_2d4;
      lVar21 = CONCAT44(local_308,local_31c);
    }
LAB_4502a595:
    local_2c6 = local_2c6 + '\x01';
    local_2e0 = local_2e0 + 1;
LAB_4502af07:
    if ((short)pvVar23 == -1) {
      sVar13 = (short)local_2cc;
      if ((*local_2e0 != L'%') || (local_2e0[1] != L'n')) goto LAB_4502a3ba;
    }
    else {
LAB_4502af3c:
      sVar13 = (short)local_2cc;
    }
    WVar11 = *local_2e0;
    if (WVar11 == L'\0') goto LAB_4502a3ba;
    goto LAB_45029cce;
  }
LAB_4502a3b4:
  lVar21 = CONCAT44(local_308,local_31c);
  sVar13 = (short)local_2cc;
LAB_4502a3ba:
  bVar20 = false;
LAB_4502a3c2:
  local_308 = (uint)((ulonglong)lVar21 >> 0x20);
  local_31c = (uint)lVar21;
  if (local_340 == 1) {
    FID_conflict__free(local_2f0);
    lVar21 = CONCAT44(local_308,local_31c);
  }
  local_308 = (uint)((ulonglong)lVar21 >> 0x20);
  local_31c = (uint)lVar21;
  if (local_330 == 1) {
    FID_conflict__free(local_2fc);
    lVar21 = CONCAT44(local_308,local_31c);
  }
  local_308 = (uint)((ulonglong)lVar21 >> 0x20);
  local_31c = (uint)lVar21;
  if ((sVar13 != -1) && (bVar20)) {
    piVar4 = __errno();
    *piVar4 = 0x16;
    FUN_45027e29();
    lVar21 = CONCAT44(local_308,local_31c);
  }
LAB_4502affc:
  if (local_344 != '\0') {
    *(uint *)(local_348 + 0x70) = *(uint *)(local_348 + 0x70) & 0xfffffffd;
  }
LAB_4502b010:
  local_308 = (uint)((ulonglong)lVar21 >> 0x20);
  local_31c = (uint)lVar21;
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


