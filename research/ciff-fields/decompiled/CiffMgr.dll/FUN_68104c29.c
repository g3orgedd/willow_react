// Source: CiffMgr.dll @ 68104c29; Catch_All@68104c29

void Catch_All_68104c29(void)

{
  int unaff_EBP;
  VARIANTARG *pvarg;
  
  for (pvarg = *(VARIANTARG **)(unaff_EBP + -0x14); pvarg != *(VARIANTARG **)(unaff_EBP + 8);
      pvarg = pvarg + 1) {
    VariantClear(pvarg);
  }
                    /* WARNING: Subroutine does not return */
  FUN_68132060((int *)0x0,(byte *)0x0);
}


