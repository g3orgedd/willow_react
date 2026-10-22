// Source: CLCiffConversion_Layout.dll @ 45418ce0; FUN_45418ce0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45418ce0(void *this,BSTR param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  HRESULT HVar4;
  int iVar5;
  UINT UVar6;
  BSTR bstrString;
  BSTR pOVar7;
  _union_2683 local_6c;
  undefined4 *local_5c;
  BSTR local_58;
  int local_54;
  int *local_50;
  BSTR local_4c;
  void *local_48;
  int *local_44;
  undefined4 local_40;
  int *local_3c;
  BSTR local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x5c;
  local_8 = 0x45418cec;
  local_38 = param_1;
  local_48 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CLZipher_CiffField::Convert");
  local_8 = 0;
  FUN_4540303d(0x454491ec);
  local_40 = 0;
  local_44 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_50 = (int *)((int)this + 0x60);
  local_8._0_1_ = 1;
  FUN_45404ce5(local_50,(int *)(param_1 + 2));
  puVar3 = FUN_4541cbbe(param_1,&local_30);
  local_8._0_1_ = 2;
  FUN_45407800((void *)((int)this + 100),(wchar_t *)*puVar3);
  local_8._0_1_ = 1;
  SysFreeString(local_30);
  FUN_4540303d(0x4544a270);
  piVar1 = *(int **)(param_1 + 2);
  (**(code **)(*piVar1 + 100))(piVar1,&local_30);
  if (local_30 != (BSTR)0x1) goto LAB_45418fe5;
  local_54 = 0;
  local_3c = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  HVar4 = CoCreateInstance((IID *)&DAT_45447d6c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454496b0,&local_3c);
  piVar1 = local_3c;
  if (HVar4 < 0) {
LAB_45418e27:
    pOVar7 = local_38;
    iVar5 = FUN_4541c661((int)local_38);
    bVar2 = FUN_4541c8ec((int)pOVar7);
    if ((bVar2) && ((iVar5 != 1 && (iVar5 != 2)))) {
      FUN_4541c9f1((int *)pOVar7,&local_44);
      if ((int *)*local_44 != local_44) {
        local_30 = (BSTR)((int *)*local_44)[2];
        FUN_4541caea(local_30,&local_34);
        local_8._0_1_ = 5;
        UVar6 = SysStringLen(local_34);
        if (UVar6 == 0) {
          (**(code **)(**(int **)local_30 + 0x5c))(*(int **)local_30);
        }
        else {
          UVar6 = SysStringLen(local_34);
          FUN_45404c3d(&local_38,UVar6 - 1,local_34);
          local_8._0_1_ = 6;
          (**(code **)(**(int **)local_30 + 0x5c))(*(int **)local_30,local_38);
          SysFreeString(local_38);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        SysFreeString(local_34);
      }
      FUN_454120f3((int *)&local_44);
    }
    if (iVar5 == 7) {
      FUN_4541c774(pOVar7,&local_4c);
      local_38 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,8);
      UVar6 = SysStringLen(local_4c);
      bstrString = (BSTR)0x0;
      if ((1 < UVar6) && (local_30 = SysAllocString(local_4c + 1), local_30 != (BSTR)0x0)) {
        SysFreeString((BSTR)0x0);
        local_38 = local_30;
        bstrString = local_30;
      }
      (**(code **)(*(int *)*local_50 + 0x9c))((int *)*local_50,bstrString);
      FUN_4541c9f1((int *)pOVar7,&local_44);
      if ((int *)*local_44 != local_44) {
        local_5c = (undefined4 *)((int *)*local_44)[2];
        FUN_4541caea(local_5c,&local_34);
        local_58 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,10);
        UVar6 = SysStringLen(local_34);
        pOVar7 = (BSTR)0x0;
        if ((1 < UVar6) && (local_30 = SysAllocString(local_34 + 1), local_30 != (BSTR)0x0)) {
          SysFreeString((BSTR)0x0);
          local_58 = local_30;
          pOVar7 = local_30;
        }
        (**(code **)(*(int *)*local_5c + 0x5c))((int *)*local_5c,bstrString);
        SysFreeString(pOVar7);
        local_8 = CONCAT31(local_8._1_3_,8);
        SysFreeString(local_34);
      }
      FUN_454120f3((int *)&local_44);
      piVar1 = (int *)*local_50;
      if ((piVar1 != (int *)0x0) && (*local_50 = 0, piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      SysFreeString(bstrString);
      SysFreeString(local_4c);
    }
  }
  else {
    if (local_3c != (int *)0x0) {
      local_6c.n2.vt = 9;
      local_6c._8_4_ = *local_50;
      if ((int *)local_6c._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_6c._8_4_ + 4))(local_6c._8_4_);
      }
      local_8._0_1_ = 4;
      HVar4 = (**(code **)(*piVar1 + 0xd0))(piVar1,&local_6c,&local_54);
      local_8 = CONCAT31(local_8._1_3_,3);
      VariantClear((VARIANTARG *)&local_6c.n2);
    }
    if ((HVar4 < 0) || (local_54 != 1)) goto LAB_45418e27;
  }
  local_8._0_1_ = 1;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
LAB_45418fe5:
  FUN_454224ff((int *)&local_44);
  FID_conflict__free(local_44);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


