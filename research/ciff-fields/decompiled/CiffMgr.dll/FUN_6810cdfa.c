// Source: CiffMgr.dll @ 6810cdfa; FUN_6810cdfa

void FUN_6810cdfa(HMODULE param_1,wchar_t *param_2)

{
  BSTR bstrString;
  int iVar1;
  HRESULT HVar2;
  UINT UVar3;
  HMODULE hModule;
  FARPROC pFVar4;
  WCHAR *pWVar5;
  BSTR local_220;
  ITypeLib *local_21c;
  BSTR local_218;
  char local_211;
  WCHAR local_210 [259];
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  local_220 = (BSTR)0x0;
  local_21c = (ITypeLib *)0x0;
  iVar1 = FUN_6810c94f(param_1,param_2,&local_220,&local_21c);
  if (-1 < iVar1) {
    pWVar5 = (WCHAR *)0x0;
    local_218 = (BSTR)0x0;
    HVar2 = (*local_21c->lpVtbl->GetDocumentation)
                      (local_21c,-1,(BSTR *)0x0,(BSTR *)0x0,(DWORD *)0x0,&local_218);
    if ((-1 < HVar2) && (local_218 != (BSTR)0x0)) {
      UVar3 = SysStringLen(local_218);
      iVar1 = FUN_681349da(local_210,0x104,local_218,UVar3);
      FUN_68103e74(iVar1);
      local_a = 0;
      iVar1 = FUN_6810c8b9(local_210);
      if (0x207 < (uint)(iVar1 * 2)) {
                    /* WARNING: Subroutine does not return */
        ___report_rangecheckfailure();
      }
      pWVar5 = local_210;
      local_210[iVar1] = L'\0';
    }
    bstrString = local_218;
    local_211 = '\0';
    iVar1 = FUN_6810c905(&local_211);
    if (iVar1 < 0) {
      SysFreeString(bstrString);
      if (local_21c != (ITypeLib *)0x0) {
        (*local_21c->lpVtbl->Release)(local_21c);
      }
      SysFreeString(local_220);
      goto LAB_6810cf76;
    }
    if (local_211 == '\x01') {
      hModule = GetModuleHandleW(L"OLEAUT32.DLL");
      if (hModule == (HMODULE)0x0) goto LAB_6810cf36;
      pFVar4 = GetProcAddress(hModule,"RegisterTypeLibForUser");
      if (pFVar4 == (FARPROC)0x0) goto LAB_6810cf36;
    }
    else {
LAB_6810cf36:
      pFVar4 = RegisterTypeLib_exref;
    }
    (*pFVar4)(local_21c,local_220,pWVar5);
    SysFreeString(local_218);
  }
  if (local_21c != (ITypeLib *)0x0) {
    (*local_21c->lpVtbl->Release)(local_21c);
  }
  SysFreeString(local_220);
LAB_6810cf76:
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


