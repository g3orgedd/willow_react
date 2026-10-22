// Source: CLCiffConversion_Layout.dll @ 45417a42; FUN_45417a42

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45417a42(void *this,int param_1)

{
  int *piVar1;
  undefined **local_38;
  int *local_34;
  int local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x45417a4e;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFResolutionAdjust::Convert");
  local_8 = 0;
  (**(code **)(**(int **)(param_1 + 4) + 100))(*(int **)(param_1 + 4),&local_30);
  if (local_30 == 0) {
    FUN_4540303d(0x45449990);
    FUN_45412a39(&local_38);
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)**(undefined4 **)(param_1 + 4))
              (*(undefined4 **)(param_1 + 4),&DAT_454486ec,&local_34);
    piVar1 = *(int **)(*(int *)(*(int *)((int)this + -0x10) + 4) + 0x24 + (int)this);
    (**(code **)(*piVar1 + 0x54))(piVar1,&local_30);
    FUN_4541fb66(&local_38,*(float *)((int)this + -0xc),*(float *)((int)this + -8),local_30);
  }
  else if (local_30 == 1) {
    FUN_4540303d(0x454499a0);
    FUN_4541260c(&local_38);
    local_38 = CCIFFBarcodeField::vftable;
    local_8 = CONCAT31(local_8._1_3_,2);
    (**(code **)**(undefined4 **)(param_1 + 4))
              (*(undefined4 **)(param_1 + 4),&DAT_45449f90,&local_34);
    piVar1 = *(int **)(*(int *)(*(int *)((int)this + -0x10) + 4) + 0x24 + (int)this);
    (**(code **)(*piVar1 + 0x54))(piVar1,&local_30);
    FUN_4541f9f1(&local_38,*(float *)((int)this + -0xc),*(float *)((int)this + -8),local_30);
  }
  else {
    if (local_30 != 2) goto LAB_45417bed;
    FUN_4540303d(0x454499b4);
    FUN_45412630(&local_38);
    local_38 = CCIFFGFXField::vftable;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)**(undefined4 **)(param_1 + 4))
              (*(undefined4 **)(param_1 + 4),&DAT_4544a718,&local_34);
    piVar1 = *(int **)(*(int *)(*(int *)((int)this + -0x10) + 4) + 0x24 + (int)this);
    (**(code **)(*piVar1 + 0x54))(piVar1,&local_30);
    FUN_4541fa93(&local_38,*(float *)((int)this + -0xc),*(float *)((int)this + -8),local_30);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
LAB_45417bed:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


