// Source: CLCiffConversion_Layout.dll @ 454220a4; Catch_All@454220a4

void Catch_All_454220a4(void)

{
  void *_Memory;
  int iVar1;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  iVar1 = *(int *)(unaff_EBP + -0x20);
  if (1 < *(int *)(unaff_EBP + -0x18)) {
    FUN_45421f2e(_Memory,(void *)((int)_Memory + iVar1 * 4));
  }
  if (0 < *(int *)(unaff_EBP + -0x18)) {
    FUN_45421f2e((void *)((int)_Memory + iVar1 * 4),
                 (void *)((int)_Memory + (*(int *)(unaff_EBP + 0x10) + iVar1) * 4));
  }
  FID_conflict__free(_Memory);
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)0x0,(byte *)0x0);
}


