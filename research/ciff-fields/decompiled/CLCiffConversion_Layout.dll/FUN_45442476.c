// Source: CLCiffConversion_Layout.dll @ 45442476; Unwind@45442476

void Unwind_45442476(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_45402c5d(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}


