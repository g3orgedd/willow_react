// Source: CLCiffConversion_Layout.dll @ 45416a4a; FUN_45416a4a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45416a4a(undefined4 *param_1)

{
  undefined1 local_30 [4];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x45416a56;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFCull::Convert(CCIFFDataObject*)");
  local_8 = 0;
  FUN_4540303d(0x454491ec);
  FUN_4541d98c(param_1);
  (**(code **)(*(int *)*param_1 + 0x28))((int *)*param_1,local_30);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


