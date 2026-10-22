// Source: CLCiffConversion_Data.dll @ 450325bf; FUN_450325bf

void __cdecl
FUN_450325bf(wchar_t *param_1,DWORD param_2,PCNZWCH param_3,int param_4,PCNZWCH param_5,int param_6)

{
  LCID Locale;
  
  if ((code *)(DAT_45056f54 ^ DAT_450518d0) != (code *)0x0) {
    (*(code *)(DAT_45056f54 ^ DAT_450518d0))(param_1,param_2,param_3,param_4,param_5,param_6,0,0,0);
    return;
  }
  Locale = FID_conflict__AtlDownlevelLocaleNameToLCID(param_1);
  CompareStringW(Locale,param_2,param_3,param_4,param_5,param_6);
  return;
}


