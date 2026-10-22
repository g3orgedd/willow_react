// Source: CLCiffConversion_Data.dll @ 45010a0a; Catch@45010a0a

undefined * Catch_45010a0a(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [16];
  undefined4 uStack_1c;
  undefined1 auStack_14 [16];
  undefined *puStack_4;
  
  puStack_4 = &DAT_4503f918;
  *(undefined1 **)(unaff_EBP + -0x30) = auStack_14;
  uStack_1c = 0x45010a1f;
  FUN_450021f2(auStack_14,*(int *)(unaff_EBP + -0x50));
  *(undefined1 *)(unaff_EBP + -4) = 6;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar1 = FUN_4500eea9((IID *)&DAT_4503f938,(wchar_t *)0x0);
  *(undefined4 *)(unaff_EBP + -0x30) = uVar1;
  return &DAT_45010a4d;
}


