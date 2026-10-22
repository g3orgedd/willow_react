// Source: CiffHelper.dll @ 40802ea3; FUN_40802ea3

void __fastcall FUN_40802ea3(int *param_1)

{
  if (*param_1 != 0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  SysFreeString((BSTR)*param_1);
  return;
}


