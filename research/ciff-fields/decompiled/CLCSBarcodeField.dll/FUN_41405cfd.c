// Source: CLCSBarcodeField.dll @ 41405cfd; FUN_41405cfd

void __fastcall FUN_41405cfd(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_414a9014) {
    piVar2 = (int *)(*param_1 + -0xc);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      FID_conflict__free((void *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_414a9018;
  }
  return;
}


