// Source: CLCSGraphicBasedField.dll @ 41c01781; FUN_41c01781

bool __thiscall FUN_41c01781(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_41c013b1(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


