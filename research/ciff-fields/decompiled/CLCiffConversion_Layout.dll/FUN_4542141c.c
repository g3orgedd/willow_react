// Source: CLCiffConversion_Layout.dll @ 4542141c; Catch@4542141c

undefined * Catch_4542141c(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [16];
  undefined4 uStack_1c;
  undefined1 auStack_14 [16];
  undefined *puStack_4;
  
  puStack_4 = &DAT_4544a7c8;
  *(undefined1 **)(unaff_EBP + -0x170) = auStack_14;
  uStack_1c = 0x45421437;
  FUN_45404c78(auStack_14,*(int *)(unaff_EBP + -0x194));
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  uVar1 = FUN_4541b651((IID *)&DAT_4544a7f8,(char *)0x0);
  *(undefined4 *)(unaff_EBP + -0x170) = uVar1;
  return &DAT_45421468;
}


