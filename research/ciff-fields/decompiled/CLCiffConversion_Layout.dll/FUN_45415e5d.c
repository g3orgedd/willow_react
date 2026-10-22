// Source: CLCiffConversion_Layout.dll @ 45415e5d; FUN_45415e5d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45415e5d(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  size_t sVar2;
  int *piVar3;
  char local_13c [4];
  char *local_138;
  BSTR local_134;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_130 [24];
  char local_118 [272];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x130;
  local_8 = 0x45415e6c;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_130,"CCiffConversion_Layout::CheckForPath");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  puVar1 = FUN_45402ac2(&local_138,(wchar_t *)*param_1);
  FUN_4542e700((char *)*puVar1,local_13c,3,local_118,0x100,(char *)0x0,0,(char *)0x0,0);
  FUN_45402c5d((int *)&local_138);
  sVar2 = _strlen(local_13c);
  if (sVar2 == 0) {
    sVar2 = _strlen(local_118);
    if (sVar2 == 0) {
      FUN_45402a2f(&local_138,(int *)((int)this + 0x4e0));
      local_8._0_1_ = 2;
      puVar1 = FUN_45402ac2(&local_134,(wchar_t *)*param_1);
      local_8._0_1_ = 3;
      FUN_45405bb3(&local_138,*(rsize_t *)((int)*puVar1 + -8),(void *)*puVar1);
      local_8._0_1_ = 2;
      FUN_45402c5d((int *)&local_134);
      piVar3 = FUN_454028b9(&local_134,local_138);
      FUN_454066f3(param_1,piVar3);
      SysFreeString(local_134);
      FUN_45402c5d((int *)&local_138);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_130,true,0);
  FUN_45415fd8();
  return;
}


