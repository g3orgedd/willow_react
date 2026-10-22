// Source: CLCiffConversion_Data.dll @ 4500ec61; Catch@4500ec61

undefined * Catch_4500ec61(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [16];
  undefined4 uStack_1c;
  undefined1 auStack_14 [16];
  undefined *puStack_4;
  
  puStack_4 = &DAT_4503f918;
  *(undefined1 **)(unaff_EBP + -0x3c) = auStack_14;
  uStack_1c = 0x4500ec76;
  FUN_450021f2(auStack_14,*(int *)(unaff_EBP + -0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  uVar1 = FUN_4500eea9((IID *)&DAT_4503f938,(wchar_t *)0x0);
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar1;
  return &DAT_4500eca4;
}


