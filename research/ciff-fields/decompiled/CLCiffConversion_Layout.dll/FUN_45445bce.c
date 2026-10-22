// Source: CLCiffConversion_Layout.dll @ 45445bce; Unwind@45445bce

void Unwind_45445bce(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x40) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x40) = *(uint *)(unaff_EBP + -0x40) & 0xfffffffe;
    FUN_45401c67((undefined4 *)(unaff_EBP + -0x48));
    return;
  }
  return;
}


