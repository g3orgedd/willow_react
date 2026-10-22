// Source: CLCiffConversion_Layout.dll @ 45402d1b; FUN_45402d1b

bool __thiscall FUN_45402d1b(void *this,BSTR param_1)

{
  bool bVar1;
  
  FUN_454028b9(&param_1,(char *)param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


