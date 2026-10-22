// Source: CiffMgr.dll @ 68105a42; Catch_All@68105a42

void Catch_All_68105a42(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  VARIANTARG *pvarg;
  
  iVar2 = *(int *)(unaff_EBP + 0x10) * 0x10;
  iVar1 = *(int *)(*(int *)(unaff_EBP + -0x24) + 4);
  for (pvarg = (VARIANTARG *)(*(int *)(unaff_EBP + 0xc) + iVar2);
      pvarg != (VARIANTARG *)(iVar1 + iVar2); pvarg = pvarg + 1) {
    VariantClear(pvarg);
  }
                    /* WARNING: Subroutine does not return */
  FUN_68132060((int *)0x0,(byte *)0x0);
}


