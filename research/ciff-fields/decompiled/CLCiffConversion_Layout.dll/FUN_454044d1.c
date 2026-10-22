// Source: CLCiffConversion_Layout.dll @ 454044d1; FUN_454044d1

void __fastcall FUN_454044d1(int *param_1)

{
  if (*param_1 != 0) {
    SysFreeString((BSTR)*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    FID_conflict__free((void *)param_1[1]);
    param_1[1] = 0;
  }
  return;
}


