// Source: CLCiffConversion_Data.dll @ 45039876; Unwind@45039876

void Unwind_45039876(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_4500574c((undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10));
    return;
  }
  return;
}


