// Source: CLCiffConversion_Data.dll @ 4500ad70; thunk_FUN_45014032

void __fastcall thunk_FUN_45014032(int *param_1)

{
  if (*param_1 != 0) {
    FUN_45014013(*param_1,param_1[1]);
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


