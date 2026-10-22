// Source: CLCSSmallBarcode.dll @ 420284e3; FUN_420284e3

void __fastcall FUN_420284e3(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
      FUN_42009b75((int *)(iVar2 + 0x18));
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


