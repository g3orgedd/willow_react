// Source: CLCiffConversion_Layout.dll @ 45444fe4; Unwind@45444fe4

void Unwind_45444fe4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x44) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x44) = *(uint *)(unaff_EBP + -0x44) & 0xfffffffe;
    FUN_45404caa(*(int **)(unaff_EBP + -0x68));
    return;
  }
  return;
}


