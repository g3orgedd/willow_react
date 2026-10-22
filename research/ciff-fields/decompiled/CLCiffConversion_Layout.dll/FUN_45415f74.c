// Source: CLCiffConversion_Layout.dll @ 45415f74; Catch@45415f74

undefined * Catch_45415f74(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [16];
  undefined4 uStack_1c;
  undefined1 auStack_14 [16];
  undefined *puStack_4;
  
  puStack_4 = &DAT_4544a7c8;
  *(undefined1 **)(unaff_EBP + -0x130) = auStack_14;
  uStack_1c = 0x45415f8f;
  FUN_45404c78(auStack_14,*(int *)(unaff_EBP + -0x13c));
  *(undefined1 *)(unaff_EBP + -4) = 5;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -300));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uVar1 = FUN_4541b651((IID *)&DAT_4544a7f8,(char *)0x0);
  *(undefined4 *)(unaff_EBP + -0x130) = uVar1;
  return &DAT_45415fc3;
}


