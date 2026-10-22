// Source: CiffMgr.dll @ 6811115c; FUN_6811115c

void __fastcall FUN_6811115c(int *param_1)

{
  if (*param_1 != 0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  SysFreeString((BSTR)*param_1);
  return;
}


