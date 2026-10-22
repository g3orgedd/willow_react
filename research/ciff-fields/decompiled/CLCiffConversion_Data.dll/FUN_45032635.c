// Source: CLCiffConversion_Data.dll @ 45032635; FUN_45032635

void __cdecl
FUN_45032635(wchar_t *param_1,DWORD param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,int param_6)

{
  LCID Locale;
  
  if ((code *)(DAT_45056f70 ^ DAT_450518d0) != (code *)0x0) {
    (*(code *)(DAT_45056f70 ^ DAT_450518d0))(param_1,param_2,param_3,param_4,param_5,param_6,0,0,0);
    return;
  }
  Locale = FID_conflict__AtlDownlevelLocaleNameToLCID(param_1);
  LCMapStringW(Locale,param_2,param_3,param_4,param_5,param_6);
  return;
}


