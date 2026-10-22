// Source: CLCiffConversion_Layout.dll @ 4541d072; FUN_4541d072

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541d072(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *this_00;
  int *piVar2;
  VARIANTARG local_4c;
  undefined4 *local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x4541d07e;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFFontConvert::GetFonts");
  local_8 = 0;
  local_30 = (int *)0x0;
  FUN_45429f70((uint *)&local_4c,0,0x10);
  VariantInit(&local_4c);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = *(int **)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this);
  iVar1 = (**(code **)(*piVar2 + 0x474))(piVar2,&local_4c);
  FUN_4541534f(iVar1);
  (*(code *)**(undefined4 **)local_4c.n1._8_4_)(local_4c.n1._8_4_,&DAT_45447790,&local_30);
  local_38 = 0;
  (**(code **)(*local_30 + 0x24))(local_30,&local_38);
  iVar1 = 0;
  if (0 < local_38) {
    do {
      local_34 = (int *)0x0;
      iVar1 = iVar1 + 1;
      local_8._0_1_ = 3;
      (**(code **)(*local_30 + 0x20))(local_30,iVar1,&local_4c);
      (*(code *)**(undefined4 **)local_4c.n1._8_4_)(local_4c.n1._8_4_,&DAT_45447760,&local_34);
      this_00 = (undefined4 *)FUN_454298b4(4);
      local_8._0_1_ = 4;
      if (this_00 == (undefined4 *)0x0) {
        local_3c = (undefined4 *)0x0;
      }
      else {
        piVar2 = local_34;
        local_3c = this_00;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 4))(local_34);
        }
        local_3c = FUN_45412a60(this_00,piVar2);
      }
      local_8._0_1_ = 3;
      FUN_4541222d(param_1,(int *)*param_1,&local_3c);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 8))(local_34);
      }
    } while (iVar1 < local_38);
  }
  FUN_4540303d(0x45449a50);
  VariantClear(&local_4c);
  local_8 = local_8 & 0xffffff00;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


