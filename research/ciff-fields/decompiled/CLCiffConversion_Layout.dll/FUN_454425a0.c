// Source: CLCiffConversion_Layout.dll @ 454425a0; Unwind@454425a0

void Unwind_454425a0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_45402c5d((int *)(unaff_EBP + -0x14));
    return;
  }
  return;
}


