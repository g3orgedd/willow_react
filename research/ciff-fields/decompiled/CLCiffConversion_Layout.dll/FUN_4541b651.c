// Source: CLCiffConversion_Layout.dll @ 4541b651; FUN_4541b651

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_4541b651(IID *param_1,char *param_2)

{
  char ****ppppcVar1;
  undefined4 in_stack_00000028;
  GUID *in_stack_00000034;
  char *in_stack_ffffff8c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_44 [24];
  char ***local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 1;
  FUN_45404c78(&stack0xffffff98,(int)&stack0x00000024);
  FUN_4541b61f(local_44);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&stack0xffffff8c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0x0000000c);
  FUN_4541b53a((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_2c,param_2,
               in_stack_ffffff8c);
  local_8 = CONCAT31(local_8._1_3_,4);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_44,true,0);
  ppppcVar1 = local_2c;
  if (0xf < local_18) {
    ppppcVar1 = (char ****)local_2c[0];
  }
  FUN_45414a58(param_1,(char *)ppppcVar1,0,(char *)0x0,in_stack_00000034,in_stack_00000028);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_2c,true,0);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&stack0x0000000c,
             true,0);
  _com_error::~_com_error((_com_error *)&stack0x00000024);
  FUN_4542a957();
  return;
}


