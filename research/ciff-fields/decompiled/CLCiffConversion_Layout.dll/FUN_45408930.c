// Source: CLCiffConversion_Layout.dll @ 45408930; FUN_45408930

void __fastcall FUN_45408930(int *param_1)

{
  if (*param_1 != 0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  SysFreeString((BSTR)*param_1);
  return;
}


