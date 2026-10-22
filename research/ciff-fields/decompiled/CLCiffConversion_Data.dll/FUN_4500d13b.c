// Source: CLCiffConversion_Data.dll @ 4500d13b; FUN_4500d13b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_4500d13b(void *this,int *param_1)

{
  int iVar1;
  UINT UVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_60;
  _union_2683 local_5c;
  BSTR local_4c;
  int local_48;
  int local_44;
  BSTR local_40;
  LPCWSTR local_3c;
  OLECHAR *local_38;
  BSTR local_34;
  BSTR local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x50;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFDatabaseResolve::Convert (Price)");
  local_60 = 0;
  local_8._0_1_ = 1;
  (**(code **)(*param_1 + 0x54))(param_1,&local_60);
  if (local_60 == 0) goto LAB_4500d536;
  local_40 = (BSTR)0x0;
  local_34 = (BSTR)0x0;
  local_8._0_1_ = 3;
  (**(code **)(*param_1 + 100))(param_1,&local_40);
  (**(code **)(*param_1 + 0x5c))(param_1,&local_34);
  iVar1 = FUN_45010317(this,(BSTR)&local_40);
  if (-1 < iVar1) {
    (**(code **)(*param_1 + 0x68))(param_1,local_40);
    UVar2 = SysStringLen(local_34);
    if (UVar2 != 0) {
      FUN_450020a5(&local_38,local_34);
      local_8._0_1_ = 4;
      FUN_450020a5(&local_44,local_34);
      local_8._0_1_ = 5;
      FUN_45002050(&local_3c,"\'");
      local_8._0_1_ = 6;
      puVar3 = FUN_450020a5(&local_30,*(LPCWSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
      local_8._0_1_ = 7;
      FUN_450035a3(&local_3c,*(int *)((int)*puVar3 + -8),(void *)*puVar3);
      local_8._0_1_ = 6;
      FUN_45002256((int *)&local_30);
      FUN_4500af7f(&local_3c,L"\'");
      if ((DAT_450538f0 & 1) == 0) {
        DAT_450538f0 = DAT_450538f0 | 1;
        local_8._0_1_ = 8;
        FUN_45002050(&DAT_450538ec,"##PRODUCTCODE##");
        FUN_4502386d(&LAB_4503ca4a);
        local_8._0_1_ = 6;
      }
      FUN_45011476(&local_38,DAT_450538ec,local_3c);
      FUN_45002050(&local_30,";");
      local_8._0_1_ = 9;
      FUN_450035a3(&local_38,*(int *)(local_30 + -4),local_30);
      local_8._0_1_ = 6;
      FUN_45002256((int *)&local_30);
      piVar4 = FUN_45001f5d(&local_30,local_38);
      FUN_450058c3(&local_34,piVar4);
      SysFreeString(local_30);
      iVar1 = FUN_4500b5ff((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),&local_40,0);
      if (-1 < iVar1) {
        FUN_45001f8d((uint *)&local_5c);
        local_8._0_1_ = 10;
        iVar1 = FUN_4500f57b((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),(BSTR)&local_34,
                             (VARIANTARG *)&local_5c.n2);
        if ((iVar1 < 0) && (*(int *)(local_44 + -8) != 0)) {
          UVar2 = SysStringLen(*(BSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
          if (UVar2 == 0) {
            FUN_4500274d(0x4503edf4);
          }
          FUN_45008a06(&local_38,&local_44);
          FUN_45002050(&local_30,"");
          local_8._0_1_ = 0xb;
          puVar3 = FUN_450020a5(&local_4c,
                                *(LPCWSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
          local_8._0_1_ = 0xc;
          FUN_450035a3(&local_30,*(int *)((int)*puVar3 + -8),(void *)*puVar3);
          local_8._0_1_ = 0xb;
          FUN_45002256((int *)&local_4c);
          if ((DAT_450538f0 & 2) == 0) {
            DAT_450538f0 = DAT_450538f0 | 2;
            local_8._0_1_ = 0xd;
            FUN_45002050(&DAT_450538f4,"##PRODUCTCODE##");
            FUN_4502386d(&LAB_4503ca22);
            local_8._0_1_ = 0xb;
          }
          FUN_45011476(&local_38,DAT_450538f4,local_30);
          FUN_4500af7f(&local_38,L";");
          piVar4 = FUN_45001f5d(&local_4c,local_38);
          FUN_450058c3(&local_34,piVar4);
          SysFreeString(local_4c);
          FUN_4500f57b((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),(BSTR)&local_34,
                       (VARIANTARG *)&local_5c.n2);
          local_8._0_1_ = 10;
          FUN_45002256((int *)&local_30);
        }
        local_48 = 2;
        iVar1 = 0;
        local_30 = (BSTR)(**(code **)(*param_1 + 0x7c))(param_1,&local_48);
        iVar6 = 1;
        iVar5 = local_48;
        if (0 < local_48) {
          do {
            iVar6 = iVar6 * 10;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        if (local_5c.n2.vt == 2) {
          iVar1 = (int)(short)local_5c._8_2_;
        }
        else if (local_5c.n2.vt == 3) {
          iVar1 = CONCAT22(local_5c._10_2_,local_5c._8_2_);
        }
        else if (local_5c.n2.vt == 4) {
          iVar1 = (int)((float)iVar6 * (float)CONCAT22(local_5c._10_2_,local_5c._8_2_) +
                       _DAT_4503f914);
        }
        else if (local_5c.n2.vt == 5) {
          iVar1 = (int)((float)(double)CONCAT44(local_5c._12_4_,
                                                CONCAT22(local_5c._10_2_,local_5c._8_2_)) *
                        (float)iVar6 + _DAT_4503f914);
        }
        else {
          if (local_5c.n2.vt == 6) {
LAB_4500d478:
            VariantChangeType((VARIANTARG *)&local_5c.n2,(VARIANTARG *)&local_5c,0,8);
          }
          else if (local_5c.n2.vt != 8) {
            if (local_5c.n2.vt != 0xe) goto LAB_4500d4f0;
            goto LAB_4500d478;
          }
          iVar1 = FUN_45010a64((BSTR)CONCAT22(local_5c._10_2_,local_5c._8_2_),local_48);
        }
LAB_4500d4f0:
        (**(code **)(*param_1 + 0x30))(param_1,iVar1);
        (**(code **)(*param_1 + 0x28))(param_1,iVar1);
        VariantClear((VARIANTARG *)&local_5c.n2);
      }
      FUN_45002256((int *)&local_3c);
      FUN_45002256(&local_44);
      FUN_45002256((int *)&local_38);
    }
  }
  SysFreeString(local_34);
  SysFreeString(local_40);
LAB_4500d536:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_45022eb8();
  return;
}


