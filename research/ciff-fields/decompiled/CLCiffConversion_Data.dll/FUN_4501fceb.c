// Source: CLCiffConversion_Data.dll @ 4501fceb; FUN_4501fceb

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4501fceb(void *this,int *param_1)

{
  ushort uVar1;
  UINT UVar2;
  uint uVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4501fcf7;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"TimeDateParser::ConvertNumerals");
  local_8 = 0;
  FUN_45005aac(0x4503db14);
  if ((*(int *)((int)this + 0x150) != 0) && (*(int *)((int)this + 0x150) == 1)) {
    FUN_45005aac(0x4504167c);
    UVar2 = SysStringLen((BSTR)*param_1);
    uVar3 = 0;
    if (UVar2 != 0) {
      do {
        uVar1 = *(ushort *)(*param_1 + uVar3 * 2);
        if ((0x2f < uVar1) && (uVar1 < 0x3a)) {
          *(ushort *)(*param_1 + uVar3 * 2) = uVar1 + 0x630;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < UVar2);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


