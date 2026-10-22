// Source: CLCSBarcodeField.dll @ 414031f1; FUN_414031f1

void __fastcall FUN_414031f1(int *param_1)

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
  }
  return;
}


