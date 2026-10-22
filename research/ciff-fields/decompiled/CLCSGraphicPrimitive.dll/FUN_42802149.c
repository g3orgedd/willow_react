// Source: CLCSGraphicPrimitive.dll @ 42802149; FUN_42802149

bool __thiscall FUN_42802149(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_42801dad(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


