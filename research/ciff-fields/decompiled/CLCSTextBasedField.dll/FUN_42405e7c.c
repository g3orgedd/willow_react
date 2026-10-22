// Source: CLCSTextBasedField.dll @ 42405e7c; FUN_42405e7c

void __fastcall FUN_42405e7c(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_424b9010) {
    piVar2 = (int *)(*param_1 + -0xc);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      FID_conflict__free((void *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_424b9014;
  }
  return;
}


