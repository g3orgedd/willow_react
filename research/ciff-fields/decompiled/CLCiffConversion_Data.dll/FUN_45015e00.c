// Source: CLCiffConversion_Data.dll @ 45015e00; FUN_45015e00

undefined1 __cdecl FUN_45015e00(LPCWSTR param_1)

{
  LPCWSTR pWVar1;
  UINT UVar2;
  
  if (DAT_45053905 == '\0') {
    pWVar1 = FUN_4501ca38();
    UVar2 = GetPrivateProfileIntW(L"Debug",L"All",0,pWVar1);
    if (UVar2 == 0) {
      pWVar1 = FUN_4501ca38();
      UVar2 = GetPrivateProfileIntW(L"Debug",param_1,0,pWVar1);
      DAT_45053904 = UVar2 != 0;
      DAT_45053905 = '\x01';
    }
    else {
      DAT_45053905 = '\x01';
      DAT_45053904 = 1;
    }
  }
  return DAT_45053904;
}


