// Source: CLCSBlockTextField.dll @ 418016e4; FUN_418016e4

bool __thiscall FUN_418016e4(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_4180139e(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


