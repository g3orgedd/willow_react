// Source: CLCiffConversion_Layout.dll @ 4541f405; FUN_4541f405

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4541f405(void)

{
  bool bVar1;
  uint uVar2;
  UINT UVar3;
  BSTR **pppOVar4;
  int iVar5;
  undefined ***pppuVar6;
  OLECHAR *in_stack_0000001c;
  LPCLSID in_stack_00000020;
  undefined **local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined **local_94;
  LPCLSID local_90;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  LPCOLESTR local_80;
  BSTR local_7c;
  LPCLSID local_78;
  undefined1 local_74 [4];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_70 [24];
  BSTR *local_58 [4];
  undefined4 local_48;
  uint local_44;
  char local_40 [56];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_78 = in_stack_00000020;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_70,"CCiffConversion_Layout::ProcessCLSIDLine");
  local_8._0_1_ = 2;
  FUN_454028ee(&local_7c,in_stack_0000001c);
  local_8._0_1_ = 3;
  local_74[0] = 0x7b;
  uVar2 = FUN_45404a6f(&stack0x00000004,(uint *)local_74,0,1);
  if (uVar2 == 0xffffffff) {
    SysFreeString(local_7c);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_70,true,0);
LAB_4541f4d9:
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&stack0x00000004,
               true,0);
    FUN_4542a966();
    return;
  }
  local_44 = 0xf;
  local_48 = 0;
  local_58[0] = (BSTR *)((uint)local_58[0] & 0xffffff00);
  local_8._0_1_ = 4;
  FUN_454046be(local_58,(undefined4 *)&stack0x00000004,0,uVar2);
  pppOVar4 = local_58;
  if (0xf < local_44) {
    pppOVar4 = (BSTR **)local_58[0];
  }
  bVar1 = FUN_45402d1b(&local_7c,(BSTR)pppOVar4);
  if (!bVar1) {
    UVar3 = SysStringLen(local_7c);
    if (UVar3 != 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_58,true,0)
      ;
      SysFreeString(local_7c);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_70,true,0);
      goto LAB_4541f4d9;
    }
  }
  local_74[0] = 0x7d;
  local_84 = FUN_45404a6f(&stack0x00000004,(uint *)local_74,uVar2,1);
  FUN_454023e7(local_58,0);
  FUN_454046be(local_58,(undefined4 *)&stack0x00000004,uVar2,local_84);
  pppOVar4 = local_58;
  if (0xf < local_44) {
    pppOVar4 = (BSTR **)local_58[0];
  }
  iVar5 = FUN_45409564((int)pppOVar4,local_40);
  if (iVar5 == 0) {
    local_a4 = _com_error::vftable;
    pppuVar6 = &local_a4;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
  }
  else {
    FUN_454028b9(&local_80,local_40);
    local_8._0_1_ = 5;
    local_90 = (LPCLSID)CLSIDFromString(local_80,local_78);
    local_78 = local_90;
    if (-1 < (int)local_90) {
      SysFreeString(local_80);
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_58,true,0)
      ;
      SysFreeString(local_7c);
      FUN_4541f613();
      return;
    }
    pppuVar6 = &local_94;
    local_94 = _com_error::vftable;
    local_8c = 0;
    local_88 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)pppuVar6,&DAT_4545636c);
}


