// Source: CiffHelper.dll @ 4080cd7c; FUN_4080cd7c

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4080cd7c(int param_1)

{
  OLECHAR *pOVar1;
  int iVar2;
  BSTR local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x4080cd88;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffDataHelper::OpenConnection");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (*(int *)(param_1 + 100) == 0) {
    FUN_4080c146(param_1 + 0x28);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
    FUN_4080ce23();
    return;
  }
  pOVar1 = (OLECHAR *)(param_1 + 0x54);
  if (7 < *(uint *)(param_1 + 0x68)) {
    pOVar1 = *(OLECHAR **)pOVar1;
  }
  FUN_40802e40(&local_34,pOVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_4080c194((void *)(param_1 + 0x28),&local_34,0);
  FUN_4080c114(iVar2);
  SysFreeString(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4080ce23();
  return;
}


