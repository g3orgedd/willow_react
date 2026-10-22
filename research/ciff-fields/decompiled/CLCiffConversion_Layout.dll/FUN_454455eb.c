// Source: CLCiffConversion_Layout.dll @ 454455eb; Unwind@454455eb

void Unwind_454455eb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_45402c5d((int *)(unaff_EBP + -0x2c));
    return;
  }
  return;
}


