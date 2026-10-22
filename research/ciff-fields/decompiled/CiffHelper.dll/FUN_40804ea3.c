// Source: CiffHelper.dll @ 40804ea3; FUN_40804ea3

void FUN_40804ea3(void)

{
  LPCWSTR lpFileName;
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  lpFileName = FUN_408288b7();
  GetPrivateProfileStringW
            (L"Generic",L"Start of Day Enabled",(LPCWSTR)0x0,local_210,0x104,lpFileName);
  FUN_4082ee87(local_210);
  local_210[0] = L'仱';
  local_210[1] = L'䂀';
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


