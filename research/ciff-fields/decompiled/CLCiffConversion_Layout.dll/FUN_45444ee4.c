// Source: CLCiffConversion_Layout.dll @ 45444ee4; Unwind@45444ee4

void Unwind_45444ee4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x14) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) & 0xfffffffe;
    FUN_45404caa(*(int **)(unaff_EBP + 8));
    return;
  }
  return;
}


