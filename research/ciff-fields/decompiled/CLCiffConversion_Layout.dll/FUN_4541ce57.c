// Source: CLCiffConversion_Layout.dll @ 4541ce57; FUN_4541ce57

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541ce57(void *this,int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  VARIANTARG local_68;
  VARIANTARG local_58;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  wchar_t *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0;
  local_48 = 0;
  local_30 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFAddTabFields::GetFontToUse");
  *param_1 = 0;
  local_8 = 1;
  local_48 = 1;
  FUN_45429f70((uint *)&local_68,0,0x10);
  VariantInit(&local_68);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 0x38) + 0x474))(*(int **)((int)this + 0x38),&local_68);
  CComQIPtr<>(&local_38,(undefined4 *)local_68.n1._8_4_);
  local_8 = CONCAT31(local_8._1_3_,3);
  (**(code **)(*local_38 + 0x24))(local_38,&local_3c);
  if ((0 < local_3c) && (iVar2 = 0, 0 < local_3c)) {
    do {
      FUN_45429f70((uint *)&local_58,0,0x10);
      VariantInit(&local_58);
      iVar2 = iVar2 + 1;
      local_8._0_1_ = 4;
      (**(code **)(*local_38 + 0x20))(local_38,iVar2,&local_58);
      CComQIPtr<>(&local_34,(undefined4 *)local_58.n1._8_4_);
      local_8 = CONCAT31(local_8._1_3_,5);
      (**(code **)(*local_34 + 0x3c))(local_34,&local_44);
      piVar3 = *(int **)(local_30 + 0x36);
      uVar4 = local_44;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      bVar1 = FUN_4541c517(piVar3,uVar4);
      if (bVar1) {
        FUN_4541a358(&local_34,param_1);
        local_30 = (wchar_t *)0x0;
        local_8._0_1_ = 6;
        (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_30);
        FUN_45402ac2(&local_40,local_30);
        local_8._0_1_ = 7;
        FUN_4540303d(0x4544a098);
        FUN_45402c5d(&local_40);
        SysFreeString(local_30);
        local_8 = CONCAT31(local_8._1_3_,4);
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
        VariantClear(&local_58);
        break;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 8))(local_34);
      }
      VariantClear(&local_58);
    } while (iVar2 < local_3c);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))(local_38);
  }
  VariantClear(&local_68);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


