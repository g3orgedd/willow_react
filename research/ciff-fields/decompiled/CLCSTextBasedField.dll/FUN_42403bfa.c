// Source: CLCSTextBasedField.dll @ 42403bfa; FUN_42403bfa

bool __thiscall FUN_42403bfa(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_424037d2(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


