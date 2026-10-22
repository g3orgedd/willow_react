// Source: CLARiSOFT.exe @ 00e56780; FUN_00e56780

void FUN_00e56780(void)

{
  LPCWSTR lpFileName;
  
  lpFileName = FUN_00eb81f8();
  GetPrivateProfileIntW(L"CLARiSOFT",L"PrintsPerSequence",0,lpFileName);
  return;
}


