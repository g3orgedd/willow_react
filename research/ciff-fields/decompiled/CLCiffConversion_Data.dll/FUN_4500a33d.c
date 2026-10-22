// Source: CLCiffConversion_Data.dll @ 4500a33d; std::_Iostream_error_category::message

/* Library Function - Single Match
    public: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::_Iostream_error_category::message(int)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall std::_Iostream_error_category::message(_Iostream_error_category *this,int param_1)

{
  int in_stack_00000008;
  
  if (in_stack_00000008 == 1) {
    basic_string<char,std::char_traits<char>,std::allocator<char>_>::
    basic_string<char,std::char_traits<char>,std::allocator<char>_>
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_1,
               "iostream stream error");
  }
  else {
    FUN_4500a310((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)param_1,
                 in_stack_00000008);
  }
  return param_1;
}


