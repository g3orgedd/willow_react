// Source: CLCSBarcodeField.dll @ 4144a9c2; FUN_4144a9c2

LPSIZE __thiscall FUN_4144a9c2(void *this,LPSIZE param_1,int param_2,HDC param_3,BSTR param_4)

{
  UINT c;
  
  FUN_4144bd3a(this,param_3,(int)param_4);
  FUN_41402f15(&param_4,*(OLECHAR **)(param_2 + 0x83c));
  c = SysStringLen(param_4);
  GetTextExtentPoint32W(param_3,param_4,c,param_1);
  FUN_4144a22f(this,param_3);
  SysFreeString(param_4);
  return param_1;
}


