// Source: CLCiffConversion_Layout.dll @ 45421114; FUN_45421114

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45421114(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x45421120;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFieldOrder::RoundToNearestLine");
  local_30 = 0;
  local_8 = 0;
  (**(code **)(*(int *)*param_1 + 0x34))((int *)*param_1,&local_30);
  if (local_30 == 0) {
    FUN_4540303d(0x45449f28);
  }
  else {
    local_34 = 0;
    (**(code **)(*(int *)*param_2 + 0x44))((int *)*param_2,&local_34);
    if (*(int *)((int)this + 0x6c) != 0) {
      local_3c = (int *)0x0;
      FUN_45404ce5(&local_3c,(int *)((int)this + 0x6c));
      piVar1 = local_3c;
      local_38 = 0;
      local_8._0_1_ = 1;
      (**(code **)(*local_3c + 0x2c))(local_3c,&local_38);
      local_8 = (uint)local_8._1_3_ << 8;
      (**(code **)(*piVar1 + 8))(piVar1);
      if (local_34 / local_38 != 0) {
        FUN_4540303d(0x45449f28);
        goto LAB_45421201;
      }
    }
    FUN_4540303d(0x45449f28);
  }
LAB_45421201:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


