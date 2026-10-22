// Source: CLCiffConversion_Layout.dll @ 45444fa8; Unwind@45444fa8

void Unwind_45444fa8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
    FUN_45401c67(*(undefined4 **)(unaff_EBP + 8));
    return;
  }
  return;
}


