// Source: CLCiffConversion_Layout.dll @ 45402d4b; FUN_45402d4b

bool __thiscall FUN_45402d4b(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_454028ee(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


