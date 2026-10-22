// Source: CLARiSOFT.exe @ 00e03edc; FUN_00e03edc

bool __thiscall FUN_00e03edc(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_00e03b21(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


