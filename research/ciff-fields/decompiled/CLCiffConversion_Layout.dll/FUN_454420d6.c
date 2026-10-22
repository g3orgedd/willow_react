// Source: CLCiffConversion_Layout.dll @ 454420d6; Unwind@454420d6

void Unwind_454420d6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_45402c30(*(int **)(unaff_EBP + -0x34));
    return;
  }
  return;
}


