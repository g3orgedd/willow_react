// Source: CLCiffConversion_Data.dll @ 4500eea9; FUN_4500eea9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_4500eea9(IID *param_1,wchar_t *param_2)

{
  WCHAR ****ppppWVar1;
  undefined4 in_stack_00000028;
  GUID *in_stack_00000034;
  char *in_stack_ffffff8c;
  undefined1 local_44 [24];
  WCHAR ***local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 1;
  FUN_450021f2(&stack0xffffff98,(int)&stack0x00000024);
  FUN_4500ee77(local_44);
  local_8 = CONCAT31(local_8._1_3_,2);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&stack0xffffff8c,
             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
             &stack0x0000000c);
  FUN_4500ed3a(local_2c,param_2,in_stack_ffffff8c);
  FUN_450046d9(local_44,'\x01',0);
  ppppWVar1 = local_2c;
  if (7 < local_18) {
    ppppWVar1 = (WCHAR ****)local_2c[0];
  }
  FUN_4500b128(param_1,(WCHAR *)ppppWVar1,0,(IErrorInfo *)0x0,in_stack_00000034,in_stack_00000028,
               (HINSTANCE)0x0);
  FUN_450046d9(local_2c,'\x01',0);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&stack0x0000000c,
             true,0);
  _com_error::~_com_error((_com_error *)&stack0x00000024);
  FUN_45022eb8();
  return;
}


