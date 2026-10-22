// Source: CLCiffConversion_Data.dll @ 4503a4fb; Unwind@4503a4fb

void Unwind_4503a4fb(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x224) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x224) = *(uint *)(unaff_EBP + -0x224) & 0xfffffffe;
    FUN_45002256(*(int **)(unaff_EBP + -0x228));
    return;
  }
  return;
}


