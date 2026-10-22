// Source: CiffHelper.dll @ 40803ed6; FUN_40803ed6

bool __thiscall FUN_40803ed6(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_40802e40(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


