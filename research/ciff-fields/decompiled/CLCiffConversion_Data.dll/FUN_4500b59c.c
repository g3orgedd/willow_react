// Source: CLCiffConversion_Data.dll @ 4500b59c; FUN_4500b59c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4500b59c(int param_1)

{
  int *piVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4500b5a8;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffConversion_Layout::ClearLists");
  local_8 = 0;
  piVar1 = (int *)**(int **)(param_1 + 0x4e8);
  if (piVar1 != *(int **)(param_1 + 0x4e8)) {
    do {
      if ((undefined4 *)piVar1[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar1[2])(1);
      }
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x4e8));
  }
  FUN_4501423d((int *)(param_1 + 0x4e8));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


