// Source: CLCiffConversion_Data.dll @ 45006a05; FUN_45006a05

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_45006a05(int *param_1)

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
  local_8 = 0x45006a11;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFConvertBase::Convert");
  local_8 = 0;
  FUN_45005aac(0x4503db14);
  local_30 = 0;
  local_34 = (int *)FUN_45013f7b((int *)0x0,(int *)0x0);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4500753e(param_1,param_1 + 0xd,&local_34);
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
        FUN_4500274d(0x4503db18);
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
  FUN_45004f24((int *)&local_34);
  FUN_4501423d((int *)&local_34);
  FID_conflict__free(local_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


