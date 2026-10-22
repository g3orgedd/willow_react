// Source: CLCiffConversion_Layout.dll @ 45414b7d; FUN_45414b7d

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_45414b7d(IID *param_1,wchar_t *param_2,DWORD param_3,LPOLESTR param_4,GUID *param_5,
                 int param_6,HINSTANCE param_7)

{
  LPOLESTR pOVar1;
  IErrorInfo *pIVar2;
  bool bVar3;
  int iVar4;
  errno_t eVar5;
  size_t sVar6;
  long lVar7;
  wchar_t *pwVar8;
  HRESULT HVar9;
  LPOLESTR _Memory;
  IErrorInfo *local_414;
  LPOLESTR local_410;
  ICreateErrorInfo *local_40c;
  CHAR local_408 [1024];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  _Memory = (LPOLESTR)0x0;
  local_410 = (LPOLESTR)0x0;
  local_408[0] = '\0';
  if (((uint)param_2 & 0xffff0000) == 0) {
    iVar4 = LoadStringA(param_7,(uint)param_2 & 0xffff,local_408,0x400);
    if (iVar4 == 0) {
      eVar5 = _strcpy_s(local_408,0x400,"Unknown Error");
      FUN_45402fb2(eVar5);
    }
    sVar6 = _strlen(local_408);
    local_414 = (IErrorInfo *)(sVar6 + 1);
    lVar7 = ATL::AtlMultiply<int>((int *)&local_414,(int)local_414,2);
    pIVar2 = local_414;
    if (lVar7 < 0) goto LAB_45414dce;
    if (((int)local_414 < 0x401) &&
       (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_414), bVar3)) {
      pwVar8 = (wchar_t *)&stack0xfffffbd0;
    }
    else {
      pwVar8 = (wchar_t *)FUN_454145c6(&local_410,(int)pIVar2);
      _Memory = local_410;
    }
    param_2 = AtlA2WHelper(pwVar8,local_408,(uint)pIVar2 >> 1,3);
    if (param_2 == (wchar_t *)0x0) {
      while (_Memory != (LPOLESTR)0x0) {
        pOVar1 = *(LPOLESTR *)_Memory;
        FID_conflict__free(_Memory);
        _Memory = pOVar1;
      }
      goto LAB_45414dce;
    }
  }
  local_40c = (ICreateErrorInfo *)0x0;
  HVar9 = CreateErrorInfo(&local_40c);
  if (-1 < HVar9) {
    local_414 = (IErrorInfo *)0x0;
    (*local_40c->lpVtbl->SetGUID)(local_40c,param_5);
    HVar9 = ProgIDFromCLSID(param_1,&local_410);
    if (HVar9 < 0) {
      local_410 = (LPOLESTR)0x0;
    }
    if (local_410 != (LPOLESTR)0x0) {
      (*local_40c->lpVtbl->SetSource)(local_40c,local_410);
    }
    if ((param_3 != 0) && (param_4 != (LPOLESTR)0x0)) {
      (*local_40c->lpVtbl->SetHelpContext)(local_40c,param_3);
      (*local_40c->lpVtbl->SetHelpFile)(local_40c,param_4);
    }
    CoTaskMemFree(local_410);
    (*local_40c->lpVtbl->SetDescription)(local_40c,param_2);
    HVar9 = (*local_40c->lpVtbl->QueryInterface)(local_40c,(IID *)&DAT_45449478,&local_414);
    if (-1 < HVar9) {
      SetErrorInfo(0,local_414);
    }
    if (local_414 != (IErrorInfo *)0x0) {
      (*local_414->lpVtbl->Release)(local_414);
    }
  }
  if (local_40c != (ICreateErrorInfo *)0x0) {
    (*local_40c->lpVtbl->Release)(local_40c);
  }
  while (_Memory != (LPOLESTR)0x0) {
    pOVar1 = *(LPOLESTR *)_Memory;
    FID_conflict__free(_Memory);
    _Memory = pOVar1;
  }
LAB_45414dce:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


