// Source: CLCiffConversion_Data.dll @ 45032b71; FUN_45032b71

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_45032b71(WCHAR *param_1,WCHAR *param_2,uint param_3)

{
  char *pcVar1;
  char cVar2;
  WCHAR WVar3;
  byte bVar4;
  wint_t wVar5;
  ulong *puVar6;
  int *piVar7;
  undefined3 extraout_var;
  _ptiddata p_Var8;
  BOOL BVar9;
  UINT CodePage;
  int iVar10;
  DWORD DVar11;
  uint uVar12;
  char cVar13;
  WCHAR *pWVar14;
  uint uVar15;
  uint uVar16;
  DWORD DVar17;
  WCHAR *pWVar18;
  DWORD local_1aec;
  char local_1ae5;
  uint local_1ae4;
  int local_1ae0;
  int local_1adc;
  WCHAR *local_1ad8;
  WCHAR *local_1ad4;
  DWORD local_1ad0;
  WCHAR *local_1acc;
  WCHAR *local_1ac8;
  uint local_1ac4;
  int local_1ac0;
  WCHAR local_1abc [854];
  WCHAR local_1410 [852];
  CHAR local_d68 [3416];
  undefined2 local_10;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_1ac0 = 0;
  uVar15 = 0;
  local_1acc = param_1;
  DVar17 = 0;
  local_1ad4 = param_2;
  local_1ac4 = 0;
  if (param_3 == 0) goto LAB_450333c6;
  if (param_2 == (WCHAR *)0x0) {
    puVar6 = ___doserrno();
    *puVar6 = 0;
    piVar7 = __errno();
    *piVar7 = 0x16;
    FUN_45027e29();
    goto LAB_450333c6;
  }
  local_1adc = (int)param_1 >> 5;
  local_1ae0 = ((uint)param_1 & 0x1f) * 0x40;
  cVar13 = (char)(*(char *)(local_1ae0 + 0x24 + (&DAT_45055ae0)[local_1adc]) * '\x02') >> 1;
  if (((cVar13 == '\x02') || (cVar13 == '\x01')) && ((~param_3 & 1) == 0)) {
    puVar6 = ___doserrno();
    *puVar6 = 0;
    piVar7 = __errno();
    *piVar7 = 0x16;
    FUN_45027e29();
    goto LAB_450333c6;
  }
  if ((*(byte *)(local_1ae0 + 4 + (&DAT_45055ae0)[local_1adc]) & 0x20) != 0) {
    FUN_450334d2((uint)param_1,0,0,(PLARGE_INTEGER)0x2);
  }
  bVar4 = FUN_45032a2e((uint)local_1acc);
  if ((CONCAT31(extraout_var,bVar4) == 0) ||
     ((*(byte *)(local_1ae0 + 4 + (&DAT_45055ae0)[local_1adc]) & 0x80) == 0)) {
LAB_45032fb4:
    if ((*(byte *)(local_1ae0 + 4 + (&DAT_45055ae0)[local_1adc]) & 0x80) == 0) {
      BVar9 = WriteFile(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),local_1ad4,param_3,
                        &local_1ae4,(LPOVERLAPPED)0x0);
      if (BVar9 == 0) {
LAB_45032fa7:
        DVar17 = GetLastError();
      }
      else {
        uVar15 = local_1ae4;
        DVar17 = 0;
      }
      goto LAB_450330c4;
    }
    local_1ad0 = 0;
    if (cVar13 == '\0') {
      local_1acc = local_1ad4;
      if (param_3 == 0) goto LAB_45033386;
      do {
        pWVar18 = local_1410;
        local_1ac8 = (WCHAR *)0x0;
        uVar12 = (int)local_1acc - (int)local_1ad4;
        do {
          if (param_3 <= uVar12) break;
          local_1ae5 = (char)*local_1acc;
          local_1acc = (WCHAR *)((int)local_1acc + 1);
          uVar12 = uVar12 + 1;
          if (local_1ae5 == '\n') {
            local_1ac0 = local_1ac0 + 1;
            *(char *)pWVar18 = '\r';
            pWVar18 = (WCHAR *)((int)pWVar18 + 1);
            local_1ac8 = (WCHAR *)((int)local_1ac8 + 1);
          }
          *(char *)pWVar18 = local_1ae5;
          pWVar18 = (WCHAR *)((int)pWVar18 + 1);
          local_1ac8 = (WCHAR *)((int)local_1ac8 + 1);
        } while (local_1ac8 < (WCHAR *)0x13ff);
        BVar9 = WriteFile(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),local_1410,
                          (int)pWVar18 - (int)local_1410,&local_1ae4,(LPOVERLAPPED)0x0);
        if (BVar9 == 0) goto LAB_45032fa7;
        uVar15 = uVar15 + local_1ae4;
        DVar17 = local_1ad0;
      } while (((int)pWVar18 - (int)local_1410 <= (int)local_1ae4) &&
              ((uint)((int)local_1acc - (int)local_1ad4) < param_3));
      goto LAB_450330c4;
    }
    if (cVar13 == '\x02') {
      pWVar18 = local_1ad4;
      if (param_3 != 0) {
        do {
          local_1aec = 0;
          pWVar14 = local_1410;
          uVar12 = (int)pWVar18 - (int)local_1ad4;
          uVar15 = 0;
          do {
            if (param_3 <= uVar12) break;
            WVar3 = *pWVar18;
            uVar12 = uVar12 + 2;
            pWVar18 = pWVar18 + 1;
            if (WVar3 == L'\n') {
              local_1ac0 = local_1ac0 + 2;
              *pWVar14 = L'\r';
              pWVar14 = pWVar14 + 1;
              uVar15 = uVar15 + 2;
            }
            *pWVar14 = WVar3;
            uVar15 = uVar15 + 2;
            pWVar14 = pWVar14 + 1;
          } while (uVar15 < 0x13fe);
          local_1ac8 = pWVar18;
          BVar9 = WriteFile(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),local_1410,
                            (int)pWVar14 - (int)local_1410,&local_1ae4,(LPOVERLAPPED)0x0);
          uVar15 = local_1ac4;
          if (BVar9 == 0) goto LAB_45032fa7;
          uVar15 = local_1ac4 + local_1ae4;
          DVar17 = local_1ad0;
          local_1ac4 = uVar15;
        } while (((int)pWVar14 - (int)local_1410 <= (int)local_1ae4) &&
                (pWVar18 = local_1ac8, (uint)((int)local_1ac8 - (int)local_1ad4) < param_3));
        goto LAB_450330c4;
      }
    }
    else {
      local_1acc = local_1ad4;
      if (param_3 != 0) {
        do {
          local_1aec = 0;
          pWVar18 = local_1abc;
          uVar12 = (int)local_1acc - (int)local_1ad4;
          uVar15 = 0;
          do {
            if (param_3 <= uVar12) break;
            WVar3 = *local_1acc;
            uVar12 = uVar12 + 2;
            local_1acc = local_1acc + 1;
            if (WVar3 == L'\n') {
              *pWVar18 = L'\r';
              pWVar18 = pWVar18 + 1;
              uVar15 = uVar15 + 2;
            }
            *pWVar18 = WVar3;
            uVar15 = uVar15 + 2;
            pWVar18 = pWVar18 + 1;
          } while (uVar15 < 0x6a8);
          local_1ac8 = (WCHAR *)WideCharToMultiByte(0xfde9,0,local_1abc,
                                                    ((int)pWVar18 - (int)local_1abc) / 2,local_d68,
                                                    0xd55,(LPCSTR)0x0,(LPBOOL)0x0);
          uVar15 = local_1ac4;
          DVar17 = local_1ad0;
          if (local_1ac8 == (WCHAR *)0x0) goto LAB_45032fa7;
          local_1ac4 = 0;
          do {
            BVar9 = WriteFile(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),
                              local_d68 + local_1ac4,(int)local_1ac8 - local_1ac4,&local_1ae4,
                              (LPOVERLAPPED)0x0);
            if (BVar9 == 0) {
              DVar17 = GetLastError();
              local_1ad0 = DVar17;
              break;
            }
            local_1ac4 = local_1ac4 + local_1ae4;
          } while ((int)local_1ac4 < (int)local_1ac8);
        } while (((int)local_1ac8 <= (int)local_1ac4) &&
                (uVar15 = (int)local_1acc - (int)local_1ad4, local_1ac4 = uVar15, uVar15 < param_3))
        ;
        goto LAB_450330c4;
      }
    }
  }
  else {
    p_Var8 = __getptd();
    local_1ac8 = (WCHAR *)(uint)(p_Var8->ptlocinfo->locale_name[2] == (wchar_t *)0x0);
    BVar9 = GetConsoleMode(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),&local_1aec);
    if ((BVar9 == 0) || ((local_1ac8 != (WCHAR *)0x0 && (cVar13 == '\0')))) goto LAB_45032fb4;
    CodePage = GetConsoleCP();
    DVar11 = 0;
    local_1acc = (WCHAR *)0x0;
    local_1ad0 = 0;
    local_1ad8 = local_1ad4;
    if (param_3 == 0) goto LAB_45033386;
    uVar12 = 0;
    local_1ac4 = 0;
    pWVar18 = local_1ad4;
    uVar16 = uVar15;
    do {
      local_1ac8 = (WCHAR *)0x0;
      uVar15 = uVar16;
      if (cVar13 == '\0') {
        cVar2 = (char)*pWVar18;
        local_1aec = (DWORD)(cVar2 == '\n');
        local_1ac8 = (WCHAR *)(&DAT_45055ae0)[local_1adc];
        if (*(int *)(local_1ae0 + 0x38 + (int)local_1ac8) == 0) {
          iVar10 = FUN_45021506((int)cVar2);
          if (iVar10 == 0) {
            uVar12 = 1;
            pWVar18 = local_1ad8;
            goto LAB_45032dd0;
          }
          if ((char *)((int)local_1ad4 + (param_3 - (int)local_1ad8)) < (char *)0x2) {
            *(char *)(local_1ae0 + 0x34 + (&DAT_45055ae0)[local_1adc]) = (char)*local_1ad8;
            *(undefined4 *)(local_1ae0 + 0x38 + (&DAT_45055ae0)[local_1adc]) = 1;
            uVar15 = uVar16 + 1;
            break;
          }
          iVar10 = FUN_4503381b((LPWSTR)&local_1ad0,(byte *)local_1ad8,2);
          if (iVar10 == -1) break;
          local_1ad8 = (WCHAR *)((int)local_1ad8 + 1);
          local_1ac4 = local_1ac4 + 1;
        }
        else {
          local_10._0_1_ = *(char *)(local_1ae0 + 0x34 + (int)local_1ac8);
          uVar12 = 2;
          pcVar1 = (char *)(local_1ae0 + 0x38 + (int)local_1ac8);
          pcVar1[0] = '\0';
          pcVar1[1] = '\0';
          pcVar1[2] = '\0';
          pcVar1[3] = '\0';
          pWVar18 = &local_10;
          local_10._1_1_ = cVar2;
LAB_45032dd0:
          iVar10 = FUN_4503381b((LPWSTR)&local_1ad0,(byte *)pWVar18,uVar12);
          if (iVar10 == -1) break;
        }
        local_1ad8 = (WCHAR *)((int)local_1ad8 + 1);
        local_1ac4 = local_1ac4 + 1;
        local_1ac8 = (WCHAR *)WideCharToMultiByte(CodePage,0,(LPCWSTR)&local_1ad0,1,(LPSTR)&local_10
                                                  ,5,(LPCSTR)0x0,(LPBOOL)0x0);
        if (local_1ac8 == (WCHAR *)0x0) break;
        BVar9 = WriteFile(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),&local_10,
                          (DWORD)local_1ac8,(LPDWORD)&local_1acc,(LPOVERLAPPED)0x0);
        if (BVar9 == 0) goto LAB_45032fa7;
        uVar15 = local_1ac4 + local_1ac0;
        if ((int)local_1acc < (int)local_1ac8) break;
        pWVar18 = local_1ad8;
        DVar11 = local_1ad0;
        uVar12 = local_1ac4;
        if (local_1aec != 0) {
          local_10._0_1_ = '\r';
          BVar9 = WriteFile(*(HANDLE *)(local_1ae0 + (&DAT_45055ae0)[local_1adc]),&local_10,1,
                            (LPDWORD)&local_1acc,(LPOVERLAPPED)0x0);
          if (BVar9 == 0) goto LAB_45032fa7;
          if ((int)local_1acc < 1) break;
          local_1ac0 = local_1ac0 + 1;
          uVar15 = uVar15 + 1;
          pWVar18 = local_1ad8;
          DVar11 = local_1ad0;
          uVar12 = local_1ac4;
        }
      }
      else {
        if ((cVar13 == '\x01') || (cVar13 == '\x02')) {
          DVar11 = (DWORD)(ushort)*pWVar18;
          local_1ac8 = (WCHAR *)(uint)(*pWVar18 == L'\n');
          pWVar18 = pWVar18 + 1;
          uVar12 = local_1ac4 + 2;
          local_1ad8 = pWVar18;
          local_1ad0 = DVar11;
          local_1ac4 = uVar12;
        }
        if ((cVar13 == '\x01') || (cVar13 == '\x02')) {
          wVar5 = __putwch_nolock((wchar_t)DVar11);
          if (wVar5 != (wint_t)local_1ad0) goto LAB_45032fa7;
          uVar15 = uVar16 + 2;
          pWVar18 = local_1ad8;
          DVar11 = local_1ad0;
          uVar12 = local_1ac4;
          if (local_1ac8 != (WCHAR *)0x0) {
            local_1ad0 = 0xd;
            wVar5 = __putwch_nolock(L'\r');
            if (wVar5 != (wint_t)local_1ad0) goto LAB_45032fa7;
            uVar15 = uVar16 + 3;
            local_1ac0 = local_1ac0 + 1;
            pWVar18 = local_1ad8;
            DVar11 = local_1ad0;
            uVar12 = local_1ac4;
          }
        }
      }
      uVar16 = uVar15;
    } while (uVar12 < param_3);
LAB_450330c4:
    if (uVar15 != 0) goto LAB_450333c6;
    if (DVar17 != 0) {
      if (DVar17 == 5) {
        piVar7 = __errno();
        *piVar7 = 9;
        puVar6 = ___doserrno();
        *puVar6 = 5;
      }
      else {
        FID_conflict___dosmaperr(DVar17);
      }
      goto LAB_450333c6;
    }
  }
LAB_45033386:
  if (((*(byte *)(local_1ae0 + 4 + (&DAT_45055ae0)[local_1adc]) & 0x40) == 0) ||
     ((char)*local_1ad4 != '\x1a')) {
    piVar7 = __errno();
    *piVar7 = 0x1c;
    puVar6 = ___doserrno();
    *puVar6 = 0;
  }
LAB_450333c6:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


