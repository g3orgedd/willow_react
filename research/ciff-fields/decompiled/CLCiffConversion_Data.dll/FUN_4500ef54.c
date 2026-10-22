// Source: CLCiffConversion_Data.dll @ 4500ef54; FUN_4500ef54

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500ef54(void *this,BSTR param_1,void *param_2)

{
  undefined4 uVar1;
  OLECHAR *pOVar2;
  bool bVar3;
  int iVar4;
  UINT UVar5;
  LPCSTR ****pppppCVar6;
  int *piVar7;
  OLECHAR **ppOVar8;
  VARIANTARG local_8c;
  VARIANTARG local_7c;
  _union_2683 local_6c;
  void *local_58;
  BSTR local_54;
  undefined4 local_50;
  void *local_4c;
  void *local_48;
  int local_44;
  int local_40;
  int *local_3c;
  OLECHAR *local_38;
  BSTR local_34;
  LPCSTR ***local_30 [5];
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0x4500ef63;
  local_48 = param_2;
  local_58 = this;
  local_4c = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_30,
             "CADOConnection::Execute1");
  local_8 = 0;
  local_40 = 0;
  local_3c = (int *)0x0;
  FUN_45001f8d((uint *)&local_8c);
  local_8._0_1_ = 3;
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
  }
  local_3c = (int *)0x0;
  local_40 = FUN_4500f33f(this,param_1,(int)&local_8c,0,(int)&local_3c);
  local_50 = 0;
  if ((local_40 < 0) || (local_3c == (int *)0x0)) {
    bVar3 = FUN_450023b0(param_1,
                         L"SELECT [ParamValue] FROM [Parameters] WHERE [ParamID] = \'Database Type\'"
                        );
    if (!bVar3) {
      pppppCVar6 = local_30;
      if (0xf < local_1c) {
        pppppCVar6 = (LPCSTR ****)local_30[0];
      }
      FUN_45002050(&local_38,(LPCSTR)pppppCVar6);
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_4500af7f(&local_38,L" : ");
      ppOVar8 = &local_38;
      piVar7 = *(int **)((int)local_4c + 0x20);
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 4))(piVar7);
      }
      FUN_4500f908(piVar7,ppOVar8);
      if ((*(int *)param_1 != 0) && (UVar5 = SysStringLen(*(BSTR *)param_1), UVar5 != 0)) {
        FUN_4500274d(0x4503e718);
      }
      FUN_45001f5d(&local_34,local_38);
      local_8._0_1_ = 10;
      if ((local_34 != (BSTR)0x0) && (UVar5 = SysStringLen(local_34), UVar5 != 0)) {
        FUN_4500274d(0x4503e744);
      }
      SysFreeString(local_34);
      FUN_45002256((int *)&local_38);
    }
    goto LAB_4500f28b;
  }
  if (local_3c == (int *)0x0) goto LAB_4500efea;
  local_40 = (**(code **)(*local_3c + 0x98))(local_3c);
  if (local_40 < 0) {
    if ((*(int *)param_1 != 0) && (UVar5 = SysStringLen(*(BSTR *)param_1), UVar5 != 0)) {
      FUN_4500274d(0x4503e63c);
    }
LAB_4500f1a3:
    local_40 = 1;
  }
  else {
    if (local_3c == (int *)0x0) goto LAB_4500efea;
    local_44 = (**(code **)(*local_3c + 0x50))(local_3c,&local_50);
    local_40 = local_44;
    if (-1 < local_44) {
      if ((short)local_50 != 0) goto LAB_4500f1a3;
      local_38 = (OLECHAR *)0x0;
      local_34 = (BSTR)0x0;
      FUN_45001f8d((uint *)&local_7c);
      piVar7 = local_3c;
      local_54 = (BSTR)0x0;
      local_8._0_1_ = 7;
      if (local_3c == (int *)0x0) {
LAB_4500efea:
                    /* WARNING: Subroutine does not return */
        _com_issue_error(-0x7fffbffd);
      }
      if (local_38 != (OLECHAR *)0x0) {
        (**(code **)(*(int *)local_38 + 8))(local_38);
      }
      local_38 = (OLECHAR *)0x0;
      iVar4 = (**(code **)(*piVar7 + 0x54))(piVar7,&local_38);
      FUN_4500b385(iVar4);
      pOVar2 = local_38;
      if (local_38 != (OLECHAR *)0x0) {
        local_6c.n2.vt = 3;
        uVar1 = local_6c._0_4_;
        local_6c._8_4_ = 0;
        local_8._0_1_ = 8;
        if (local_34 != (BSTR)0x0) {
          (**(code **)(*(int *)local_34 + 8))(local_34);
        }
        local_34 = (BSTR)0x0;
        iVar4 = (**(code **)(*(int *)pOVar2 + 0x28))
                          (pOVar2,uVar1,local_6c.decVal.Hi32,0,local_6c._12_4_,&local_34);
        FUN_4500b385(iVar4);
        local_8._0_1_ = 7;
        VariantClear((VARIANTARG *)&local_6c.n2);
      }
      if (local_34 != (BSTR)0x0) {
        iVar4 = (**(code **)(*(int *)local_34 + 0x34))(local_34,&local_7c);
        FUN_4500b385(iVar4);
        if (local_34 == (BSTR)0x0) goto LAB_4500efea;
        iVar4 = (**(code **)(*(int *)local_34 + 0x2c))(local_34,&local_54);
        FUN_4500b385(iVar4);
      }
      FUN_45013cef(&local_7c,local_48);
      FUN_45011457((int *)&local_38);
      FUN_45011457((int *)&local_34);
      if (local_3c == (int *)0x0) goto LAB_4500efea;
      (**(code **)(*local_3c + 0x80))(local_3c);
      SysFreeString(local_54);
      VariantClear(&local_7c);
      local_8._0_1_ = 4;
      if (local_34 != (BSTR)0x0) {
        (**(code **)(*(int *)local_34 + 8))(local_34);
      }
      local_8._0_1_ = 3;
      if (local_38 != (OLECHAR *)0x0) {
        (**(code **)(*(int *)local_38 + 8))(local_38);
      }
    }
  }
  FUN_45011457((int *)&local_3c);
LAB_4500f28b:
  VariantClear(&local_8c);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_3c != (int *)0x0) {
    (**(code **)(*local_3c + 8))(local_3c);
    FUN_4500f32a();
    return;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_30,true,0);
  FUN_45022ec7();
  return;
}


