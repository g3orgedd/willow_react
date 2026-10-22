// Source: CLCiffConversion_Layout.dll @ 45405c5a; FUN_45405c5a

bool __thiscall FUN_45405c5a(void *this,char *param_1,size_t *param_2)

{
  size_t *_ArgList;
  char cVar1;
  LPCSTR lpsz;
  uint uVar2;
  size_t *psVar3;
  LPSTR pCVar4;
  int iVar5;
  size_t *psVar6;
  size_t *psVar7;
  size_t *local_10;
  uint local_c;
  LPSTR local_8;
  
  _ArgList = param_2;
  local_8 = (LPSTR)0x0;
  cVar1 = *param_1;
  lpsz = param_1;
  psVar7 = param_2;
  do {
    if (cVar1 == '\0') {
      iVar5 = FUN_454037db(this,(int)local_8);
      if (iVar5 != 0) {
        _vsprintf_s(*(char **)this,*(int *)(*(char **)this + -4) + 1,param_1,(va_list)_ArgList);
        FUN_45404047(this,-1);
      }
      return iVar5 != 0;
    }
    if (*lpsz == '%') {
      lpsz = CharNextA(lpsz);
      cVar1 = *lpsz;
      if (cVar1 == '%') goto LAB_45405f06;
      param_2 = (size_t *)0x0;
      if (cVar1 == '\0') {
LAB_45405ceb:
        param_2 = (size_t *)FUN_4542aefb(lpsz);
        while ((*lpsz != '\0' && (iVar5 = FUN_4542d298((int)*lpsz), iVar5 != 0))) {
          lpsz = CharNextA(lpsz);
        }
      }
      else {
        do {
          if (cVar1 == '#') {
            local_8 = local_8 + 2;
          }
          else if (cVar1 == '*') {
            param_2 = (size_t *)*psVar7;
            psVar7 = psVar7 + 1;
          }
          else if ((((cVar1 != '-') && (cVar1 != '+')) && (cVar1 != '0')) && (cVar1 != ' ')) break;
          lpsz = CharNextA(lpsz);
          cVar1 = *lpsz;
        } while (cVar1 != '\0');
        if (param_2 == (size_t *)0x0) goto LAB_45405ceb;
      }
      psVar3 = (size_t *)0x0;
      local_10 = (size_t *)0x0;
      psVar6 = psVar7;
      if (*lpsz == '.') {
        lpsz = CharNextA(lpsz);
        if (*lpsz == '*') {
          local_10 = (size_t *)*psVar7;
          lpsz = CharNextA(lpsz);
          psVar6 = psVar7 + 1;
        }
        else {
          local_10 = (size_t *)FUN_4542aefb(lpsz);
          while ((*lpsz != '\0' && (iVar5 = FUN_4542d298((int)*lpsz), iVar5 != 0))) {
            lpsz = CharNextA(lpsz);
          }
        }
      }
      cVar1 = *lpsz;
      local_c = 0;
      if (cVar1 == 'I') {
        if ((lpsz[1] == '6') && (lpsz[2] == '4')) {
          lpsz = lpsz + 3;
          local_c = 0x40000;
        }
        else if ((lpsz[1] == '3') && (lpsz[2] == '2')) {
          lpsz = lpsz + 3;
        }
        else {
          lpsz = lpsz + 1;
        }
      }
      else {
        if (((cVar1 != 'F') && (cVar1 != 'L')) && (cVar1 != 'N')) {
          if (cVar1 == 'h') {
            local_c = 0x10000;
          }
          else {
            if (cVar1 != 'l') goto LAB_45405dcf;
            local_c = 0x20000;
          }
        }
        lpsz = CharNextA(lpsz);
      }
LAB_45405dcf:
      uVar2 = (int)*lpsz | local_c;
      psVar7 = psVar6;
      if ((int)uVar2 < 0x10064) {
        if ((uVar2 == 0x10063) || (uVar2 == 0x43)) {
LAB_45405e63:
          psVar3 = (size_t *)0x2;
        }
        else {
          if (uVar2 == 0x53) goto LAB_45405e4a;
          if (uVar2 == 99) goto LAB_45405e63;
          if (uVar2 != 0x73) {
            if (uVar2 == 0x10043) goto LAB_45405e63;
            if (uVar2 != 0x10053) goto LAB_45405e8d;
          }
LAB_45405e09:
          if (*psVar6 != 0) {
            psVar3 = (size_t *)lstrlenA((LPCSTR)*psVar6);
            goto LAB_45405e1b;
          }
LAB_45405e53:
          psVar3 = (size_t *)0x6;
        }
LAB_45405e29:
        psVar7 = psVar6 + 1;
        if ((int)param_2 < (int)psVar3) {
          param_2 = psVar3;
        }
        psVar3 = param_2;
        if ((local_10 != (size_t *)0x0) && (psVar3 = local_10, (int)param_2 < (int)local_10)) {
          psVar3 = param_2;
        }
        goto LAB_45405efe;
      }
      if (uVar2 == 0x10073) goto LAB_45405e09;
      if (uVar2 == 0x20043) goto LAB_45405e63;
      if (uVar2 == 0x20053) {
LAB_45405e4a:
        if (*psVar6 == 0) goto LAB_45405e53;
        psVar3 = (size_t *)_wcslen((wchar_t *)*psVar6);
LAB_45405e1b:
        psVar7 = psVar6 + 1;
        if ((int)psVar3 < 1) {
          psVar3 = (size_t *)0x1;
        }
        if (psVar3 != (size_t *)0x0) goto LAB_45405e29;
      }
      else {
        if (uVar2 == 0x20063) goto LAB_45405e63;
        if (uVar2 == 0x20073) goto LAB_45405e4a;
      }
LAB_45405e8d:
      iVar5 = (int)*lpsz;
      if (iVar5 < 0x6a) {
        if (iVar5 == 0x69) goto LAB_45405edb;
        if ((iVar5 != 0x45) && (iVar5 != 0x47)) {
          if ((iVar5 == 0x58) || (iVar5 == 100)) goto LAB_45405edb;
          if (2 < iVar5 - 0x65U) goto LAB_45405efe;
        }
        OutputDebugStringA(
                          "Floating point (%%e, %%f, %%g, and %%G) is not supported by the WTL::CString class."
                          );
        DebugBreak();
      }
      else if (iVar5 == 0x6e) {
        psVar7 = psVar7 + 1;
      }
      else {
        if (iVar5 == 0x6f) {
LAB_45405edb:
          if ((local_c & 0x40000) == 0) goto LAB_45405ee8;
          psVar7 = psVar7 + 2;
        }
        else {
          if (iVar5 != 0x70) {
            if ((iVar5 != 0x75) && (iVar5 != 0x78)) goto LAB_45405efe;
            goto LAB_45405edb;
          }
LAB_45405ee8:
          psVar7 = psVar7 + 1;
        }
        psVar3 = (size_t *)((int)local_10 + (int)param_2);
        if ((int)local_10 + (int)param_2 < 0x20) {
          psVar3 = (size_t *)0x20;
        }
      }
LAB_45405efe:
      local_8 = local_8 + (int)psVar3;
    }
    else {
LAB_45405f06:
      pCVar4 = CharNextA(lpsz);
      local_8 = pCVar4 + ((int)local_8 - (int)lpsz);
    }
    lpsz = CharNextA(lpsz);
    cVar1 = *lpsz;
  } while( true );
}


