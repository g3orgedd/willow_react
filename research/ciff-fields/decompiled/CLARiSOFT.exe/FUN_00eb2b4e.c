// Source: CLARiSOFT.exe @ 00eb2b4e; FUN_00eb2b4e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_00eb2b4e(void *this,void *param_1,int *param_2,BSTR param_3,undefined1 *param_4)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  uchar uVar4;
  char cVar5;
  bool bVar6;
  OLECHAR *pOVar7;
  HANDLE hFindFile;
  undefined4 *puVar8;
  HRESULT HVar9;
  BOOL BVar10;
  UINT UVar11;
  CComBSTR *pCVar12;
  int *piVar13;
  BSTR extraout_EAX;
  HKEY pHVar14;
  LSTATUS LVar15;
  undefined4 uVar16;
  BSTR extraout_ECX;
  BSTR pOVar17;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  code *pcVar18;
  void *pvVar19;
  void *pvVar20;
  BSTR pOVar21;
  BSTR pOVar22;
  int iVar23;
  int local_974 [2];
  OLECHAR *local_96c;
  _union_2683 local_95c;
  LPCWSTR local_94c;
  BSTR local_948;
  int local_944;
  int *local_940;
  int local_93c;
  DWORD local_938;
  BSTR local_934;
  int *local_930;
  int local_92c;
  BSTR local_928;
  HKEY local_924;
  HANDLE local_920;
  BSTR local_91c;
  BSTR local_918;
  BSTR local_914;
  BSTR local_910;
  void *local_90c;
  BSTR local_908;
  void *local_904;
  BSTR local_900;
  BSTR local_8fc;
  int *local_8f8;
  BSTR local_8f4;
  undefined1 *local_8f0;
  HKEY local_8ec;
  char local_8e5;
  BSTR local_8e4;
  OLECHAR *local_8e0;
  BSTR local_8dc;
  char local_8d5;
  _WIN32_FIND_DATAW local_8d4;
  _WIN32_FIND_DATAW local_684;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_434 [24];
  WCHAR local_41c [256];
  wchar_t local_21c [266];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x964;
  local_904 = param_1;
  local_8f0 = param_4;
  local_8 = 1;
  local_90c = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_434,"CCiffChecker::CheckTextField");
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00e3c14c(0xf00bc4);
  local_8e4 = (BSTR)FUN_00eca369(8);
  if (local_8e4 == (BSTR)0x0) {
    local_8e4 = (BSTR)0x0;
  }
  else {
    pOVar21 = local_8e4 + 2;
    pOVar21[0] = L'\0';
    pOVar21[1] = L'\0';
    FUN_00e11de5(pOVar21,(int *)&param_2);
    *(undefined1 *)local_8e4 = 1;
  }
  local_92c = 0;
  local_91c = (BSTR)0x0;
  local_8._0_1_ = 3;
  (**(code **)(**(int **)((int)param_1 + 4) + 0xa8))();
  FUN_00e03b51((uint *)&local_95c);
  local_8._0_1_ = 4;
  (**(code **)(**(int **)(local_8e4 + 2) + 0x474))();
  CComQIPtr<>(&local_940,(undefined4 *)local_95c._8_4_);
  local_93c = 0;
  local_8._0_1_ = 5;
  (**(code **)(*local_940 + 0x24))();
  local_928 = (BSTR)0x0;
  local_934 = (BSTR)0x0;
  local_944 = 0;
  local_8._0_1_ = 7;
  local_8d5 = '\0';
  local_8ec = (HKEY)((uint)local_8ec & 0xffffff00);
  local_908 = (BSTR)((uint)local_908 & 0xffffff00);
  local_900 = (BSTR)((uint)local_900 & 0xffffff00);
  (**(code **)(**(int **)((int)param_1 + 4) + 0x124))();
  pcVar18 = SysFreeString_exref;
  if (local_944 == 2) {
LAB_00eb2cf0:
    pOVar7 = FUN_00eb81ca();
    FUN_00e03b21(&local_8fc,pOVar7);
    local_8 = CONCAT31(local_8._1_3_,9);
    _swprintf_s(local_21c,0x104,L"%ls\\*.zfbf");
    hFindFile = FindFirstFileW(local_21c,&local_684);
    local_920 = hFindFile;
    if (hFindFile != (HANDLE)0xffffffff) {
      do {
        FUN_00e03bc2(&local_8f8,local_684.cFileName);
        local_8._0_1_ = 10;
        if (((byte)local_684.dwFileAttributes & 0x10) == 0) {
          puVar8 = FUN_00e07750(&local_8f8,&local_8f4,local_8f8[-2] + -5);
          local_8._0_1_ = 0xb;
          FUN_00e03b21(&local_914,(OLECHAR *)*puVar8);
          local_8._0_1_ = 0xd;
          FUN_00e01f81((int *)&local_8f4);
          FUN_00e3c14c(0xf06ad4);
          HVar9 = VarBstrCmp(local_914,local_91c,0x400,0);
          local_900 = (BSTR)((uint)local_900 & 0xff);
          if (HVar9 == 1) {
            local_900 = (BSTR)0x1;
          }
          SysFreeString(local_914);
        }
        local_8 = CONCAT31(local_8._1_3_,9);
        FUN_00e01f81((int *)&local_8f8);
        BVar10 = FindNextFileW(hFindFile,&local_684);
        this = local_90c;
      } while ((BVar10 != 0) && ((char)local_900 == '\0'));
    }
    FindClose(local_920);
    local_8._0_1_ = 7;
    SysFreeString(local_8fc);
    if ((char)local_900 == '\0') goto LAB_00eb2e69;
  }
  else {
    local_8dc = (BSTR)&stack0xfffff658;
    pOVar21 = (BSTR)&stack0xfffff658;
    piVar13 = param_2;
    pOVar17 = (BSTR)&stack0xfffff658;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))();
      pOVar21 = extraout_ECX;
      pOVar17 = local_8dc;
    }
    local_8dc = pOVar17;
    local_8._0_1_ = 8;
    FUN_00e03ab8(&stack0xfffff654,(int *)&local_91c);
    local_8._0_1_ = 7;
    uVar4 = FUN_00eb6b6a(pOVar21,piVar13);
    if (uVar4 != '\0') goto LAB_00eb2cf0;
LAB_00eb2e69:
    pOVar21 = (BSTR)0x0;
    if (0 < local_93c) {
      do {
        local_8f4 = (BSTR)((int)pOVar21 + 1);
        (**(code **)(*local_940 + 0x20))();
        CComQIPtr<>(&local_8e0,(undefined4 *)local_95c._8_4_);
        local_8._0_1_ = 0xe;
        SysFreeString(local_928);
        local_928 = (BSTR)0x0;
        (**(code **)(*(int *)local_8e0 + 0x1c))();
        HVar9 = VarBstrCmp(local_91c,local_928,0x400,0);
        this = local_90c;
        if (HVar9 == 1) {
          local_8d5 = '\x01';
          if (local_8e0 != (OLECHAR *)0x0) {
            (**(code **)(*(int *)local_8e0 + 0xb4))();
          }
          local_914 = (BSTR)0x0;
          local_8._0_1_ = 0xf;
          (**(code **)(*(int *)local_8e0 + 0x9c))();
          bVar6 = FUN_00e03edc(&local_914,L"TrueType");
          local_8ec = (HKEY)((uint)local_8ec & 0xff);
          if (bVar6) {
            local_8ec = (HKEY)0x1;
          }
          (**(code **)(*(int *)local_8e0 + 0xac))();
          UVar11 = SysStringLen(local_934);
          local_908 = (BSTR)((uint)local_908 & 0xff);
          if (UVar11 != 0) {
            local_908 = (BSTR)0x1;
          }
          SysFreeString(local_914);
          local_8._0_1_ = 7;
          if (local_8e0 != (OLECHAR *)0x0) {
            (**(code **)(*(int *)local_8e0 + 8))();
          }
          break;
        }
        local_8._0_1_ = 7;
        if (local_8e0 != (OLECHAR *)0x0) {
          (**(code **)(*(int *)local_8e0 + 8))();
        }
        pOVar21 = local_8f4;
      } while ((int)local_8f4 < local_93c);
    }
  }
  (**(code **)(*(int *)local_95c._8_4_ + 8))();
  local_95c._8_4_ = 0;
  local_95c.n2.vt = 0;
  GetEnvironmentVariableW(L"windir",local_41c,0xff);
  FUN_00e03bc2(&local_914,local_41c);
  local_8._0_1_ = 0x10;
  FUN_00e06fd2(&local_914,L"\\Fonts\\");
  FUN_00e03b6d(&local_920,"*.ttc");
  local_8._0_1_ = 0x11;
  FUN_00e13b24(&local_94c,&local_914,&local_920);
  local_8 = CONCAT31(local_8._1_3_,0x13);
  FUN_00e01f81((int *)&local_920);
  local_920 = FindFirstFileW(local_94c,&local_8d4);
  local_8e5 = '\x01';
  if (local_920 != (HANDLE)0xffffffff) {
    while (local_8e5 != '\0') {
      FUN_00e28cb6(&local_8e0,&local_914,local_8d4.cFileName);
      local_948 = (BSTR)0x0;
      local_8._0_1_ = 0x15;
      puVar8 = FUN_00e03b21(&local_938,local_8e0);
      local_8._0_1_ = 0x16;
      FUN_00eb6158(puVar8,(uint *)&local_924,(BSTR)&local_948);
      local_8 = CONCAT31(local_8._1_3_,0x15);
      (*pcVar18)();
      pOVar21 = local_948;
      local_8dc = (BSTR)SysStringLen(local_948);
      local_8f4 = (BSTR)0x0;
      pOVar17 = (BSTR)0x0;
      if (-1 < (int)local_8dc) {
        local_930 = (int *)0x0;
        local_8f8 = (int *)0x2;
        do {
          if (*(short *)((int)(pOVar21 + -1) + (int)local_8f8) == 0) {
            FUN_00e0e8e2(&local_8fc,(UINT)pOVar17,(OLECHAR *)((int)local_930 + (int)pOVar21));
            HVar9 = VarBstrCmp(local_8fc,local_91c,0x400,0);
            if (HVar9 == 1) {
              local_8d5 = '\x01';
              local_8e5 = '\0';
              SysFreeString(local_8fc);
              break;
            }
            local_910 = (BSTR)0xffffffff;
            local_930 = local_8f8;
            SysFreeString(local_8fc);
            pOVar17 = local_910;
          }
          local_8f4 = (BSTR)((int)local_8f4 + 1);
          local_8f8 = (int *)((int)local_8f8 + 2);
          pOVar17 = (BSTR)((int)pOVar17 + 1);
        } while ((int)local_8f4 <= (int)local_8dc);
      }
      BVar10 = FindNextFileW(local_920,&local_8d4);
      pcVar18 = SysFreeString_exref;
      if (BVar10 == 0) {
        SysFreeString(pOVar21);
        local_8 = CONCAT31(local_8._1_3_,0x13);
        FUN_00e01f81((int *)&local_8e0);
        break;
      }
      SysFreeString(pOVar21);
      local_8 = CONCAT31(local_8._1_3_,0x13);
      FUN_00e01f81((int *)&local_8e0);
    }
  }
  FindClose(local_920);
  local_8fc = *(BSTR *)((int)this + 0x1c);
  local_910 = local_8fc;
  if ((int)local_8fc < 1) {
LAB_00eb3314:
    pvVar20 = local_90c;
    if ((char)local_900 == '\0') {
LAB_00eb331d:
      if (local_8d5 == '\0') {
        pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_8dc);
        local_8._0_1_ = 0x19;
        iVar23 = 0x95;
      }
      else {
        pvVar20 = local_90c;
        if ((char)local_8ec == '\0') goto LAB_00eb3396;
        pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_8dc);
        local_8._0_1_ = 0x18;
        iVar23 = 0x94;
      }
      pvVar20 = local_90c;
      piVar13 = FUN_00e4cac1(*(void **)((int)local_90c + 0xc),iVar23);
      FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
      local_8 = CONCAT31(local_8._1_3_,0x13);
      SysFreeString(local_8dc);
      local_8fc = extraout_EAX;
    }
  }
  else {
    pvVar20 = local_90c;
    if ((char)local_900 == '\0') {
      local_8f4 = (BSTR)0x0;
      puVar8 = (undefined4 *)**(undefined4 **)((int)this + 0x18);
      if (0 < (int)local_8fc) {
        do {
          puVar1 = (undefined4 *)*puVar8;
          FUN_00eaf985(local_974,puVar8 + 2);
          local_8._0_1_ = 0x17;
          FUN_00e03b21(&local_8dc,local_96c);
          pOVar21 = local_8dc;
          UVar11 = SysStringLen(local_8dc);
          if (UVar11 != 0) {
            HVar9 = VarBstrCmp(pOVar21,local_91c,0x400,0);
            if (HVar9 == 1) {
              SysFreeString(pOVar21);
              local_8 = CONCAT31(local_8._1_3_,0x13);
              local_8fc = (BSTR)FUN_00eafb11(local_974);
              pvVar20 = local_90c;
              goto LAB_00eb3396;
            }
            if (((char)local_908 != '\0') &&
               (HVar9 = VarBstrCmp(pOVar21,local_934,0x400,0), HVar9 == 1)) {
              local_900 = (BSTR)CONCAT31(local_900._1_3_,1);
              SysFreeString(pOVar21);
              local_8 = CONCAT31(local_8._1_3_,0x13);
              local_8fc = (BSTR)FUN_00eafb11(local_974);
              goto LAB_00eb3314;
            }
          }
          SysFreeString(pOVar21);
          local_8 = CONCAT31(local_8._1_3_,0x13);
          FUN_00eafb11(local_974);
          local_8fc = (BSTR)((int)local_8f4 + 1);
          puVar8 = puVar1;
          local_8f4 = local_8fc;
        } while ((int)local_8fc < (int)local_910);
      }
      goto LAB_00eb331d;
    }
  }
LAB_00eb3396:
  local_8fc = (BSTR)((uint)local_8fc & 0xffffff00);
  local_8f4 = (BSTR)((uint)local_8f4 & 0xffffff00);
  cVar5 = FUN_00eb73f4((int)local_8e4);
  if (cVar5 == '\x01') {
    iVar23 = FUN_00e56780();
    local_8fc = (BSTR)((uint)local_8fc & 0xff);
    if (0 < iVar23) {
      local_8fc = (BSTR)0x1;
    }
    local_8f4 = (BSTR)CONCAT31(local_8f4._1_3_,(char)local_8fc);
  }
  pvVar19 = local_904;
  local_918 = (BSTR)0x0;
  local_8._0_1_ = 0x1a;
  (**(code **)(**(int **)((int)local_904 + 4) + 0x68))();
  bVar6 = FUN_00e03edc(&local_918,L"TimeText");
  if (bVar6) {
    if (((char)local_8fc != '\0') || (bVar6 = FUN_00eb6777((int)pvVar19), bVar6)) goto LAB_00eb4049;
    cVar5 = FUN_00eb76dd((int)local_8e4);
    if (cVar5 == '\0') {
      pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
      local_8._0_1_ = 0x1b;
      piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),3);
      FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
      local_8._0_1_ = 0x1a;
      SysFreeString(local_8dc);
      if (local_8f0 != (undefined1 *)0x0) {
        *local_8f0 = 0;
      }
    }
    else {
      FUN_00eb57cd(pvVar19,&local_8fc,(int *)0x1);
      local_8._0_1_ = 0x1c;
      if (local_8fc != (BSTR)0x0) {
        (**(code **)(*(int *)local_8fc + 0x28))();
        local_908 = (BSTR)0x0;
        local_8._0_1_ = 0x1d;
        if (local_8dc == (BSTR)0x4) {
          (**(code **)(*(int *)local_8fc + 0xb4))();
        }
        FUN_00e03edc(&local_908,L"SinceJobSelection");
        local_8ec = (HKEY)FUN_00eca369(4);
        if (local_8ec == (HKEY)0x0) {
          local_8ec = (HKEY)0x0;
        }
        else {
          local_8ec->unused = 0;
          FUN_00e11de5(local_8ec,(int *)&local_8fc);
        }
        uVar16 = 0;
        pHVar14 = local_8ec;
        FUN_00eb596f(local_8ec,(undefined4 *)&stack0xfffff648);
        cVar5 = FUN_00eb75c5(local_8e4,(BSTR)pHVar14,uVar16);
        if (cVar5 == '\0') {
          pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_910);
          local_8._0_1_ = 0x1e;
          piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x31);
          FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
          SysFreeString(local_910);
          if (local_8f0 != (undefined1 *)0x0) {
            *local_8f0 = 0;
          }
        }
        if (local_8ec != (HKEY)0x0) {
          FUN_00eafb63(local_8ec,1);
        }
        SysFreeString(local_908);
      }
      local_8._0_1_ = 0x1a;
      if (local_8fc != (BSTR)0x0) {
        (**(code **)(*(int *)local_8fc + 8))();
      }
    }
    if (local_92c != 1) goto LAB_00eb4049;
    pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_8dc);
    local_8._0_1_ = 0x1f;
LAB_00eb3a24:
    iVar23 = 0xe;
  }
  else {
    bVar6 = FUN_00e03edc(&local_918,L"DateText");
    if (bVar6) {
      bVar6 = FUN_00eb6777((int)pvVar19);
      if (bVar6) goto LAB_00eb4049;
      cVar5 = FUN_00eb458c((int)local_8e4);
      if ((cVar5 == '\0') && (cVar5 = FUN_00eb4612((int)local_8e4), cVar5 == '\0')) {
        pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
        local_8._0_1_ = 0x20;
        piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),1);
        FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
        local_8._0_1_ = 0x1a;
        SysFreeString(local_8dc);
        if (local_8f0 != (undefined1 *)0x0) {
          *local_8f0 = 0;
        }
      }
      else {
        FUN_00eb57cd(pvVar19,&local_908,(int *)0x1);
        local_8._0_1_ = 0x21;
        if (local_908 != (BSTR)0x0) {
          pOVar21 = (BSTR)0x4;
          local_8e0 = (OLECHAR *)FUN_00eca369(4);
          if (local_8e0 == (OLECHAR *)0x0) {
            local_8e0 = (OLECHAR *)0x0;
          }
          else {
            local_8e0[0] = L'\0';
            local_8e0[1] = L'\0';
            FUN_00e11de5(local_8e0,(int *)&local_908);
            pOVar21 = extraout_ECX_00;
          }
          uVar16 = 0;
          FUN_00eb596f(local_8e0,(undefined4 *)&stack0xfffff648);
          cVar5 = FUN_00eb75c5(local_8e4,pOVar21,uVar16);
          if (cVar5 == '\0') {
            pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
            local_8._0_1_ = 0x22;
            piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x30);
            FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
            local_8._0_1_ = 0x21;
            SysFreeString(local_8dc);
            pvVar19 = local_904;
            if (local_8f0 != (undefined1 *)0x0) {
              *local_8f0 = 0;
            }
          }
          puVar8 = FUN_00eb652a(local_8e0,&local_8dc);
          local_8._0_1_ = 0x23;
          cVar5 = FUN_00eb6cc8(local_8e4,puVar8);
          local_8._0_1_ = 0x21;
          SysFreeString(local_8dc);
          if (cVar5 == '\0') {
            pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
            local_8._0_1_ = 0x24;
            piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x32);
            FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
            local_8._0_1_ = 0x21;
            SysFreeString(local_8dc);
            if (local_8f0 != (undefined1 *)0x0) {
              *local_8f0 = 0;
            }
          }
          FUN_00eae6d1(&local_8f8);
          pOVar7 = local_8e0;
          local_8._0_1_ = 0x25;
          puVar8 = FUN_00eb652a(local_8e0,&local_8dc);
          local_8._0_1_ = 0x26;
          bVar6 = FUN_00e03edc(puVar8,L"en-GB");
          SysFreeString(local_8dc);
          if (!bVar6) {
            local_8ec = (HKEY)0x0;
            local_8._0_1_ = 0x27;
            puVar8 = FUN_00eb652a(pOVar7,&local_8dc);
            pOVar21 = (BSTR)*puVar8;
            local_8._0_1_ = 0x28;
            *puVar8 = 0;
            FUN_00eaef6c((int *)&param_2,&local_8ec,pOVar21);
            SysFreeString(local_8dc);
            local_900 = (BSTR)0x0;
            local_8._0_1_ = 0x29;
            pOVar21 = extraout_ECX_01;
            FUN_00e03b21(&stack0xfffff64c,local_91c);
            FUN_00eaee17((BSTR)&param_2,&local_900,pOVar21);
            pHVar14 = local_8ec;
            local_8d5 = '\0';
            if (local_900 == (BSTR)0x0) {
              cVar5 = '\x01';
            }
            else {
              local_8._0_1_ = 0x2a;
              local_924 = local_8ec;
              if (local_8ec != (HKEY)0x0) {
                (**(code **)(local_8ec->unused + 4))();
              }
              pOVar21 = local_900;
              local_8._0_1_ = 0x2b;
              local_8dc = local_900;
              if ((local_900 != (BSTR)0x0) &&
                 ((**(code **)(*(int *)local_900 + 4))(), pHVar14 != (HKEY)0x0)) {
                pOVar17 = pOVar21;
                pOVar22 = pOVar21;
                (**(code **)(*(int *)pOVar21 + 4))();
                (**(code **)(pHVar14->unused + 4))(pHVar14,pHVar14);
                local_8d5 = FUN_00eaf1c8((int *)pOVar17,(int *)pOVar22);
              }
              local_8._0_1_ = 0x2a;
              if (pOVar21 != (BSTR)0x0) {
                (**(code **)(*(int *)pOVar21 + 8))();
              }
              local_8._0_1_ = 0x29;
              cVar5 = local_8d5;
              if (pHVar14 != (HKEY)0x0) {
                (**(code **)(pHVar14->unused + 8))();
                cVar5 = local_8d5;
              }
            }
            if (cVar5 == '\0') {
              pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_8dc);
              pvVar20 = local_90c;
              local_8._0_1_ = 0x2c;
              piVar13 = FUN_00e4cac1(*(void **)((int)local_90c + 0xc),0x10);
              FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
              SysFreeString(local_8dc);
              if (local_8f0 != (undefined1 *)0x0) {
                *local_8f0 = 0;
              }
            }
            local_8._0_1_ = 0x27;
            if (local_900 != (BSTR)0x0) {
              (**(code **)(*(int *)local_900 + 8))();
            }
            local_8._0_1_ = 0x25;
            if (local_8ec != (HKEY)0x0) {
              (**(code **)(local_8ec->unused + 8))();
            }
          }
          if (local_8e0 != (OLECHAR *)0x0) {
            FUN_00eafb63(local_8e0,1);
          }
          local_8._0_1_ = 0x21;
          FUN_00eae7b2(&local_8f8);
        }
        local_8._0_1_ = 0x1a;
        pvVar20 = local_90c;
        if (local_908 != (BSTR)0x0) {
          (**(code **)(*(int *)local_908 + 8))();
          pvVar20 = local_90c;
        }
      }
      if ((local_92c != 1) || ((char)local_8fc != '\0')) goto LAB_00eb4049;
      pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_8dc);
      local_8._0_1_ = 0x2d;
      goto LAB_00eb3a24;
    }
    bVar6 = FUN_00e03edc(&local_918,L"OffsetDateText");
    if (bVar6) {
      FUN_00eb10ca(pvVar20,param_3,local_8e4,pvVar19,local_92c,local_8f4,local_8f0);
      goto LAB_00eb4049;
    }
    bVar6 = FUN_00e03edc(&local_918,L"CounterText");
    if (!bVar6) {
      bVar6 = FUN_00e03edc(&local_918,L"FixedText");
      if (bVar6) {
        FUN_00e3c14c(0xf06b24);
        FUN_00eb57cd(pvVar19,&local_930,(int *)0x1);
        local_8._0_1_ = 0x30;
        uVar3 = (undefined1)local_8;
        local_8._0_1_ = 0x30;
        if (local_930 != (int *)0x0) {
          FUN_00eae6d1(&local_8f4);
          local_8f8 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x32);
          pOVar21 = extraout_ECX_02;
          FUN_00e03b21(&stack0xfffff64c,local_91c);
          FUN_00eaee17((BSTR)&param_2,&local_8f8,pOVar21);
          piVar13 = local_8f8;
          if (local_8f8 != (int *)0x0) {
            (**(code **)(*local_8f8 + 4))();
            SysFreeString((BSTR)0x0);
            if (piVar13 != (int *)0x0) {
              (**(code **)(*piVar13 + 8))();
            }
          }
          local_8._0_1_ = 0x31;
          if (local_8f8 != (int *)0x0) {
            (**(code **)(*local_8f8 + 8))();
          }
          local_8._0_1_ = 0x30;
          FUN_00eae7b2(&local_8f4);
          uVar3 = (undefined1)local_8;
        }
        local_8._0_1_ = uVar3;
        FUN_00e3c14c(0xf06b24);
        local_8._0_1_ = 0x1a;
        if (local_930 != (int *)0x0) {
          (**(code **)(*local_930 + 8))();
        }
      }
      else {
        bVar6 = FUN_00e03edc(&local_918,L"ComplexText");
        if ((bVar6) || (bVar6 = FUN_00e03edc(&local_918,L"RichText"), bVar6)) {
          FUN_00e3c14c(0xf06b3c);
          cVar5 = FUN_00eb01b8((int)local_8e4);
          if (cVar5 == '\0') {
            pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
            local_8._0_1_ = 0x33;
            piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),8);
            FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
            local_8._0_1_ = 0x1a;
            SysFreeString(local_8dc);
            pvVar19 = local_904;
            if (local_8f0 != (undefined1 *)0x0) {
              *local_8f0 = 0;
            }
          }
          FUN_00e3c14c(0xf06b3c);
          bVar6 = FUN_00e03edc(&local_918,L"RichText");
          if (bVar6) {
            bVar6 = FUN_00eb6ec6((int)local_8e4);
            if (!bVar6) {
              pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
              local_8._0_1_ = 0x34;
              piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),6);
              FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
              local_8._0_1_ = 0x1a;
              SysFreeString(local_8dc);
              if (local_8f0 != (undefined1 *)0x0) {
                *local_8f0 = 0;
              }
            }
            pvVar19 = local_904;
            uVar16 = FUN_00eb5a00((int)local_904);
            cVar5 = FUN_00eb6e75(local_8e4,uVar16);
            if (cVar5 == '\0') {
              pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
              local_8._0_1_ = 0x35;
              piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x52);
              FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
              local_8._0_1_ = 0x1a;
              SysFreeString(local_8dc);
              if (local_8f0 != (undefined1 *)0x0) {
                *local_8f0 = 0;
              }
            }
            local_908 = (BSTR)0x0;
            pOVar21 = *(BSTR *)((int)local_904 + 4);
            local_8dc = pOVar21;
            if (pOVar21 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar21 + 4))();
            }
            local_8 = CONCAT31(local_8._1_3_,0x36);
            iVar23 = FUN_00eb552a((int *)&param_2,(int *)&local_8dc,(int *)&param_3,
                                  (int *)&local_908);
            if (-1 < iVar23) {
              local_8ec = (HKEY)0x0;
              LVar15 = RegOpenKeyExW((HKEY)0x80000001,
                                     L"Software\\Claricom Ltd\\CLARiSOFT\\WorkSpace\\RichTextBlockEUReg90HMM"
                                     ,0,0xf003f,&local_8ec);
              local_8d5 = '\x01';
              if (LVar15 == 0) {
                local_938 = 0;
                local_910 = (BSTR)0x4;
                local_8f4 = (BSTR)0x0;
                LVar15 = RegQueryValueExW(local_8ec,
                                          L"Software\\Claricom Ltd\\CLARiSOFT\\WorkSpace\\RichTextBlockEUReg90HMM"
                                          ,(LPDWORD)0x0,&local_938,(LPBYTE)&local_8f4,
                                          (LPDWORD)&local_910);
                if (LVar15 == 0) {
                  local_8d5 = local_8f4 != (BSTR)0x0;
                }
                RegCloseKey(local_8ec);
              }
              local_8e5 = (int)local_908 < 0x78;
              if (((int)local_908 < 0x5a) && (local_8d5 != '\0')) {
                pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_910);
                local_8._0_1_ = 0x37;
                piVar13 = FUN_00e4cac1(*(void **)((int)local_90c + 0xc),0x98);
                pvVar20 = local_90c;
                FUN_00eafbc7(*(void **)((int)local_90c + 0x10),pCVar12,piVar13);
                local_8 = CONCAT31(local_8._1_3_,0x36);
                SysFreeString(local_910);
                if (local_8f0 != (undefined1 *)0x0) {
                  *local_8f0 = 0;
                }
              }
              if ((local_8e5 != '\0') && (local_8d5 == '\0')) {
                pCVar12 = (CComBSTR *)FUN_00e616d4(local_904,&local_910);
                local_8 = CONCAT31(local_8._1_3_,0x38);
                piVar13 = FUN_00e4cac1(*(void **)((int)local_90c + 0xc),0x99);
                pvVar20 = local_90c;
                FUN_00eafbc7(*(void **)((int)local_90c + 0x10),pCVar12,piVar13);
                SysFreeString(local_910);
                if (local_8f0 != (undefined1 *)0x0) {
                  *local_8f0 = 0;
                }
              }
            }
            local_8._0_1_ = 0x1a;
            if (pOVar21 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar21 + 8))();
            }
          }
        }
      }
      goto LAB_00eb4049;
    }
    uVar16 = FUN_00eb4562((int)local_8e4);
    local_8ec = (HKEY)0x0;
    if ((char)uVar16 == '\x01') {
      local_8ec = (HKEY)0x2;
    }
    cVar5 = FUN_00eb73f4((int)local_8e4);
    pHVar14 = local_8ec;
    if ((cVar5 == '\x01') && (iVar23 = FUN_00e56780(), pHVar14 = local_8ec, 0 < iVar23)) {
      pHVar14 = (HKEY)((int)&local_8ec->unused + 1);
    }
    if (pHVar14 != (HKEY)0x0) {
      if (pHVar14 != (HKEY)0x1) {
        FUN_00e616d4(pvVar19,&local_8e0);
        piVar13 = *(int **)((int)pvVar19 + 4);
        local_8 = CONCAT31(local_8._1_3_,0x2f);
        if (piVar13 != (int *)0x0) {
          (**(code **)(*piVar13 + 4))();
        }
        cVar5 = FUN_00eb415d(piVar13);
        if (cVar5 == '\0') {
          piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x40);
          FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),(CComBSTR *)&local_8e0,piVar13);
          if (local_8f0 != (undefined1 *)0x0) {
            *local_8f0 = 0;
          }
        }
        puVar2 = local_8f0;
        piVar13 = *(int **)((int)local_904 + 4);
        if (piVar13 != (int *)0x0) {
          (**(code **)(*piVar13 + 4))();
        }
        bVar6 = FUN_00eafe4d(local_8e4,piVar13);
        if (!bVar6) {
          piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x41);
          FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),(CComBSTR *)&local_8e0,piVar13);
          if (puVar2 != (undefined1 *)0x0) {
            *puVar2 = 0;
          }
        }
        if (*(int *)((int)pvVar20 + 4) == 1) {
          piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),9);
          FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),(CComBSTR *)&local_8e0,piVar13);
          if (puVar2 != (undefined1 *)0x0) {
            *puVar2 = 0;
          }
        }
        if ((local_92c == 1) && ((char)local_8fc == '\0')) {
          piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0xe);
          FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),(CComBSTR *)&local_8e0,piVar13);
          if (puVar2 != (undefined1 *)0x0) {
            *puVar2 = 0;
          }
        }
        local_8._0_1_ = 0x1a;
        SysFreeString(local_8e0);
      }
      goto LAB_00eb4049;
    }
    pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
    local_8._0_1_ = 0x2e;
    iVar23 = 4;
  }
  piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),iVar23);
  FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
  local_8._0_1_ = 0x1a;
  SysFreeString(local_8dc);
  if (local_8f0 != (undefined1 *)0x0) {
    *local_8f0 = 0;
  }
LAB_00eb4049:
  pvVar19 = local_904;
  uVar16 = FUN_00eb5a00((int)local_904);
  cVar5 = FUN_00eb7574(local_8e4,uVar16);
  if (cVar5 == '\0') {
    pCVar12 = (CComBSTR *)FUN_00e616d4(pvVar19,&local_8dc);
    local_8._0_1_ = 0x39;
    piVar13 = FUN_00e4cac1(*(void **)((int)pvVar20 + 0xc),0x50);
    FUN_00eafbc7(*(void **)((int)pvVar20 + 0x10),pCVar12,piVar13);
    SysFreeString(local_8dc);
    if (local_8f0 != (undefined1 *)0x0) {
      *local_8f0 = 0;
    }
  }
  if (local_8e4 != (BSTR)0x0) {
    FUN_00e63686(local_8e4,1);
  }
  SysFreeString(local_918);
  FUN_00e01f81((int *)&local_94c);
  FUN_00e01f81((int *)&local_914);
  SysFreeString(local_934);
  SysFreeString(local_928);
  local_8._0_1_ = 4;
  if (local_940 != (int *)0x0) {
    (**(code **)(*local_940 + 8))();
  }
  VariantClear((VARIANTARG *)&local_95c.n2);
  SysFreeString(local_91c);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_434,true,0);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_3 != (BSTR)0x0) {
    (**(code **)(*(int *)param_3 + 8))();
  }
  FUN_00ec9e3c();
  return;
}


