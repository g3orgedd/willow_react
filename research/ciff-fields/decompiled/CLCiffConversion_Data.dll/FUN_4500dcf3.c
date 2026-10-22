// Source: CLCiffConversion_Data.dll @ 4500dcf3; Catch@4500dcf3

undefined * Catch_4500dcf3(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBP;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [16];
  undefined4 uStack_1c;
  undefined1 auStack_14 [12];
  undefined4 uStack_8;
  
  iVar1 = *(int *)(unaff_EBP + -0x40);
  uStack_8 = 0x4500dd01;
  FUN_45018d66((void *)(iVar1 + -8),'\0');
  FUN_4500b59c(iVar1 + -8);
  *(undefined1 **)(unaff_EBP + -0x40) = auStack_14;
  uStack_1c = 0x4500dd1e;
  FUN_450021f2(auStack_14,*(int *)(unaff_EBP + -0x5c));
  *(undefined1 *)(unaff_EBP + -4) = 8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             (unaff_EBP + -0x2c));
  *(undefined1 *)(unaff_EBP + -4) = 7;
  uVar2 = FUN_4500eea9((IID *)&DAT_4503f938,(wchar_t *)0x0);
  *(undefined4 *)(unaff_EBP + -0x40) = uVar2;
  return &DAT_4500dd4b;
}


