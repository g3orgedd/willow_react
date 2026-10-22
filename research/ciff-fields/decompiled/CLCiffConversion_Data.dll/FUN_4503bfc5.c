// Source: CLCiffConversion_Data.dll @ 4503bfc5; Unwind@4503bfc5

void Unwind_4503bfc5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_45009cea(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}


