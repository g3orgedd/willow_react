// Source: CLCiffConversion_Layout.dll @ 4544537a; Unwind@4544537a

void Unwind_4544537a(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x3c) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) & 0xfffffffe;
    FUN_45402c5d((int *)(unaff_EBP + -0x34));
    return;
  }
  return;
}


