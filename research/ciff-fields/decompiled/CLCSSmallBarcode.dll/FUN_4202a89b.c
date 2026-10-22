// Source: CLCSSmallBarcode.dll @ 4202a89b; FUN_4202a89b

LPSIZE __thiscall FUN_4202a89b(void *this,LPSIZE param_1,int param_2,HDC param_3,BSTR param_4)

{
  UINT c;
  
  FUN_4202bab9(this,param_3,(int)param_4);
  FUN_42002eae(&param_4,*(OLECHAR **)(param_2 + 0x83c));
  c = SysStringLen(param_4);
  GetTextExtentPoint32W(param_3,param_4,c,param_1);
  FUN_4202a25a(this,param_3);
  SysFreeString(param_4);
  return param_1;
}


