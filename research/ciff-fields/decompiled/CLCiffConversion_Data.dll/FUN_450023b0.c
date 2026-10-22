// Source: CLCiffConversion_Data.dll @ 450023b0; FUN_450023b0

bool __thiscall FUN_450023b0(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_45001f5d(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


