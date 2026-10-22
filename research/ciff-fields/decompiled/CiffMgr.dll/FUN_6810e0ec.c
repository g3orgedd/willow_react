// Source: CiffMgr.dll @ 6810e0ec; FUN_6810e0ec

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_6810e0ec(void *this,LPCWSTR param_1,HKEY param_2,int param_3,int param_4)

{
  HKEY pHVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  LPCWSTR pWVar5;
  uint uVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t sVar7;
  CRegKey *this_00;
  HKEY local_2264;
  undefined4 local_2260;
  undefined4 local_225c;
  HKEY local_2258;
  undefined4 local_2254;
  undefined4 local_2250;
  HKEY local_224c;
  undefined4 local_2248;
  undefined4 local_2244;
  int local_2240;
  HKEY local_223c;
  undefined4 local_2238;
  undefined4 local_2234;
  HKEY local_2230;
  undefined4 local_222c;
  undefined4 local_2228;
  HKEY local_2224;
  uint local_2220;
  wchar_t local_221c [4096];
  WCHAR local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_681433c1;
  local_10 = ExceptionList;
  local_14 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2224 = param_2;
  local_2230 = (HKEY)0x0;
  local_222c = 0;
  local_2228 = 0;
  local_8 = 0;
  uStack_7 = 0;
LAB_6810e14c:
  iVar3 = FUN_6810d73a(this,param_1);
  do {
    if (iVar3 < 0) {
LAB_6810e68f:
      ATL::CRegKey::Close((CRegKey *)&local_2230);
      ExceptionList = local_10;
      FUN_68132051(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
LAB_6810e15e:
    if (*param_1 == L'}') goto LAB_6810e68f;
    local_2240 = 1;
    iVar3 = lstrcmpiW(param_1,L"Delete");
    local_2220 = (uint)(iVar3 == 0);
    iVar4 = lstrcmpiW(param_1,L"ForceRemove");
    if ((iVar4 == 0) || ((iVar3 == 0) != 0)) {
      iVar3 = FUN_6810d73a(this,param_1);
      if (iVar3 < 0) goto LAB_6810e68f;
      if (param_3 == 0) goto LAB_6810e270;
      local_223c = (HKEY)0x0;
      local_2238 = 0;
      local_2234 = 0;
      pWVar5 = FUN_6810e9ce(param_1,L'\\');
      if (pWVar5 == (LPCWSTR)0x0) {
        iVar3 = FUN_6810d04c(param_1);
        if (iVar3 != 0) {
          local_223c = local_2224;
          local_2238 = 0;
          local_2234 = 0;
          ATL::CRegKey::RecurseDeleteKey((CRegKey *)&local_223c,param_1);
          local_223c = (HKEY)0x0;
          local_2238 = 0;
          local_2234 = 0;
        }
        if (local_2220 == 0) {
          ATL::CRegKey::Close((CRegKey *)&local_223c);
          goto LAB_6810e270;
        }
        iVar3 = FUN_6810d73a(this,param_1);
        if (-1 < iVar3) {
          iVar3 = FUN_6810e945(this,param_1);
          ATL::CRegKey::Close((CRegKey *)&local_223c);
LAB_6810e254:
          if (-1 < iVar3) goto LAB_6810e633;
          goto LAB_6810e68f;
        }
        this_00 = (CRegKey *)&local_223c;
        goto LAB_6810e6c9;
      }
      ATL::CRegKey::Close((CRegKey *)&local_223c);
      goto LAB_6810e68f;
    }
LAB_6810e270:
    iVar3 = lstrcmpiW(param_1,L"NoRemove");
    if (iVar3 == 0) {
      local_2240 = 0;
      iVar3 = FUN_6810d73a(this,param_1);
      if (iVar3 < 0) goto LAB_6810e68f;
    }
    iVar3 = lstrcmpiW(param_1,L"Val");
    if (iVar3 != 0) {
      pWVar5 = FUN_6810e9ce(param_1,L'\\');
      pHVar1 = local_2224;
      if (pWVar5 == (LPCWSTR)0x0) {
        if (param_3 == 0) {
          if (param_4 == 0) {
            local_2220 = Open(&local_2230,local_2224,param_1,0x20019);
          }
          else {
            local_2220 = 2;
          }
          iVar3 = param_4;
          if (local_2220 != 0) {
            iVar3 = 1;
          }
          iVar4 = FUN_681349da(local_21c,0x104,param_1,-1);
          FUN_68103e74(iVar4);
          iVar4 = FUN_6810d73a(this,param_1);
          if (((-1 < iVar4) && (iVar4 = FUN_6810e945(this,param_1), -1 < iVar4)) &&
             (((*param_1 != L'{' || (sVar7 = _wcslen(param_1), sVar7 != 1)) ||
              (((iVar4 = FUN_6810e0ec(this,param_1,local_2230,0,iVar3), -1 < iVar4 || (iVar3 != 0))
               && (iVar3 = FUN_6810d73a(this,param_1), -1 < iVar3)))))) break;
        }
        else {
          iVar3 = Open(&local_2230,local_2224,param_1,0x2001f);
          if (((iVar3 != 0) && (iVar3 = Open(&local_2230,pHVar1,param_1,0x20019), iVar3 != 0)) &&
             (uVar6 = Create(&local_2230,pHVar1,param_1,(LPWSTR)0x0,0,0x2001f,
                             (LPSECURITY_ATTRIBUTES)0x0,(undefined4 *)0x0), uVar6 != 0))
          goto LAB_6810e549;
          iVar3 = FUN_6810d73a(this,param_1);
          if (-1 < iVar3) {
            if (*param_1 == L'=') {
              iVar3 = FUN_6810c13f(this,(CRegKey *)&local_2230,(wchar_t *)0x0,param_1);
              goto LAB_6810e254;
            }
            goto LAB_6810e633;
          }
        }
      }
      goto LAB_6810e68f;
    }
    iVar3 = FUN_6810d73a(this,local_221c);
    if (((iVar3 < 0) || (iVar3 = FUN_6810d73a(this,param_1), iVar3 < 0)) || (*param_1 != L'='))
    goto LAB_6810e68f;
    if (param_3 != 0) {
      local_2254 = 0;
      local_2250 = 0;
      local_8 = 1;
      local_2258 = local_2224;
      iVar3 = FUN_6810c13f(this,(CRegKey *)&local_2258,local_221c,param_1);
      this_00 = (CRegKey *)&local_2258;
      local_2258 = (HKEY)0x0;
      local_2254 = 0;
      local_2250 = 0;
      if (-1 < iVar3) {
        local_8 = 0;
        goto LAB_6810e62e;
      }
      goto LAB_6810e6c9;
    }
    if ((param_4 == 0) && (local_2240 != 0)) {
      local_2264 = (HKEY)0x0;
      local_2260 = 0;
      local_225c = 0;
      uVar6 = Open(&local_2264,local_2224,(LPCWSTR)0x0,0x20006);
      if ((uVar6 != 0) ||
         ((uVar6 = RegDeleteValueW(local_2264,local_221c), uVar6 != 0 && (uVar6 != 2)))) {
        FUN_6810c93a(uVar6);
        this_00 = (CRegKey *)&local_2264;
LAB_6810e6c9:
        ATL::CRegKey::Close(this_00);
        goto LAB_6810e68f;
      }
      ATL::CRegKey::Close((CRegKey *)&local_2264);
    }
    iVar3 = FUN_6810e945(this,param_1);
  } while( true );
  if (local_2220 != 2) {
    if (local_2220 == 0) {
      if ((param_4 != 0) && (bVar2 = FUN_6810d5f3(local_2230), CONCAT31(extraout_var,bVar2) != 0)) {
        iVar3 = FUN_6810d04c(local_21c);
        if ((iVar3 != 0) && (local_2240 != 0)) {
          ATL::CRegKey::RecurseDeleteKey((CRegKey *)&local_2230,local_21c);
        }
        goto LAB_6810e15e;
      }
      bVar2 = FUN_6810d5f3(local_2230);
      local_2220 = CONCAT31(extraout_var_00,bVar2);
      uVar6 = ATL::CRegKey::Close((CRegKey *)&local_2230);
      if (uVar6 == 0) {
        if ((local_2240 != 0) && (local_2220 == 0)) {
          local_2248 = 0;
          local_2244 = 0;
          local_224c = local_2224;
          uVar6 = DeleteSubKey(&local_224c,local_21c);
          local_224c = (HKEY)0x0;
          local_2248 = 0;
          local_2244 = 0;
          if (uVar6 != 0) {
            FUN_6810c93a(uVar6);
            this_00 = (CRegKey *)&local_224c;
            goto LAB_6810e6c9;
          }
          this_00 = (CRegKey *)&local_224c;
LAB_6810e62e:
          ATL::CRegKey::Close(this_00);
LAB_6810e633:
          if (((param_3 != 0) && (*param_1 == L'{')) && (sVar7 = _wcslen(param_1), sVar7 == 1)) {
            iVar3 = FUN_6810e0ec(this,param_1,local_2230,param_3,0);
            if (-1 < iVar3) goto LAB_6810e14c;
            goto LAB_6810e68f;
          }
        }
        goto LAB_6810e15e;
      }
    }
    else {
      uVar6 = local_2220;
      if (param_4 != 0) goto LAB_6810e15e;
    }
LAB_6810e549:
    FUN_6810c93a(uVar6);
    goto LAB_6810e68f;
  }
  goto LAB_6810e15e;
}


