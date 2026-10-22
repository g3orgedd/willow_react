// Source: CLCiffConversion_Layout.dll @ 4543bfe6; FUN_4543bfe6

void __cdecl
FUN_4543bfe6(wchar_t *param_1,DWORD param_2,PCNZWCH param_3,int param_4,PCNZWCH param_5,int param_6)

{
  LCID Locale;
  
  if ((code *)(DAT_45462754 ^ DAT_4545d9f0) != (code *)0x0) {
    (*(code *)(DAT_45462754 ^ DAT_4545d9f0))(param_1,param_2,param_3,param_4,param_5,param_6,0,0,0);
    return;
  }
  Locale = FID_conflict__AtlDownlevelLocaleNameToLCID(param_1);
  CompareStringW(Locale,param_2,param_3,param_4,param_5,param_6);
  return;
}


