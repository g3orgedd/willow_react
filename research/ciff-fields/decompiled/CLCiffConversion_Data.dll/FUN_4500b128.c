// Source: CLCiffConversion_Data.dll @ 4500b128; FUN_4500b128

void FUN_4500b128(IID *param_1,WCHAR *param_2,DWORD param_3,IErrorInfo *param_4,GUID *param_5,
                 int param_6,HINSTANCE param_7)

{
  IErrorInfo *szHelpFile;
  HRESULT HVar1;
  GUID *local_814;
  IErrorInfo *local_810;
  ICreateErrorInfo *local_80c;
  WCHAR local_808 [1024];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_814 = param_5;
  local_810 = param_4;
  local_808[0] = L'\0';
  if (((uint)param_2 & 0xffff0000) == 0) {
    LoadStringW(param_7,(uint)param_2 & 0xffff,local_808,0x400);
    param_2 = local_808;
  }
  szHelpFile = local_810;
  local_80c = (ICreateErrorInfo *)0x0;
  HVar1 = CreateErrorInfo(&local_80c);
  if (-1 < HVar1) {
    local_810 = (IErrorInfo *)0x0;
    (*local_80c->lpVtbl->SetGUID)(local_80c,local_814);
    HVar1 = ProgIDFromCLSID(param_1,(LPOLESTR *)&local_814);
    if (HVar1 < 0) {
      local_814 = (GUID *)0x0;
    }
    if (local_814 != (GUID *)0x0) {
      (*local_80c->lpVtbl->SetSource)(local_80c,(LPOLESTR)local_814);
    }
    if ((param_3 != 0) && (szHelpFile != (IErrorInfo *)0x0)) {
      (*local_80c->lpVtbl->SetHelpContext)(local_80c,param_3);
      (*local_80c->lpVtbl->SetHelpFile)(local_80c,(LPOLESTR)szHelpFile);
    }
    CoTaskMemFree(local_814);
    (*local_80c->lpVtbl->SetDescription)(local_80c,param_2);
    HVar1 = (*local_80c->lpVtbl->QueryInterface)(local_80c,(IID *)&DAT_4503e450,&local_810);
    if (-1 < HVar1) {
      SetErrorInfo(0,local_810);
    }
    if (local_810 != (IErrorInfo *)0x0) {
      (*local_810->lpVtbl->Release)(local_810);
    }
  }
  if (local_80c != (ICreateErrorInfo *)0x0) {
    (*local_80c->lpVtbl->Release)(local_80c);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


