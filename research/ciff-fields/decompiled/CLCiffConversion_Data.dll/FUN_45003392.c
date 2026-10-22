// Source: CLCiffConversion_Data.dll @ 45003392; FUN_45003392

void FUN_45003392(void)

{
  LPCWSTR lpFileName;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  lpFileName = FUN_4501ca38();
  GetPrivateProfileStringW
            (L"Generic",L"Start of Day Enabled",(LPCWSTR)0x0,local_210,0x104,lpFileName);
  FUN_45022835(local_210);
  local_210[0] = L'㏠';
  local_210[1] = L'䔀';
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


