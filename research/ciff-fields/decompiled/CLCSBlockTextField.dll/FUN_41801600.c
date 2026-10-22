// Source: CLCSBlockTextField.dll @ 41801600; FUN_41801600

void __fastcall FUN_41801600(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_4184410c) {
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


