// Source: CLCiffConversion_Data.dll @ 45039593; Unwind@45039593

void Unwind_45039593(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_45002256(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}


