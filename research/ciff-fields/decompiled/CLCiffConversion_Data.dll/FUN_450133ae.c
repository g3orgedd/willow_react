// Source: CLCiffConversion_Data.dll @ 450133ae; Catch@450133ae

undefined * Catch_450133ae(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [16];
  undefined4 uStack_1c;
  undefined1 auStack_14 [16];
  undefined *puStack_4;
  
  puStack_4 = &DAT_4503f918;
  *(undefined1 **)(unaff_EBP + -0x280) = auStack_14;
  uStack_1c = 0x450133c9;
  FUN_450021f2(auStack_14,*(int *)(unaff_EBP + -0x2ac));
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  uVar1 = FUN_4500eea9((IID *)&DAT_4503f938,(wchar_t *)0x0);
  *(undefined4 *)(unaff_EBP + -0x280) = uVar1;
  return &DAT_450133fa;
}


