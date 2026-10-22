// Source: CiffMgr.dll @ 68101c19; Catch_All@68101c19

undefined * Catch_All_68101c19(void)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(int *)(unaff_EBP + 8) = iVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pcVar2 = std::_Allocate<char>(iVar1 + 1,(char *)0x0);
  *(char **)(unaff_EBP + -0x14) = pcVar2;
  return &DAT_68101c3a;
}


