// Source: CLCiffConversion_Data.dll @ 4500d770; FUN_4500d770

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4500d770(int param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x4500d77c;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCIFFDatabaseResolve::Convert");
  piVar1 = (int *)(param_1 + -8);
  local_8 = 1;
  FUN_45012966(piVar1);
  iVar2 = FUN_4501233a(piVar1);
  if (iVar2 < 0) {
    pcVar3 = "%s - ResolveDateOffsets (FAILED(hr)";
  }
  else {
    iVar2 = FUN_450127db(piVar1);
    if (iVar2 < 0) {
      pcVar3 = "%s - ResolvePrices (FAILED(hr)";
    }
    else {
      iVar2 = FUN_45006a05((int *)(param_1 + -8 + *(int *)(*piVar1 + 4)));
      if (-1 < iVar2) goto LAB_4500d80a;
      pcVar3 = "%s - CCIFFConvertBase::Convert() (FAILED(hr)";
    }
  }
  FUN_4500274d((int)pcVar3);
LAB_4500d80a:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4500d849();
  return;
}


