// Source: CLCiffConversion_Data.dll @ 4500f57b; FUN_4500f57b

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500f57b(void *this,BSTR param_1,VARIANTARG *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  VARIANTARG local_8c;
  _union_2683 local_78;
  VARIANTARG local_68;
  void *local_58;
  VARIANTARG *local_54;
  void *local_50;
  short local_4c [2];
  BSTR local_48;
  int local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  int *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0x4500f58a;
  local_48 = param_1;
  local_54 = param_2;
  local_58 = this;
  local_50 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CADOConnection::ExecuteToVariant");
  local_8 = 0;
  local_38 = 0;
  local_34 = (int *)0x0;
  FUN_45001f8d((uint *)&local_8c);
  local_8._0_1_ = 3;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  local_34 = (int *)0x0;
  iVar3 = FUN_4500f33f(this,param_1,(int)&local_8c,0,(int)&local_34);
  local_38 = iVar3;
  if ((iVar3 < 0) || (local_34 == (int *)0x0)) goto LAB_4500f787;
  if (local_34 == (int *)0x0) goto LAB_4500f611;
  iVar3 = (**(code **)(*local_34 + 0x98))(local_34);
  if (iVar3 < 0) {
LAB_4500f779:
    local_38 = 1;
    iVar3 = 1;
  }
  else {
    if (local_34 == (int *)0x0) goto LAB_4500f611;
    local_44 = (**(code **)(*local_34 + 0x50))(local_34,local_4c);
    iVar3 = local_44;
    local_38 = local_44;
    if (-1 < local_44) {
      if (local_4c[0] != 0) goto LAB_4500f779;
      local_40 = (int *)0x0;
      local_3c = (int *)0x0;
      FUN_45001f8d((uint *)&local_68);
      piVar2 = local_34;
      local_8._0_1_ = 6;
      if (local_34 == (int *)0x0) {
LAB_4500f611:
                    /* WARNING: Subroutine does not return */
        _com_issue_error(-0x7fffbffd);
      }
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))(local_40);
      }
      local_40 = (int *)0x0;
      iVar3 = (**(code **)(*piVar2 + 0x54))(piVar2,&local_40);
      FUN_4500b385(iVar3);
      piVar2 = local_40;
      if (local_40 != (int *)0x0) {
        local_78.n2.vt = 3;
        uVar1 = local_78._0_4_;
        local_78._8_4_ = 0;
        local_8._0_1_ = 7;
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 8))(local_3c);
        }
        local_3c = (int *)0x0;
        iVar3 = (**(code **)(*piVar2 + 0x28))
                          (piVar2,uVar1,local_78.decVal.Hi32,0,local_78._12_4_,&local_3c);
        FUN_4500b385(iVar3);
        local_8._0_1_ = 6;
        VariantClear((VARIANTARG *)&local_78.n2);
      }
      if (local_3c != (int *)0x0) {
        iVar3 = (**(code **)(*local_3c + 0x34))(local_3c,&local_68);
        FUN_4500b385(iVar3);
        if (local_54 != &local_68) {
          FUN_450102ee(local_54,&local_68);
        }
      }
      FUN_45011457((int *)&local_40);
      FUN_45011457((int *)&local_3c);
      if (local_34 == (int *)0x0) goto LAB_4500f611;
      (**(code **)(*local_34 + 0x80))(local_34);
      VariantClear(&local_68);
      local_8._0_1_ = 4;
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      local_8._0_1_ = 3;
      iVar3 = local_44;
      this = local_50;
      if (local_40 != (int *)0x0) {
        (**(code **)(*local_40 + 8))(local_40);
        iVar3 = local_44;
        this = local_50;
      }
    }
  }
  FUN_45011457((int *)&local_34);
LAB_4500f787:
  VariantClear(&local_8c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
    FUN_4500f834();
    return;
  }
  local_8 = 0;
  if (iVar3 < 0) {
    FUN_450137d5((int)this);
    FUN_4500274d(0x4503e7cc);
  }
  else if (iVar3 == 1) {
    FUN_450137d5((int)this);
    FUN_4500274d(0x4503e7f0);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_45022ec7();
  return;
}


