// Source: CLCiffConversion_Data.dll @ 4500f7ae; Catch@4500f7ae

undefined * Catch_4500f7ae(void)

{
  void *this;
  LPCSTR pCVar1;
  int *piVar2;
  int unaff_EBP;
  int *piVar3;
  
  pCVar1 = (LPCSTR)(unaff_EBP + -0x2c);
  if (0xf < *(uint *)(unaff_EBP + -0x18)) {
    pCVar1 = *(LPCSTR *)(unaff_EBP + -0x2c);
  }
  piVar2 = FUN_45002050((void *)(unaff_EBP + -0x40),pCVar1);
  this = *(void **)(unaff_EBP + -0x54);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  piVar3 = *(int **)((int)this + 0x20);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
  }
  FUN_45010083(this,piVar3,piVar2);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_45002256((int *)(unaff_EBP + -0x40));
  FUN_4500274d(0x4503e5d8);
  if (-1 < *(int *)(unaff_EBP + -0x34)) {
    FUN_4500274d(0x4503e7b0);
    *(undefined4 *)(unaff_EBP + -0x34) = 0x80004005;
  }
  return &DAT_4500f82c;
}


