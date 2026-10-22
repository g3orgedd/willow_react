// Source: CLCiffConversion_Data.dll @ 450032a1; FUN_450032a1

void FUN_450032a1(void)

{
  LPCWSTR lpFileName;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  lpFileName = FUN_4501ca38();
  GetPrivateProfileStringW(L"Generic",L"DataSources",L"",local_210,0x104,lpFileName);
  FUN_45022835(local_210);
  local_210[0] = L'㋲';
  local_210[1] = L'䔀';
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


