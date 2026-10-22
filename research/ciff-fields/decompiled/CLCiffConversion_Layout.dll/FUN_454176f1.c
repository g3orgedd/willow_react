// Source: CLCiffConversion_Layout.dll @ 454176f1; thunk_FUN_4541685d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall thunk_FUN_4541685d(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_2c [36];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  uStack_8 = 0x45416869;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (abStack_2c,"CCIFFConvertBase::Convert");
  uStack_8 = 0;
  FUN_4540303d(0x454491ec);
  uStack_30 = 0;
  piStack_34 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
  uStack_8 = CONCAT31(uStack_8._1_3_,1);
  FUN_45406e39(param_1,param_1 + 0xd,&piStack_34);
  piVar2 = (int *)*piStack_34;
  if (piVar2 != piStack_34) {
    do {
      piStack_38 = (int *)piVar2[2];
      if (piStack_38 != (int *)0x0) {
        (**(code **)(*piStack_38 + 4))(piStack_38);
      }
      uStack_8._0_1_ = 2;
      iVar1 = (**(code **)(*param_1 + 4))(&piStack_38);
      if (iVar1 < 0) {
        FUN_4540500e(0x4544975c);
        uStack_8 = CONCAT31(uStack_8._1_3_,1);
        if (piStack_38 != (int *)0x0) {
          (**(code **)(*piStack_38 + 8))(piStack_38);
        }
        break;
      }
      uStack_8 = CONCAT31(uStack_8._1_3_,1);
      if (piStack_38 != (int *)0x0) {
        (**(code **)(*piStack_38 + 8))(piStack_38);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != piStack_34);
  }
  FUN_454065bf((int *)&piStack_34);
  FUN_454224ff((int *)&piStack_34);
  FID_conflict__free(piStack_34);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(abStack_2c,true,0);
  FUN_4542a957();
  return;
}


