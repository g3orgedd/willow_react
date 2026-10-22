// Source: CLCiffConversion_Data.dll @ 4501d466; FUN_4501d466

void FUN_4501d466(void)

{
  LPCWSTR lpFileName;
  
  lpFileName = FUN_4501ca38();
  GetPrivateProfileIntW(L"CLARiNET",L"Variable Date Format",0,lpFileName);
  return;
}


