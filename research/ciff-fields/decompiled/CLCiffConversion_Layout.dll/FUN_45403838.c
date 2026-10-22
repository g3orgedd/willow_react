// Source: CLCiffConversion_Layout.dll @ 45403838; FUN_45403838

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45403838(int *param_1,void *param_2,BSTR param_3)

{
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  VARIANTARG local_64;
  VARIANTARG local_54;
  void *local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_44 = param_2;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCapabilitiesHelper::GetLocalePointerFromName");
  local_8._0_1_ = 1;
  if (*param_1 == 0) {
    FUN_4540303d(0x454478f4);
  }
  else {
    FUN_45429f70((uint *)&local_64,0,0x10);
    VariantInit(&local_64);
    local_8._0_1_ = 2;
    (**(code **)(*(int *)*param_1 + 0x484))((int *)*param_1,&local_64);
    CComQIPtr<>(&local_3c,(undefined4 *)local_64.n1._8_4_);
    piVar1 = local_3c;
    local_8._0_1_ = 3;
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 4))(local_3c);
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (piVar1 == (int *)0x0) {
      FUN_4540303d(0x45447918);
    }
    else {
      local_34 = 0;
      (**(code **)(*piVar1 + 0x24))(piVar1,&local_34);
      FUN_4540303d(0x45447930);
      iVar3 = 0;
      if (0 < local_34) {
        do {
          FUN_4540303d(0x45447944);
          FUN_45429f70((uint *)&local_54,0,0x10);
          VariantInit(&local_54);
          local_40 = iVar3 + 1;
          local_8._0_1_ = 5;
          (**(code **)(*piVar1 + 0x20))(piVar1,local_40,&local_54);
          CComQIPtr<>(&local_38,(undefined4 *)local_54.n1._8_4_);
          local_30 = (BSTR)0x0;
          local_8._0_1_ = 7;
          (**(code **)(*local_38 + 0x1c))(local_38,&local_30);
          FUN_4540409b(&local_30);
          FUN_4540409b(&param_3);
          FUN_4540303d(0x45447964);
          HVar2 = VarBstrCmp(local_30,param_3,0x400,0);
          if (HVar2 == 1) {
            FUN_4540303d(0x454479a0);
            FUN_45404ce5(local_44,(int *)&local_38);
            SysFreeString(local_30);
            local_8 = CONCAT31(local_8._1_3_,5);
            if (local_38 != (int *)0x0) {
              (**(code **)(*local_38 + 8))(local_38);
            }
            VariantClear(&local_54);
            break;
          }
          SysFreeString(local_30);
          local_8._0_1_ = 5;
          if (local_38 != (int *)0x0) {
            (**(code **)(*local_38 + 8))(local_38);
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          VariantClear(&local_54);
          iVar3 = local_40;
        } while (local_40 < local_34);
      }
    }
    local_8._0_1_ = 3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    local_8._0_1_ = 2;
    if (local_3c != (int *)0x0) {
      (**(code **)(*local_3c + 8))(local_3c);
    }
    VariantClear(&local_64);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  SysFreeString(param_3);
  FUN_4542a957();
  return;
}


