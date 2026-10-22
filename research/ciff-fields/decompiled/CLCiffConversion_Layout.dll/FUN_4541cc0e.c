// Source: CLCiffConversion_Layout.dll @ 4541cc0e; FUN_4541cc0e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_4541cc0e(int *param_1,int *param_2)

{
  int local_40 [4];
  wchar_t *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFAddTabFields::GetFieldRectangle");
  local_8._0_1_ = 1;
  (**(code **)(*param_2 + 0x2c))(param_2,param_1);
  (**(code **)(*param_2 + 0x34))(param_2,param_1 + 1);
  local_40[1] = 0;
  (**(code **)(*param_2 + 0x88))(param_2,local_40 + 1);
  local_40[2] = 0;
  (**(code **)(*param_2 + 0x78))(param_2,local_40 + 2);
  param_1[2] = *param_1 + local_40[2];
  local_40[3] = 0;
  (**(code **)(*param_2 + 0x80))(param_2,local_40 + 3);
  param_1[3] = param_1[1] + local_40[3];
  local_30 = (wchar_t *)0x0;
  local_8._0_1_ = 2;
  (**(code **)(*param_2 + 0x1c))(param_2,&local_30);
  FUN_45402ac2(local_40,local_30);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_4540303d(0x4544a0d8);
  FUN_45402c5d(local_40);
  SysFreeString(local_30);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  FUN_4542a957();
  return;
}


