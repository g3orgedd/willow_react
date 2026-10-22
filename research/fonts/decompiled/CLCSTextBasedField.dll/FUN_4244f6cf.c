// Source: CLCSTextBasedField.dll @ 4244f6cf; FUN_4244f6cf

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4244f6cf(void *param_1)

{
  undefined1 uVar1;
  LRESULT LVar2;
  int *piVar3;
  undefined4 *puVar4;
  BSTR extraout_ECX;
  BSTR pOVar5;
  undefined4 local_80 [18];
  int *local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  local_8 = 0x4244f6db;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CTextBasedFieldProp::OnUseZipherBitmapFonts");
  local_8 = 0;
  LVar2 = SendMessageW(*(HWND *)((int)param_1 + 0x1b8),0xf0,0,0);
  CComQIPtr<>(&local_38,*(undefined4 **)((int)param_1 + 0x160));
  local_8._0_1_ = 1;
  FUN_424037d2(&local_30,L"");
  local_8._0_1_ = 2;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (local_38 == (int *)0x0) {
    local_8._0_1_ = uVar1;
    FUN_42403ff7(0x424994ec);
  }
  else {
    if (LVar2 == 1) {
      FUN_42467b8d(local_80);
      local_8._0_1_ = 3;
      piVar3 = (int *)FUN_42468007(local_80,&local_34);
      FUN_4241115f(&local_30,piVar3);
      SysFreeString(local_34);
      pOVar5 = extraout_ECX;
      FUN_42403768(&stack0xffffff6c,(int *)&local_30);
      FUN_4245ae52((void *)((int)param_1 + 0x6c),pOVar5);
      (**(code **)(*local_38 + 0xac))(local_38);
      FUN_4245012b(param_1,2);
      local_8._0_1_ = 2;
      FUN_42467c23(local_80);
      pOVar5 = local_30;
    }
    else {
      local_8._0_1_ = uVar1;
      FUN_42403b70(&local_30,L"Arial");
      puVar4 = FUN_4240391a(&local_34,local_30);
      local_8._0_1_ = 4;
      FUN_4245ac12((void *)((int)param_1 + 0x6c),puVar4);
      local_8._0_1_ = 2;
      FUN_42403ad1((int *)&local_34);
      (**(code **)(*local_38 + 0xac))(local_38);
      FUN_4245012b(param_1,1);
      pOVar5 = local_30;
    }
    InvalidateRect(*(HWND *)((int)param_1 + 0x70),(RECT *)0x0,1);
    local_30 = pOVar5;
  }
  SysFreeString(local_30);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4246ecf6();
  return;
}


