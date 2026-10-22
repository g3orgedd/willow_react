// Source: CLCSBarcodeField.dll @ 41449652; FUN_41449652

void __fastcall FUN_41449652(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = param_1[1];
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
      FUN_41439315((int *)(iVar2 + 0x18));
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


