// Source: CLCiffConversion_Layout.dll @ 45403fc8; FUN_45403fc8

void __fastcall FUN_45403fc8(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((undefined *)(*param_1 + -0xc) != PTR_DAT_4545d10c) {
    piVar2 = (int *)(*param_1 + -0xc);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      FID_conflict__free((void *)(*param_1 + -0xc));
    }
    *param_1 = (int)PTR_DAT_4545d110;
  }
  return;
}


