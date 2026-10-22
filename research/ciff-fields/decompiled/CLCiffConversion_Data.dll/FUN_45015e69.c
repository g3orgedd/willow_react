// Source: CLCiffConversion_Data.dll @ 45015e69; FUN_45015e69

undefined1 __cdecl FUN_45015e69(LPCWSTR param_1)

{
  LPCWSTR pWVar1;
  UINT UVar2;
  
  if (DAT_45053907 == '\0') {
    pWVar1 = FUN_4501ca38();
    UVar2 = GetPrivateProfileIntW(L"DebugLog",L"All",0,pWVar1);
    if (UVar2 == 0) {
      pWVar1 = FUN_4501ca38();
      UVar2 = GetPrivateProfileIntW(L"DebugLog",param_1,0,pWVar1);
      DAT_45053906 = UVar2 != 0;
      DAT_45053907 = '\x01';
    }
    else {
      DAT_45053907 = '\x01';
      DAT_45053906 = 1;
    }
  }
  return DAT_45053906;
}


