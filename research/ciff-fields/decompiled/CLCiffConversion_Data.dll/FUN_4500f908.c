// Source: CLCiffConversion_Data.dll @ 4500f908; FUN_4500f908

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Removing unreachable block (ram,0x4500f955) */

void FUN_4500f908(int *param_1,void *param_2)

{
  int iVar1;
  LPCWSTR bstrString;
  undefined4 local_194;
  void *local_190;
  int local_18c;
  BSTR local_188;
  LPCWSTR local_184;
  int *local_180;
  int *local_17c;
  int local_178;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_70 [32];
  _union_2683 local_50;
  char local_40 [56];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x194;
  local_190 = param_2;
  iVar1 = 0;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_70,"CCVScanpointItem::GetADOErrors");
  local_178 = 0;
  if (param_1 == (int *)0x0) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_70,true,0);
    local_8 = 0xffffffff;
    FUN_4500fc42();
    return;
  }
  local_184 = (LPCWSTR)0x0;
  local_180 = (int *)0x0;
  local_8._0_1_ = 4;
  local_178 = (**(code **)(*param_1 + 0x54))(param_1,&local_180);
  FUN_4500b385(local_178);
  local_18c = 0;
  if (local_180 != (int *)0x0) {
    local_178 = (**(code **)(*local_180 + 0x1c))(local_180,&local_18c);
    FUN_4500b385(local_178);
    bstrString = (LPCWSTR)0x0;
    while( true ) {
      if (local_18c <= iVar1) {
        FUN_4500af7f(local_190,bstrString);
        local_8 = CONCAT31(local_8._1_3_,3);
        if (local_180 != (int *)0x0) {
          (**(code **)(*local_180 + 8))(local_180);
        }
        SysFreeString(bstrString);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_70,true,0)
        ;
        local_8 = 0xffffffff;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
        FUN_4500fc42();
        return;
      }
      local_50.n2.vt = 3;
      local_17c = (int *)0x0;
      local_8._0_1_ = 6;
      local_50._8_4_ = iVar1;
      if (local_180 == (int *)0x0) break;
      local_17c = (int *)0x0;
      local_178 = (**(code **)(*local_180 + 0x28))
                            (local_180,local_50._0_4_,local_50.decVal.Hi32,iVar1,local_50._12_4_,
                             &local_17c);
      FUN_4500b385(local_178);
      local_188 = (BSTR)0x0;
      local_8._0_1_ = 7;
      if (local_17c == (int *)0x0) break;
      local_178 = (**(code **)(*local_17c + 0x1c))(local_17c,&local_194);
      FUN_4500b385(local_178);
      if (local_17c == (int *)0x0) break;
      local_178 = (**(code **)(*local_17c + 0x24))(local_17c,&local_188);
      FUN_4500b385(local_178);
      _sprintf_s(local_40,0x28,"(0x%X) ",local_194);
      FUN_4500b091(local_40);
      FUN_4500263d(&local_184,local_188);
      local_178 = FUN_4500b091("\n");
      SysFreeString(local_188);
      local_8._0_1_ = 5;
      if (local_17c != (int *)0x0) {
        (**(code **)(*local_17c + 8))(local_17c);
      }
      local_8._0_1_ = 4;
      VariantClear((VARIANTARG *)&local_50.n2);
      iVar1 = iVar1 + 1;
      bstrString = local_184;
    }
  }
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


