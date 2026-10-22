// Source: CLCiffConversion_Layout.dll @ 4542084f; FUN_4542084f

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4542084f(void *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined3 uVar3;
  int *local_38;
  BSTR local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x4542085b;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::ResolveCapabilitiesFileReference");
  local_34 = (BSTR)0x0;
  local_8._1_3_ = 0;
  uVar3 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if ((*(short *)((int)param_1 + 0x178) == 0xd) && (*(int *)((int)param_1 + 0x180) != 0)) {
    piVar1 = (int *)((int)param_1 + 0x34);
    if (*piVar1 != 0) {
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        *piVar1 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        *piVar1 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    FUN_45413189(piVar1,*(int **)((int)param_1 + 0x180));
    uVar3 = local_8._1_3_;
  }
  else if (*(short *)((int)param_1 + 0xe8) == 8) {
    piVar1 = (int *)((int)param_1 + 0x34);
    if (*piVar1 != 0) {
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        *piVar1 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        *piVar1 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    local_38 = (int *)0x0;
    local_8._0_1_ = 2;
    local_34 = (BSTR)CoCreateInstance((IID *)&DAT_454473b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454494fc,
                                      &local_38);
    if ((-1 < (int)local_34) && (local_38 != (int *)0x0)) {
      FUN_454028ee(&local_34,*(OLECHAR **)((int)param_1 + 0xf0));
      local_8._0_1_ = 3;
      FUN_45415e5d(param_1,&local_34);
      (**(code **)(*local_38 + 0x20))(local_38,local_34,piVar1);
      SysFreeString(local_34);
    }
    local_8._0_1_ = 1;
    uVar3 = local_8._1_3_;
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))(local_38);
      uVar3 = local_8._1_3_;
    }
  }
  local_8._1_3_ = uVar3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4542a966();
  return;
}


