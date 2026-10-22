// Source: CLCiffConversion_Data.dll @ 4500f834; FUN_4500f834

void FUN_4500f834(void)

{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  uint unaff_EDI;
  
  *(uint *)(unaff_EBP + -4) = unaff_EDI;
  if (unaff_EBX < 0) {
    FUN_450137d5(unaff_ESI);
    FUN_4500274d(0x4503e7cc);
  }
  else if (unaff_EBX == 1) {
    FUN_450137d5(unaff_ESI);
    FUN_4500274d(0x4503e7f0);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(unaff_EBP + -0x2c),
             true,unaff_EDI);
  FUN_45022ec7();
  return;
}


