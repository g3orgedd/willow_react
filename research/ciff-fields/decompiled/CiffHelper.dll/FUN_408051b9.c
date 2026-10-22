// Source: CiffHelper.dll @ 408051b9; FUN_408051b9

bool __thiscall FUN_408051b9(void *this,wchar_t *param_1,size_t *param_2)

{
  size_t *_ArgList;
  WCHAR WVar1;
  LPCWSTR lpsz;
  uint uVar2;
  size_t *psVar3;
  LPWSTR pWVar4;
  int iVar5;
  size_t *psVar6;
  size_t *psVar7;
  size_t *local_10;
  uint local_c;
  int local_8;
  
  _ArgList = param_2;
  local_8 = 0;
  WVar1 = *param_1;
  lpsz = param_1;
  psVar7 = param_2;
  do {
    if (WVar1 == L'\0') {
      iVar5 = FUN_408035a4(this,local_8);
      if (iVar5 != 0) {
        _vswprintf_s(*(wchar_t **)this,*(int *)(*(wchar_t **)this + -2) + 1,param_1,
                     (va_list)_ArgList);
        FUN_40803722(this,-1);
      }
      return iVar5 != 0;
    }
    if (*lpsz == L'%') {
      lpsz = CharNextW(lpsz);
      WVar1 = *lpsz;
      if (WVar1 == L'%') goto LAB_40805496;
      param_2 = (size_t *)0x0;
      if (WVar1 == L'\0') {
LAB_4080526a:
        param_2 = (size_t *)FUN_4082ee87(lpsz);
        while ((*lpsz != L'\0' && (iVar5 = FUN_4082dc94(*lpsz), iVar5 != 0))) {
          lpsz = CharNextW(lpsz);
        }
      }
      else {
        do {
          if (WVar1 == L'#') {
            local_8 = local_8 + 2;
          }
          else if (WVar1 == L'*') {
            param_2 = (size_t *)*psVar7;
            psVar7 = psVar7 + 1;
          }
          else if ((((WVar1 != L'-') && (WVar1 != L'+')) && (WVar1 != L'0')) && (WVar1 != L' '))
          break;
          lpsz = CharNextW(lpsz);
          WVar1 = *lpsz;
        } while (WVar1 != L'\0');
        if (param_2 == (size_t *)0x0) goto LAB_4080526a;
      }
      psVar3 = (size_t *)0x0;
      local_10 = (size_t *)0x0;
      psVar6 = psVar7;
      if (*lpsz == L'.') {
        lpsz = CharNextW(lpsz);
        if (*lpsz == L'*') {
          local_10 = (size_t *)*psVar7;
          lpsz = CharNextW(lpsz);
          psVar6 = psVar7 + 1;
        }
        else {
          local_10 = (size_t *)FUN_4082ee87(lpsz);
          while ((*lpsz != L'\0' && (iVar5 = FUN_4082dc94(*lpsz), iVar5 != 0))) {
            lpsz = CharNextW(lpsz);
          }
        }
      }
      WVar1 = *lpsz;
      local_c = 0;
      if (WVar1 == L'I') {
        if ((lpsz[1] == L'6') && (lpsz[2] == L'4')) {
          lpsz = lpsz + 3;
          local_c = 0x40000;
        }
        else if ((lpsz[1] == L'3') && (lpsz[2] == L'2')) {
          lpsz = lpsz + 3;
        }
        else {
          lpsz = lpsz + 1;
        }
      }
      else {
        if (((WVar1 != L'F') && (WVar1 != L'L')) && (WVar1 != L'N')) {
          if (WVar1 == L'h') {
            local_c = 0x10000;
          }
          else {
            if (WVar1 != L'l') goto LAB_4080535c;
            local_c = 0x20000;
          }
        }
        lpsz = CharNextW(lpsz);
      }
LAB_4080535c:
      uVar2 = (ushort)*lpsz | local_c;
      psVar7 = psVar6;
      if (uVar2 < 0x10064) {
        if ((uVar2 != 0x10063) && (uVar2 != 0x43)) {
          if (uVar2 == 0x53) goto LAB_40805396;
          if (uVar2 != 99) {
            if (uVar2 == 0x73) {
              if (*psVar6 == 0) goto LAB_408053e0;
              psVar3 = (size_t *)lstrlenW((LPCWSTR)*psVar6);
              goto LAB_408053a8;
            }
            if (uVar2 != 0x10043) {
              if (uVar2 != 0x10053) goto LAB_4080542f;
              goto LAB_40805396;
            }
          }
        }
LAB_408053f0:
        psVar3 = (size_t *)0x2;
LAB_408053b6:
        psVar7 = psVar6 + 1;
        if ((int)param_2 < (int)psVar3) {
          param_2 = psVar3;
        }
        psVar3 = param_2;
        if ((local_10 != (size_t *)0x0) && (psVar3 = local_10, (int)param_2 < (int)local_10)) {
          psVar3 = param_2;
        }
      }
      else {
        if (uVar2 != 0x10073) {
          if (uVar2 != 0x20043) {
            if (uVar2 == 0x20053) {
LAB_40805415:
              if (*psVar6 == 0) goto LAB_408053e0;
              psVar3 = (size_t *)_wcslen((wchar_t *)*psVar6);
              goto LAB_408053a8;
            }
            if (uVar2 != 0x20063) {
              if (uVar2 == 0x20073) goto LAB_40805415;
              goto LAB_4080542f;
            }
          }
          goto LAB_408053f0;
        }
LAB_40805396:
        if (*psVar6 == 0) {
LAB_408053e0:
          psVar3 = (size_t *)0x6;
          goto LAB_408053b6;
        }
        psVar3 = (size_t *)lstrlenA((LPCSTR)*psVar6);
LAB_408053a8:
        psVar7 = psVar6 + 1;
        if ((int)psVar3 < 1) {
          psVar3 = (size_t *)0x1;
        }
        if (psVar3 != (size_t *)0x0) goto LAB_408053b6;
LAB_4080542f:
        WVar1 = *lpsz;
        if ((ushort)WVar1 < 0x6a) {
          if ((WVar1 == L'i') ||
             (((WVar1 != L'E' && (WVar1 != L'G')) && ((WVar1 == L'X' || (WVar1 == L'd')))))) {
LAB_4080546b:
            if ((local_c & 0x40000) == 0) goto LAB_40805478;
            psVar7 = psVar7 + 2;
LAB_4080547b:
            psVar3 = (size_t *)((int)local_10 + (int)param_2);
            if ((int)local_10 + (int)param_2 < 0x20) {
              psVar3 = (size_t *)0x20;
            }
          }
          else {
            OutputDebugStringW(
                              L"Floating point (%%e, %%f, %%g, and %%G) is not supported by the WTL::CString class."
                              );
            DebugBreak();
          }
        }
        else {
          if (WVar1 != L'n') {
            if ((WVar1 == L'o') || (WVar1 != L'p')) goto LAB_4080546b;
LAB_40805478:
            psVar7 = psVar7 + 1;
            goto LAB_4080547b;
          }
          psVar7 = psVar7 + 1;
        }
      }
      local_8 = local_8 + (int)psVar3;
    }
    else {
LAB_40805496:
      pWVar4 = CharNextW(lpsz);
      local_8 = local_8 + ((int)pWVar4 - (int)lpsz >> 1);
    }
    lpsz = CharNextW(lpsz);
    WVar1 = *lpsz;
  } while( true );
}


