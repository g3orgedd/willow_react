// Source: CLCiffConversion_Layout.dll @ 454452de; Unwind@454452de

void Unwind_454452de(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x38) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x38) & 0xfffffffe;
    FUN_45402c5d((int *)(unaff_EBP + -0x30));
    return;
  }
  return;
}


