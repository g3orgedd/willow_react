// Source: CLCiffConversion_Data.dll @ 4500b8a1; Catch@4500b8a1

undefined * Catch_4500b8a1(void)

{
  void *this;
  LPCSTR pCVar1;
  int *piVar2;
  int iVar3;
  int unaff_EBP;
  int *piVar4;
  
  pCVar1 = (LPCSTR)(unaff_EBP + -0x2c);
  if (0xf < *(uint *)(unaff_EBP + -0x18)) {
    pCVar1 = *(LPCSTR *)(unaff_EBP + -0x2c);
  }
  piVar2 = FUN_45002050((void *)(unaff_EBP + -0x34),pCVar1);
  this = *(void **)(unaff_EBP + -0x48);
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  piVar4 = *(int **)((int)this + 0x20);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))(piVar4);
  }
  FUN_45010083(this,piVar4,piVar2);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_45002256((int *)(unaff_EBP + -0x34));
  FUN_4500274d(0x4503e5d8);
  iVar3 = *(int *)(unaff_EBP + -0x38);
  if (-1 < iVar3) {
    iVar3 = -0x7fffbffb;
  }
  *(int *)(unaff_EBP + -0x38) = iVar3;
  return &DAT_4500b917;
}


