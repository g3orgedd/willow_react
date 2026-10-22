// Source: CiffMgr.dll @ 6810cf8f; FUN_6810cf8f

int FUN_6810cf8f(TLIBATTR *param_1,wchar_t *param_2)

{
  int iVar1;
  HMODULE hModule;
  FARPROC pFVar2;
  BSTR local_c;
  ITypeLib *local_8;
  
  local_c = (BSTR)0x0;
  local_8 = (ITypeLib *)0x0;
  iVar1 = FUN_6810c94f((HMODULE)param_1,param_2,&local_c,&local_8);
  if (iVar1 < 0) goto LAB_6810d02d;
  iVar1 = (*local_8->lpVtbl->GetLibAttr)(local_8,&param_1);
  if (iVar1 < 0) goto LAB_6810d02d;
  param_2 = (wchar_t *)((uint)param_2 & 0xffffff);
  iVar1 = FUN_6810c905((undefined1 *)((int)&param_2 + 3));
  if (iVar1 < 0) goto LAB_6810d02d;
  if (param_2._3_1_ == '\x01') {
    hModule = GetModuleHandleW(L"OLEAUT32.DLL");
    if (hModule == (HMODULE)0x0) goto LAB_6810d003;
    pFVar2 = GetProcAddress(hModule,"UnRegisterTypeLibForUser");
    if (pFVar2 == (FARPROC)0x0) goto LAB_6810d003;
  }
  else {
LAB_6810d003:
    pFVar2 = UnRegisterTypeLib_exref;
  }
  iVar1 = (*pFVar2)(param_1,(uint)param_1->wMajorVerNum,(uint)param_1->wMinorVerNum,param_1->lcid,
                    param_1->syskind);
  (*local_8->lpVtbl->ReleaseTLibAttr)(local_8,param_1);
LAB_6810d02d:
  if (local_8 != (ITypeLib *)0x0) {
    (*local_8->lpVtbl->Release)(local_8);
  }
  SysFreeString(local_c);
  return iVar1;
}


