// Source: CLCiffConversion_Layout.dll @ 4541e269; FUN_4541e269

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4541e269(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  bool bVar1;
  void *pvVar2;
  void *this;
  uint uVar3;
  wchar_t *in_stack_00000020;
  wchar_t *in_stack_00000030;
  int *in_stack_00000040;
  void *local_48;
  int local_44;
  undefined4 *local_40;
  void *local_3c;
  int local_38;
  char local_31;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x84;
  local_8 = 0x4541e278;
  uVar3 = 0;
  local_40 = (undefined4 *)0x0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::InitialiseCaps");
  local_8 = 1;
  FUN_45407800((void *)(param_1 + 0x4d8),param_4);
  if (in_stack_00000040 != (int *)0x0) {
    (**(code **)(*in_stack_00000040 + 4))(in_stack_00000040);
  }
  local_8._0_1_ = 2;
  local_31 = '\0';
  FUN_45402ac2(&local_38,in_stack_00000020);
  pvVar2 = (void *)FUN_4541b8d6((void *)(param_1 + 0x4c8),&local_38);
  local_48 = pvVar2;
  FUN_45402c5d(&local_38);
  if (pvVar2 == (void *)0x0) {
    this = (void *)FUN_454298b4(0x18);
    local_8._0_1_ = 3;
    local_3c = this;
    if (this == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_45402ac2(&local_38,in_stack_00000020);
      local_8 = CONCAT31(local_8._1_3_,4);
      local_40 = (undefined4 *)0x1;
      pvVar2 = FUN_45412adb(this,&local_38,&local_44);
    }
    bVar1 = this != (void *)0x0;
    uVar3 = (uint)bVar1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    local_48 = pvVar2;
    if (bVar1) {
      uVar3 = 0;
      FUN_45402c5d(&local_38);
    }
    local_31 = '\x01';
  }
  local_3c = (void *)FUN_454298b4(0x24);
  local_8._0_1_ = 6;
  if (local_3c == (void *)0x0) {
    local_40 = (undefined4 *)0x0;
  }
  else {
    FUN_45402ac2(&local_38,in_stack_00000030);
    local_8 = CONCAT31(local_8._1_3_,7);
    uVar3 = uVar3 | 2;
    local_40 = (undefined4 *)uVar3;
    local_40 = FUN_45412b9f(local_3c,&local_38,&local_44);
  }
  local_8 = 2;
  if ((uVar3 & 2) != 0) {
    FUN_45402c5d(&local_38);
  }
  FUN_45413356((int)pvVar2);
  if ((local_31 != '\0') && (pvVar2 != (void *)0x0)) {
    FUN_4542273a((void *)(param_1 + 0x4c8),&local_48);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (in_stack_00000040 != (int *)0x0) {
    (**(code **)(*in_stack_00000040 + 8))(in_stack_00000040);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4541e464();
  return;
}


