// Source: CiffMgr.dll @ 681056fa; Catch_All@681056fa

undefined * Catch_All_681056fa(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  iVar1 = _Allocate<>(iVar1 + 1);
  *(int *)(unaff_EBP + -0x14) = iVar1;
  return &DAT_6810571b;
}


