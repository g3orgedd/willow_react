// Source: CLCiffConversion_Data.dll @ 4500ad83; FUN_4500ad83

void __fastcall FUN_4500ad83(int *param_1)

{
  if (*param_1 != 0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  SysFreeString((BSTR)*param_1);
  return;
}


