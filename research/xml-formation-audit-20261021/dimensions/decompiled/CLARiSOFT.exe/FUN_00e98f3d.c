// Source: CLARiSOFT.exe @ 00e98f3d; FUN_00e98f3d

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_00e98f3d(void *param_1)

{
  int *piVar1;
  HRESULT HVar2;
  undefined4 *extraout_EAX;
  OLECHAR *pOVar3;
  int *piVar4;
  int *extraout_EAX_00;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR pOVar5;
  BSTR extraout_ECX_01;
  _union_2683 local_c8;
  _union_2683 local_b8;
  _union_2683 local_a8;
  _union_2683 local_98;
  _union_2683 local_88;
  _union_2683 local_78;
  _union_2683 local_68;
  void *local_58;
  int *local_54;
  undefined4 local_50;
  int *local_4c;
  undefined4 local_48;
  BSTR local_44;
  BSTR local_40;
  BSTR local_3c;
  int local_38;
  BSTR local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xbc;
  local_8 = 0xe98f4c;
  local_50 = 0;
  local_48 = 0;
  local_58 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CSPrintPreview::Preview");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_00e97080(param_1,(OLECHAR *)0x1);
  FUN_00e03ab8(&local_3c,(int *)((int)param_1 + 0xa8));
  local_8._0_1_ = 2;
  FUN_00e13922(&local_34,"\\");
  local_8._0_1_ = 3;
  HVar2 = FUN_00e04193(&local_3c,local_34);
  if (HVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00e02099(HVar2);
  }
  local_8._0_1_ = 2;
  SysFreeString(local_34);
  pOVar5 = extraout_ECX;
  FUN_00e03ab8(&stack0xffffff20,(int *)((int)param_1 + 0x78));
  FUN_00e056b2(*(int *)((int)param_1 + 0x84),&local_34,pOVar5);
  local_8._0_1_ = 4;
  FUN_00e0ea57(&local_3c,extraout_EAX);
  SysFreeString(local_34);
  local_40 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(**(int **)((int)param_1 + 0x8c) + 0x38))();
  piVar1 = (int *)((int)param_1 + 0x88);
  if ((*piVar1 != 0) && (piVar4 = (int *)*piVar1, piVar4 != (int *)0x0)) {
    *piVar1 = 0;
    (**(code **)(*piVar4 + 8))();
  }
  (**(code **)(**(int **)((int)param_1 + 0x90) + 0x24))();
  CComQIPtr<>(&local_54,(undefined4 *)*piVar1);
  local_8._0_1_ = 6;
  (**(code **)(*local_54 + 0xb0))();
  pOVar3 = FUN_00eb81ca();
  FUN_00e03b21(&local_44,pOVar3);
  local_b8._8_4_ = *piVar1;
  local_8._0_1_ = 7;
  local_b8.n2.vt = 9;
  pOVar5 = (BSTR)0x0;
  if ((int *)local_b8._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_b8._8_4_ + 4))();
    pOVar5 = extraout_ECX_00;
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  piVar1 = (int *)((int)param_1 + 0x78);
  FUN_00e03ab8(&stack0xffffff08,piVar1);
  piVar4 = FUN_00e0572b(*(void **)((int)param_1 + 0x84),(int *)&local_34,pOVar5);
  local_98._8_4_ = *piVar4;
  local_98.n2.vt = 9;
  if ((int *)local_98._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_98._8_4_ + 4))();
  }
  local_8._0_1_ = 9;
  if (local_34 != (BSTR)0x0) {
    (**(code **)(*(int *)local_34 + 8))();
  }
  local_78._0_4_ = (uint)local_78.n2.wReserved1 << 0x10;
  FUN_00e03e6b(&local_78,(int *)((int)param_1 + 0x108));
  local_8._0_1_ = 10;
  local_68._0_4_ = (uint)local_68.n2.wReserved1 << 0x10;
  FUN_00e03e6b(&local_68,piVar1);
  local_8._0_1_ = 0xb;
  local_c8._0_4_ = (uint)local_c8.n2.wReserved1 << 0x10;
  FUN_00e03e6b(&local_c8,(int *)((int)param_1 + 0x7c));
  local_8._0_1_ = 0xc;
  local_88._0_4_ = (uint)local_88.n2.wReserved1 << 0x10;
  FUN_00e03e6b(&local_88,(int *)&local_44);
  local_8._0_1_ = 0xd;
  pOVar5 = extraout_ECX_01;
  FUN_00e03ab8(&stack0xffffff08,piVar1);
  FUN_00e05797(*(int *)((int)param_1 + 0x84),&local_34,pOVar5);
  local_8._0_1_ = 0xe;
  local_a8._0_4_ = (uint)local_a8.n2.wReserved1 << 0x10;
  FUN_00e03e6b(&local_a8,extraout_EAX_00);
  SysFreeString(local_34);
  CComQIPtr<>(&local_4c,*(undefined4 **)((int)param_1 + 0x98));
  local_8 = CONCAT31(local_8._1_3_,0x11);
  if (local_4c != (int *)0x0) {
    local_50 = (**(code **)(*local_4c + 0x6c))
                         (local_4c,local_b8._0_4_,local_b8.decVal.Hi32,local_b8._8_4_,
                          local_b8._12_4_,local_98._0_4_,local_98.decVal.Hi32,local_98._8_4_,
                          local_98._12_4_,local_78._0_4_,local_78.decVal.Hi32,local_78._8_4_,
                          local_78._12_4_,local_68._0_4_,local_68.decVal.Hi32,local_68._8_4_,
                          local_68._12_4_,local_c8._0_4_,local_c8.decVal.Hi32,local_c8._8_4_,
                          local_c8._12_4_,local_88._0_4_,local_88.decVal.Hi32,local_88._8_4_,
                          local_88._12_4_,local_a8._0_4_,local_a8.decVal.Hi32,local_a8._8_4_);
    local_48 = local_50;
  }
  if (*(int *)((int)param_1 + 0x9c) != 0) {
    (**(code **)(**(int **)((int)param_1 + 0x9c) + 0x1c))(*(int **)((int)param_1 + 0x9c));
    EnableWindow(*(HWND *)((int)param_1 + 0xec),(uint)(0 < local_38));
  }
  SetTimer(*(HWND *)((int)param_1 + 4),0,500,(TIMERPROC)0x0);
  local_8._0_1_ = 0x10;
  if (local_4c != (int *)0x0) {
    (**(code **)(*local_4c + 8))();
  }
  VariantClear((VARIANTARG *)&local_a8.n2);
  VariantClear((VARIANTARG *)&local_88.n2);
  VariantClear((VARIANTARG *)&local_c8.n2);
  VariantClear((VARIANTARG *)&local_68.n2);
  VariantClear((VARIANTARG *)&local_78.n2);
  VariantClear((VARIANTARG *)&local_98.n2);
  VariantClear((VARIANTARG *)&local_b8.n2);
  SysFreeString(local_44);
  local_8 = CONCAT31(local_8._1_3_,5);
  if (local_54 != (int *)0x0) {
    (**(code **)(*local_54 + 8))();
  }
  SysFreeString(local_40);
  SysFreeString(local_3c);
  FUN_00e992cf();
  return;
}


