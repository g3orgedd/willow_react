// Source: CiffMgr.dll @ 68105953; Catch_All@68105953

void Catch_All_68105953(void)

{
  VARIANTARG *_Memory;
  int iVar1;
  int iVar2;
  int unaff_EBP;
  VARIANTARG *pVVar3;
  
  _Memory = *(VARIANTARG **)(unaff_EBP + -0x14);
  iVar2 = *(int *)(unaff_EBP + -0x18);
  if ((1 < *(int *)(unaff_EBP + -0x1c)) && (pVVar3 = _Memory, _Memory != _Memory + iVar2)) {
    do {
      VariantClear(pVVar3);
      pVVar3 = pVVar3 + 1;
    } while (pVVar3 != _Memory + iVar2);
    iVar2 = *(int *)(unaff_EBP + -0x18);
  }
  if (0 < *(int *)(unaff_EBP + -0x1c)) {
    iVar1 = *(int *)(unaff_EBP + 0x10);
    for (pVVar3 = _Memory + iVar2; pVVar3 != _Memory + iVar2 + iVar1; pVVar3 = pVVar3 + 1) {
      VariantClear(pVVar3);
    }
  }
  FID_conflict__free(_Memory);
                    /* WARNING: Subroutine does not return */
  FUN_68132060((int *)0x0,(byte *)0x0);
}


