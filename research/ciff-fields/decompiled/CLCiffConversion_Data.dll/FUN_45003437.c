// Source: CLCiffConversion_Data.dll @ 45003437; FUN_45003437

void __cdecl FUN_45003437(void *param_1)

{
  LPCWSTR lpFileName;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  lpFileName = FUN_4501ca38();
  GetPrivateProfileStringW
            (L"Generic",L"Start of Day Offset",L"notpresent",local_210,0x104,lpFileName);
  FUN_450020a5(param_1,local_210);
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


