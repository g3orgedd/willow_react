// Source: CLCiffConversion_Layout.dll @ 4544383a; Unwind@4544383a

void Unwind_4544383a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_45412de4((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10));
    return;
  }
  return;
}


