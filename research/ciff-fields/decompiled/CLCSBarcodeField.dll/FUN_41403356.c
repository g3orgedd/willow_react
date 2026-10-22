// Source: CLCSBarcodeField.dll @ 41403356; FUN_41403356

bool __thiscall FUN_41403356(void *this,OLECHAR *param_1)

{
  bool bVar1;
  
  FUN_41402f15(&param_1,param_1);
  bVar1 = ATL::CComBSTR::operator==(this,(CComBSTR *)&param_1);
  SysFreeString(param_1);
  return bVar1;
}


