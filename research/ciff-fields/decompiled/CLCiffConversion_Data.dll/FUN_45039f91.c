// Source: CLCiffConversion_Data.dll @ 45039f91; Unwind@45039f91

void Unwind_45039f91(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_4501d03e(*(void **)(unaff_EBP + 8));
    return;
  }
  return;
}


