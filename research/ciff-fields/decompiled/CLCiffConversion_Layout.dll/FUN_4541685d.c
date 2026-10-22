// Source: CLCiffConversion_Layout.dll @ 4541685d; FUN_4541685d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4541685d(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *local_38;
  int *local_34;
  undefined4 local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x45416869;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFConvertBase::Convert");
  local_8 = 0;
  FUN_4540303d(0x454491ec);
  local_30 = 0;
  local_34 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45406e39(param_1,param_1 + 0xd,&local_34);
  piVar2 = (int *)*local_34;
  if (piVar2 != local_34) {
    do {
      local_38 = (int *)piVar2[2];
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 4))(local_38);
      }
      local_8._0_1_ = 2;
      iVar1 = (**(code **)(*param_1 + 4))(&local_38);
      if (iVar1 < 0) {
        FUN_4540500e(0x4544975c);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_38 != (int *)0x0) {
          (**(code **)(*local_38 + 8))(local_38);
        }
        break;
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != local_34);
  }
  FUN_454065bf((int *)&local_34);
  FUN_454224ff((int *)&local_34);
  FID_conflict__free(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


