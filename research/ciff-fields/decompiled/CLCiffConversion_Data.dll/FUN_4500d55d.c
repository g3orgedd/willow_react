// Source: CLCiffConversion_Data.dll @ 4500d55d; FUN_4500d55d

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500d55d(void *this,BSTR param_1)

{
  int *this_00;
  BSTR pOVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  void *local_40;
  int *local_3c;
  undefined4 local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x4500d569;
  local_30 = param_1;
  local_40 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFDatabaseResolve::Convert (field)");
  local_8 = 0;
  *(undefined1 *)((int)this + -4) = 0;
  local_38 = 0;
  local_3c = (int *)FUN_45013f7b((int *)0x0,(int *)0x0);
  local_8._0_1_ = 1;
  this_00 = (int *)((int)this + -8);
  FUN_450022ba((void *)((int)this + *(int *)(*this_00 + 4) + 0x58),(int *)(param_1 + 2));
  puVar2 = FUN_45007442(param_1,&local_34);
  local_8._0_1_ = 2;
  FUN_45002365((void *)((int)this + *(int *)(*this_00 + 4) + 0x5c),(LPCWSTR)*puVar2);
  local_8._0_1_ = 1;
  SysFreeString(local_34);
  puVar2 = FUN_450072f3(local_30,&local_34);
  local_8._0_1_ = 3;
  FUN_45002365((void *)((int)this + *(int *)(*this_00 + 4) + 0x60),(LPCWSTR)*puVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  SysFreeString(local_34);
  FUN_4500735e((int *)local_30,&local_3c);
  piVar4 = (int *)*local_3c;
  if (piVar4 != local_3c) {
    do {
      iVar3 = FUN_4500bfa4(this_00,(int *)piVar4[2],(int)local_30);
      this = local_40;
      if (iVar3 < 0) break;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != local_3c);
  }
  FUN_45004f8d((int *)&local_3c);
  piVar4 = *(int **)(*(int *)(*this_00 + 4) + 0x58 + (int)this);
  if ((piVar4 != (int *)0x0) &&
     (*(undefined4 *)(*(int *)(*this_00 + 4) + 0x58 + (int)this) = 0, piVar4 != (int *)0x0)) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  FUN_45002365((void *)(*(int *)(*this_00 + 4) + 0x5c + (int)this),L"");
  FUN_45002365((void *)(*(int *)(*this_00 + 4) + 0x60 + (int)this),L"");
  pOVar1 = local_30;
  if (*(char *)((int)this + -4) == '\0') goto LAB_4500d748;
  (**(code **)(**(int **)(local_30 + 2) + 100))(*(int **)(local_30 + 2),&local_40);
  if (local_40 == (void *)0x0) {
    CComQIPtr<>(&local_30,*(undefined4 **)(pOVar1 + 2));
    local_8._0_1_ = 4;
    bVar5 = local_30 == (BSTR)0x0;
    local_34 = local_30;
    if (!bVar5) {
      (**(code **)(*(int *)local_30 + 0x174))(local_30,1);
      local_34 = local_30;
LAB_4500d73a:
      bVar5 = local_34 == (BSTR)0x0;
      local_34 = local_34;
    }
  }
  else if (local_40 == (void *)0x1) {
    CComQIPtr<>(&local_30,*(undefined4 **)(pOVar1 + 2));
    local_8._0_1_ = 5;
    bVar5 = local_30 == (BSTR)0x0;
    local_34 = local_30;
    if (!bVar5) {
      (**(code **)(*(int *)local_30 + 0x240))(local_30,1);
      local_34 = local_30;
      goto LAB_4500d73a;
    }
  }
  else {
    if (local_40 != (void *)0x2) goto LAB_4500d748;
    CComQIPtr<>(&local_34,*(undefined4 **)(pOVar1 + 2));
    local_8._0_1_ = 6;
    bVar5 = true;
    if (local_34 != (BSTR)0x0) {
      (**(code **)(*(int *)local_34 + 0xf8))(local_34,1);
      goto LAB_4500d73a;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  if (!bVar5) {
    (**(code **)(*(int *)local_34 + 8))(local_34);
  }
LAB_4500d748:
  FUN_4501423d((int *)&local_3c);
  FID_conflict__free(local_3c);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


