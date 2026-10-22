// Source: CLCiffConversion_Layout.dll @ 4541b53a; FUN_4541b53a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl
FUN_4541b53a(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,char *param_2,
            char *param_3)

{
  uint uVar1;
  size_t sVar2;
  char ***pppcVar3;
  char **ppcVar4;
  uint in_stack_00000020;
  char *in_stack_00000024;
  char **local_2c [4];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (char **)((uint)local_2c[0] & 0xffffff00);
  local_8 = 1;
  if (param_2 != (char *)0x0) {
    uVar1 = std::char_traits<char>::length(param_2);
    FUN_45404764(local_2c,param_2,uVar1);
    sVar2 = _strlen(", ");
    FUN_45404764(local_2c,", ",sVar2);
  }
  sVar2 = _strlen("method ");
  FUN_45404764(local_2c,"method ",sVar2);
  ppcVar4 = &param_3;
  if (0xf < in_stack_00000020) {
    ppcVar4 = (char **)param_3;
  }
  uVar1 = std::char_traits<char>::length((char *)ppcVar4);
  FUN_45404764(local_2c,(char *)ppcVar4,uVar1);
  sVar2 = _strlen(",  ");
  FUN_45404764(local_2c,",  ",sVar2);
  uVar1 = std::char_traits<char>::length(in_stack_00000024);
  FUN_45404764(local_2c,in_stack_00000024,uVar1);
  pppcVar3 = local_2c;
  if (0xf < local_18) {
    pppcVar3 = (char ***)local_2c[0];
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(param_1,(char *)pppcVar3);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_2c,true,0);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&param_3,true,0);
  FUN_4542a957();
  return;
}


