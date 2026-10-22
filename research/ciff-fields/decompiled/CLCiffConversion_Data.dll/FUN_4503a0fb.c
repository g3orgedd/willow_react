// Source: CLCiffConversion_Data.dll @ 4503a0fb; Unwind@4503a0fb

void Unwind_4503a0fb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x30) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x30) = *(uint *)(unaff_EBP + -0x30) & 0xfffffffe;
    FUN_45002256(*(int **)(unaff_EBP + -0x34));
    return;
  }
  return;
}


