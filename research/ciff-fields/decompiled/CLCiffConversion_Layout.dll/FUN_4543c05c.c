// Source: CLCiffConversion_Layout.dll @ 4543c05c; FUN_4543c05c

void __cdecl
FUN_4543c05c(wchar_t *param_1,DWORD param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,int param_6)

{
  LCID Locale;
  
  if ((code *)(DAT_45462770 ^ DAT_4545d9f0) != (code *)0x0) {
    (*(code *)(DAT_45462770 ^ DAT_4545d9f0))(param_1,param_2,param_3,param_4,param_5,param_6,0,0,0);
    return;
  }
  Locale = FID_conflict__AtlDownlevelLocaleNameToLCID(param_1);
  LCMapStringW(Locale,param_2,param_3,param_4,param_5,param_6);
  return;
}


