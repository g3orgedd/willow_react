// Source: CLCiffConversion_Data.dll @ 4500cb62; FUN_4500cb62

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500cb62(void *this,int *param_1)

{
  int iVar1;
  UINT UVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  uint in_stack_ffffff74;
  undefined4 uVar6;
  char *pcVar7;
  int *piVar8;
  _union_2683 local_64;
  int local_54;
  int local_50;
  BSTR local_4c;
  LPCWSTR local_48;
  int local_44;
  OLECHAR *local_40;
  BSTR local_3c;
  BSTR local_38;
  BSTR local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCIFFDatabaseResolve::Convert (DateOffset)");
  local_54 = 0;
  local_8._0_1_ = 2;
  iVar1 = (**(code **)(*param_1 + 0x54))();
  local_34 = (BSTR)0x0;
  local_38 = (BSTR)0x0;
  local_8._0_1_ = 4;
  if (iVar1 < 0) {
    pcVar7 = "%s - pDateOffset->get_SQLUsed FAILED, returning E_FAIL";
    goto LAB_4500cbb7;
  }
  if (local_54 == 0) {
LAB_4500cbdb:
    SysFreeString(local_38);
    SysFreeString(local_34);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))();
    }
    goto LAB_4500d115;
  }
  iVar1 = (**(code **)(*param_1 + 0x5c))();
  if (iVar1 < 0) {
    pcVar7 = "%s - pDateOffset->get_ConnStr FAILED, returning E_FAIL";
LAB_4500cbb7:
    FUN_4500274d((int)pcVar7);
    SysFreeString(local_38);
    SysFreeString(local_34);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 100))();
    if (iVar1 < 0) {
      pcVar7 = "%s - pDateOffset->get_DateSQL FAILED, returning E_FAIL";
      goto LAB_4500cbb7;
    }
    iVar1 = FUN_45010317(this,(BSTR)&local_34);
    if (iVar1 < 0) {
      FUN_450020a5(&local_50,local_34);
      local_8._0_1_ = 5;
      FUN_4500274d(0x4503edd8);
      FUN_45002256(&local_50);
      goto LAB_4500cbdb;
    }
    (**(code **)(*param_1 + 0x60))();
    UVar2 = SysStringLen(local_38);
    if (UVar2 == 0) {
      FUN_4500274d(0x4503efc4);
      SysFreeString(local_38);
      SysFreeString(local_34);
    }
    else {
      FUN_450020a5(&local_44,local_38);
      local_8 = CONCAT31(local_8._1_3_,6);
      UVar2 = SysStringLen(*(BSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
      if (UVar2 == 0) {
        in_stack_ffffff74 = 0x4500ccfa;
        FUN_4500274d(0x4503edf4);
      }
      FUN_4500201a(&local_40,&local_44);
      local_8._0_1_ = 7;
      FUN_450020a5(&local_48,L"\'");
      local_8._0_1_ = 8;
      puVar3 = FUN_450020a5(&local_3c,*(LPCWSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
      local_8._0_1_ = 9;
      FUN_450035a3(&local_48,*(int *)((int)*puVar3 + -8),(void *)*puVar3);
      local_8._0_1_ = 8;
      FUN_45002256((int *)&local_3c);
      FUN_4500af7f(&local_48,L"\'");
      if ((DAT_450538e4 & 1) == 0) {
        DAT_450538e4 = DAT_450538e4 | 1;
        local_8._0_1_ = 10;
        FUN_45002050(&DAT_450538e0,"##PRODUCTCODE##");
        FUN_4502386d(&LAB_4503ca2c);
        local_8._0_1_ = 8;
      }
      FUN_45011476(&local_40,DAT_450538e0,local_48);
      FUN_4500af7f(&local_40,L";");
      piVar4 = FUN_45001f5d(&local_3c,local_40);
      FUN_450058c3(&local_38,piVar4);
      SysFreeString(local_3c);
      local_3c = (BSTR)FUN_4500b5ff((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),&local_34
                                    ,0);
      if ((int)local_3c < 0) {
        FUN_450020a5(&local_4c,local_34);
        local_8._0_1_ = 0xb;
        FUN_4500274d(0x4503ee28);
        FUN_45002256((int *)&local_4c);
LAB_4500ce1b:
        FUN_45002256((int *)&local_48);
        FUN_45002256((int *)&local_40);
        FUN_45002256(&local_44);
        SysFreeString(local_38);
        SysFreeString(local_34);
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0)
        ;
        local_8 = 0xffffffff;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))();
        }
        goto LAB_4500d115;
      }
      FUN_45001f8d((uint *)&local_64);
      local_8._0_1_ = 0xc;
      iVar1 = FUN_4500f57b((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),(BSTR)&local_38,
                           (VARIANTARG *)&local_64.n2);
      if ((iVar1 < 0) && (*(int *)(local_44 + -8) != 0)) {
        UVar2 = SysStringLen(*(BSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
        if (UVar2 == 0) {
          in_stack_ffffff74 = 0x4500ceca;
          FUN_4500274d(0x4503edf4);
        }
        FUN_45008a06(&local_40,&local_44);
        FUN_450020a5(&local_3c,L"");
        local_8._0_1_ = 0xd;
        puVar3 = FUN_450020a5(&local_4c,*(LPCWSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this))
        ;
        local_8._0_1_ = 0xe;
        FUN_450035a3(&local_3c,*(int *)((int)*puVar3 + -8),(void *)*puVar3);
        local_8._0_1_ = 0xd;
        FUN_45002256((int *)&local_4c);
        if ((DAT_450538e4 & 2) == 0) {
          DAT_450538e4 = DAT_450538e4 | 2;
          local_8._0_1_ = 0xf;
          FUN_45002050(&DAT_450538e8,"##PRODUCTCODE##");
          FUN_4502386d(&LAB_4503ca36);
          local_8._0_1_ = 0xd;
        }
        FUN_45011476(&local_40,DAT_450538e8,local_3c);
        FUN_4500af7f(&local_40,L";");
        piVar4 = FUN_45001f5d(&local_4c,local_40);
        FUN_450058c3(&local_38,piVar4);
        SysFreeString(local_4c);
        FUN_4500f57b((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),(BSTR)&local_38,
                     (VARIANTARG *)&local_64.n2);
        local_8._0_1_ = 0xc;
        FUN_45002256((int *)&local_3c);
      }
      if (local_64.n2.vt == 1) {
        local_3c = (BSTR)0x0;
        local_8._0_1_ = 0x10;
        (**(code **)(*param_1 + 0x1c))();
        FUN_4500274d(0x4503ee68);
        SysFreeString(local_3c);
      }
      else {
        piVar4 = &local_50;
        local_50 = 0;
        uVar6 = 0x4500d01a;
        piVar8 = param_1;
        iVar1 = (**(code **)(*param_1 + 0x24))();
        if (iVar1 < 0) {
          pcVar7 = "%s - pDateOffset->get_StaticDate FAILED, returning E_FAIL";
        }
        else {
          in_stack_ffffff74 = in_stack_ffffff74 & 0xffff0000;
          if (local_50 == 1) {
            FUN_450102ee(&stack0xffffff74,(VARIANTARG *)&local_64.n2);
            piVar5 = param_1;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 4))(param_1);
            }
            iVar1 = FUN_45011718(piVar5,in_stack_ffffff74,uVar6,piVar8,piVar4);
            if (-1 < iVar1) {
LAB_4500d0bc:
              VariantClear((VARIANTARG *)&local_64.n2);
              goto LAB_4500ce1b;
            }
            pcVar7 = "%s - ResolveAbsoluteDate FAILED, returning E_FAIL";
          }
          else {
            FUN_450102ee(&stack0xffffff74,(VARIANTARG *)&local_64.n2);
            piVar5 = param_1;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 4))(param_1);
            }
            iVar1 = FUN_45011c74(this,piVar5,in_stack_ffffff74,uVar6,piVar8,piVar4);
            if (-1 < iVar1) goto LAB_4500d0bc;
            pcVar7 = "%s - ResolveDate FAILED, returning E_FAIL";
          }
        }
        FUN_4500274d((int)pcVar7);
      }
      VariantClear((VARIANTARG *)&local_64.n2);
      FUN_45002256((int *)&local_48);
      FUN_45002256((int *)&local_40);
      FUN_45002256(&local_44);
      SysFreeString(local_38);
      SysFreeString(local_34);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
LAB_4500d115:
  FUN_45022ec7();
  return;
}


