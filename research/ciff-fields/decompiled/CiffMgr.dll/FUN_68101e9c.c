// Source: CiffMgr.dll @ 68101e9c; std::_System_error_category::default_error_condition

/* Library Function - Single Match
    public: virtual class std::error_condition __thiscall
   std::_System_error_category::default_error_condition(int)const 
   
   Library: Visual Studio 2012 Release */

void __thiscall
std::_System_error_category::default_error_condition(_System_error_category *this,int param_1)

{
  char *pcVar1;
  int in_stack_00000008;
  
  pcVar1 = _Syserror_map(in_stack_00000008);
  *(int *)param_1 = in_stack_00000008;
  if (pcVar1 == (char *)0x0) {
    *(undefined ***)(param_1 + 4) = &PTR_vftable_6815f008;
  }
  else {
    *(undefined ***)(param_1 + 4) = &PTR_vftable_6815f000;
  }
  return;
}


