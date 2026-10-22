// Source: CLCiffConversion_Data.dll @ 45012308; FUN_45012308

void FUN_45012308(void)

{
  int *piVar1;
  uint unaff_EBX;
  int unaff_EBP;
  
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(unaff_EBP + -0x2c),
             true,unaff_EBX);
  piVar1 = *(int **)(unaff_EBP + 8);
  *(char *)(unaff_EBP + -4) = (char)unaff_EBX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  VariantClear((VARIANTARG *)(unaff_EBP + 0xc));
  FUN_45022ec7();
  return;
}


