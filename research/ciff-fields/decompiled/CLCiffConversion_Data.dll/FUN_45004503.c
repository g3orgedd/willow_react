// Source: CLCiffConversion_Data.dll @ 45004503; FUN_45004503

void __fastcall FUN_45004503(int *param_1)

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


