// Source: CLCiffConversion_Layout.dll @ 4541e46c; FUN_4541e46c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4541e46c(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  VARIANTARG local_50;
  int local_40;
  int local_3c;
  undefined4 *local_38;
  int *local_34;
  int *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x4541e478;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFResolveFieldWidth::InitialiseFontList");
  local_8 = 0;
  local_30 = (int *)0x0;
  FUN_45429f70((uint *)&local_50,0,0x10);
  VariantInit(&local_50);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  local_40 = (**(code **)(*piVar1 + 0x474))(piVar1,&local_50);
  if (-1 < local_40) {
    (*(code *)**(undefined4 **)local_50.n1._8_4_)(local_50.n1._8_4_,&DAT_45447790,&local_30);
    local_3c = 0;
    (**(code **)(*local_30 + 0x24))(local_30,&local_3c);
    piVar1 = param_1 + 1;
    FUN_454224ff(piVar1);
    iVar2 = 0;
    if (0 < local_3c) {
      do {
        local_34 = (int *)0x0;
        iVar2 = iVar2 + 1;
        local_8._0_1_ = 3;
        (**(code **)(*local_30 + 0x20))(local_30,iVar2,&local_50);
        (*(code *)**(undefined4 **)local_50.n1._8_4_)(local_50.n1._8_4_,&DAT_45447760,&local_34);
        local_38 = (undefined4 *)FUN_454298b4(4);
        local_8._0_1_ = 4;
        if (local_38 == (undefined4 *)0x0) {
          local_38 = (undefined4 *)0x0;
        }
        else {
          piVar3 = local_34;
          if (local_34 != (int *)0x0) {
            (**(code **)(*local_34 + 4))(local_34);
          }
          local_38 = FUN_45412a60(local_38,piVar3);
        }
        local_8._0_1_ = 3;
        FUN_4541222d(piVar1,(int *)*piVar1,&local_38);
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
      } while (iVar2 < local_3c);
    }
    FUN_4540303d(0x45449a50);
  }
  VariantClear(&local_50);
  local_8 = local_8 & 0xffffff00;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


