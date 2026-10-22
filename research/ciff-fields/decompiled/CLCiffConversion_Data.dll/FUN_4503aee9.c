// Source: CLCiffConversion_Data.dll @ 4503aee9; Unwind@4503aee9

void Unwind_4503aee9(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x24) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffe;
    FUN_45002256((int *)(unaff_EBP + -0x34));
    return;
  }
  return;
}


