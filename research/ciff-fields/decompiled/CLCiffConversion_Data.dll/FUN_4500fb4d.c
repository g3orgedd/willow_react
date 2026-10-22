// Source: CLCiffConversion_Data.dll @ 4500fb4d; Catch@4500fb4d

undefined * Catch_4500fb4d(void)

{
  wchar_t *pwVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_104 [59];
  undefined4 uStack_18;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  
  *(undefined1 *)(unaff_EBP + -4) = 9;
  uStack_18 = 0x4500fb62;
  FUN_450021f2(auStack_10,unaff_EBP + -0x1a0);
  uStack_18 = 0x4500fb6b;
  FUN_4500ee77((void *)(unaff_EBP + -0x54));
  *(undefined1 *)(unaff_EBP + -4) = 10;
  pwVar1 = (wchar_t *)(unaff_EBP + -0x54);
  if (7 < *(uint *)(unaff_EBP + -0x40)) {
    pwVar1 = *(wchar_t **)(unaff_EBP + -0x54);
  }
  *(int *)(unaff_EBP + -0x170) = unaff_EBP + -0x16c;
  ATL::CW2WEX<128>::Init((CW2WEX<128> *)(unaff_EBP + -0x170),pwVar1);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  puVar3 = (undefined4 *)(unaff_EBP + -0x170);
  puVar4 = auStack_104;
  for (iVar2 = 0x41; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_4500274d(0x4503e9e8);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  if (*(int *)(unaff_EBP + -0x170) != unaff_EBP + -0x16c) {
    FID_conflict__free(*(void **)(unaff_EBP + -0x170));
  }
  uStack_c = 0x4500fbea;
  FUN_4500274d(0x4503ea38);
  iVar2 = *(int *)(unaff_EBP + -0x174);
  if (-1 < iVar2) {
    iVar2 = -0x7fffbffb;
  }
  *(int *)(unaff_EBP + -0x174) = iVar2;
  uStack_c = 0x4500fc0e;
  FUN_450046d9((void *)(unaff_EBP + -0x54),'\x01',0);
  _com_error::~_com_error((_com_error *)(unaff_EBP + -0x1a0));
  return &DAT_4500fc1f;
}


