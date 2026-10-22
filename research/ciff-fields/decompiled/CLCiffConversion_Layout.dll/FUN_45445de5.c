// Source: CLCiffConversion_Layout.dll @ 45445de5; Unwind@45445de5

void Unwind_45445de5(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x20) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x20) = *(uint *)(unaff_EBP + -0x20) & 0xfffffffe;
    FUN_45402c30(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}


