// Source: CLCSRichTextBlockField.dll @ 418016de; FUN_418016de

bool __thiscall FUN_418016de(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_41801397(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


