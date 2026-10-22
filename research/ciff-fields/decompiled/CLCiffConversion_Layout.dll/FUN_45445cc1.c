// Source: CLCiffConversion_Layout.dll @ 45445cc1; Unwind@45445cc1

void Unwind_45445cc1(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x38) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x38) & 0xfffffffe;
    FUN_45402c5d((int *)(unaff_EBP + -0x34));
    return;
  }
  return;
}


