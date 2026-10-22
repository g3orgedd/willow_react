// Source: CiffMgr.dll @ 68119d18; FUN_68119d18

bool __thiscall FUN_68119d18(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_6810210e(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


