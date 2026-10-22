// Source: CLCiffConversion_Data.dll @ 45015b73; FUN_45015b73

void FUN_45015b73(HMODULE param_1,wchar_t *param_2)

{
  WCHAR WVar1;
  LPCWSTR lpsz;
  BSTR bstrString;
  int iVar2;
  HRESULT HVar3;
  UINT UVar4;
  LPWSTR pWVar5;
  HMODULE hModule;
  FARPROC pFVar6;
  WCHAR *pWVar7;
  LPCWSTR pWVar8;
  BSTR local_220;
  ITypeLib *local_21c;
  BSTR local_218;
  char local_211;
  WCHAR local_210 [259];
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  pWVar7 = (WCHAR *)0x0;
  local_220 = (BSTR)0x0;
  local_21c = (ITypeLib *)0x0;
  iVar2 = FUN_450156b2(param_1,param_2,&local_220,&local_21c);
  if (-1 < iVar2) {
    local_218 = (BSTR)0x0;
    HVar3 = (*local_21c->lpVtbl->GetDocumentation)
                      (local_21c,-1,(BSTR *)0x0,(BSTR *)0x0,(DWORD *)0x0,&local_218);
    if ((-1 < HVar3) && (local_218 != (BSTR)0x0)) {
      UVar4 = SysStringLen(local_218);
      iVar2 = FUN_45025980(local_210,0x104,local_218,UVar4);
      FUN_450026fa(iVar2);
      pWVar8 = local_210;
      local_a = 0;
      lpsz = pWVar8;
      while (local_210[0] != L'\0') {
        pWVar5 = CharNextW(lpsz);
        WVar1 = *lpsz;
        if (((WVar1 == L'\\') || (WVar1 == L'/')) || (WVar1 == L':')) {
          pWVar8 = pWVar5;
        }
        lpsz = pWVar5;
        local_210[0] = *pWVar5;
      }
      iVar2 = (int)pWVar8 - (int)local_210 >> 1;
      if (0x207 < (uint)(iVar2 * 2)) {
                    /* WARNING: Subroutine does not return */
        ___report_rangecheckfailure();
      }
      pWVar7 = local_210;
      local_210[iVar2] = L'\0';
    }
    bstrString = local_218;
    local_211 = '\0';
    iVar2 = FUN_450155c6(&local_211);
    if (iVar2 < 0) {
      SysFreeString(bstrString);
      if (local_21c != (ITypeLib *)0x0) {
        (*local_21c->lpVtbl->Release)(local_21c);
      }
      SysFreeString(local_220);
      goto LAB_45015d2a;
    }
    if (((local_211 != '\x01') ||
        (hModule = GetModuleHandleW(L"OLEAUT32.DLL"), hModule == (HMODULE)0x0)) ||
       (pFVar6 = GetProcAddress(hModule,"RegisterTypeLibForUser"), pFVar6 == (FARPROC)0x0)) {
      pFVar6 = RegisterTypeLib_exref;
    }
    (*pFVar6)(local_21c,local_220,pWVar7);
    SysFreeString(local_218);
  }
  if (local_21c != (ITypeLib *)0x0) {
    (*local_21c->lpVtbl->Release)(local_21c);
  }
  SysFreeString(local_220);
LAB_45015d2a:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


