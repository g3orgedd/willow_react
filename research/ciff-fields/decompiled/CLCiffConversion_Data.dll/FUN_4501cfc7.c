// Source: CLCiffConversion_Data.dll @ 4501cfc7; FUN_4501cfc7

void __fastcall FUN_4501cfc7(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0xc) {
      FUN_450022b9();
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


