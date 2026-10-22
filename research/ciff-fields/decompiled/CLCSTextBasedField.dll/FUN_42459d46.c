// Source: CLCSTextBasedField.dll @ 42459d46; FUN_42459d46

void __cdecl FUN_42459d46(void *param_1)

{
  LPCWSTR lpFileName;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  lpFileName = FUN_42459dd8();
  GetPrivateProfileStringW(L"Generic",L"Installation Location",L"",local_210,0x104,lpFileName);
  FUN_4240391a(param_1,local_210);
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


