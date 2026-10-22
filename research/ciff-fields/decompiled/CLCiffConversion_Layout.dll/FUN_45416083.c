// Source: CLCiffConversion_Layout.dll @ 45416083; FUN_45416083

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_45416083(int param_1)

{
  int *piVar1;
  int *piVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4541608f;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffConversion_Layout::Convert");
  local_8 = 0;
  piVar1 = (int *)(param_1 + 0x4c8);
  piVar2 = *(int **)*piVar1;
  if (piVar2 != (int *)*piVar1) {
    do {
      if ((undefined4 *)piVar2[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[2])(1);
      }
      piVar2[2] = 0;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*piVar1);
  }
  FUN_454224ff(piVar1);
  *(undefined1 *)(param_1 + 0x4e4) = 0;
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_454160f3(*(int *)(param_1 + 0x3c));
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


