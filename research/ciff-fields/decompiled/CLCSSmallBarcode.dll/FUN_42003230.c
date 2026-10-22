// Source: CLCSSmallBarcode.dll @ 42003230; FUN_42003230

bool __thiscall FUN_42003230(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_42002eae(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


