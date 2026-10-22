// Source: CLCiffConversion_Layout.dll @ 45417ff4; FUN_45417ff4

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_45417ff4(int param_1)

{
  int *piVar1;
  undefined **local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x45418000;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::Convert");
  piVar1 = *(int **)(param_1 + 0x4c8);
  local_8 = 1;
  do {
    piVar1 = (int *)*piVar1;
    if (piVar1 == (int *)*(int *)(param_1 + 0x4c8)) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
      FUN_4542a966();
      return;
    }
    local_40 = (**(code **)(*(int *)piVar1[2] + 8))();
  } while (-1 < local_40);
  local_3c = 0;
  local_38 = 0;
  local_44 = _com_error::vftable;
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)&local_44,&DAT_4545636c);
}


