// Source: CLCiffConversion_Data.dll @ 45012f59; FUN_45012f59

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_45012f59(void *this,int *param_1,CComBSTR *param_2,_union_2683 *param_3)

{
  undefined4 *puVar1;
  _union_2683 *p_Var2;
  UINT UVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  _union_2683 local_3c;
  _union_2683 local_2c;
  BSTR local_1c;
  int *local_18;
  CComBSTR *local_14;
  int local_8;
  undefined4 uStack_4;
  
  p_Var2 = param_3;
  uStack_4 = 0x2c;
  local_8 = 0x45012f65;
  if ((*param_1 == 0) || (*(int *)(*(int *)(*(int *)this + 4) + 0x38 + (int)this) == 0)) {
    return -0x7fffbffd;
  }
  if (((param_3->n2).vt == 8) && (UVar3 = SysStringLen((param_3->n2).n3.bstrVal), UVar3 != 0)) {
    FUN_45001f8d((uint *)&local_3c);
    local_18 = (int *)0x0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    puVar1 = *(undefined4 **)(*(int *)(*(int *)this + 4) + 0x38 + (int)this);
    iVar4 = (**(code **)*puVar1)(puVar1,&DAT_4503e4b0,&local_18);
    if (-1 < iVar4) {
      iVar4 = FUN_45009467((BSTR)&local_18,param_2,(VARIANTARG *)&local_3c.n2);
    }
    param_3 = (_union_2683 *)0x0;
    if ((((-1 < iVar4) && (local_3c.n2.vt == 9)) && ((IUnknown *)local_3c._8_4_ != (IUnknown *)0x0))
       && (ATL::AtlComQIPtrAssign
                     ((IUnknown **)&param_3,(IUnknown *)local_3c._8_4_,(_GUID *)&DAT_4503dddc),
          param_3 != (_union_2683 *)0x0)) {
      FUN_45001f8d((uint *)&local_2c);
      param_2 = (CComBSTR *)0x0;
      local_14 = (CComBSTR *)0x0;
      local_8._0_1_ = 3;
      iVar4 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,&param_2);
      if (-1 < iVar4) {
        if (param_2 < (CComBSTR *)0x2) {
          FUN_45001f5d(&local_1c,(p_Var2->n2).n3.bstrVal);
          local_8 = CONCAT31(local_8._1_3_,4);
          iVar4 = FUN_450093e6(&local_1c);
          if (-1 < iVar4) {
            lVar5 = __wtol((p_Var2->n2).n3.bstrVal);
            FUN_4500aeef(&local_2c,lVar5);
            local_14 = param_2;
          }
          local_8._0_1_ = 3;
          SysFreeString(local_1c);
        }
        else {
          local_14 = (CComBSTR *)0x2;
          if (&local_2c != p_Var2) {
            FUN_450102ee(&local_2c,(VARIANTARG *)&p_Var2->n2);
          }
          iVar4 = 0;
        }
        if ((iVar4 < 0) ||
           (uVar6 = FUN_45009989(*(int *)(*(int *)this + 4) + 0x34 + (int)this,&param_3,
                                 (BSTR)local_14,(VARIANTARG *)&local_2c.n2), (int)uVar6 < 0)) {
          VariantClear((VARIANTARG *)&local_2c.n2);
          (**(code **)(*(int *)param_3 + 0x58))(param_3,&local_2c);
          FUN_4500274d(0x4503f628);
        }
        iVar4 = (**(code **)(*(int *)*param_1 + 0x30))
                          ((int *)*param_1,local_2c._0_4_,local_2c.decVal.Hi32,local_2c._8_4_,
                           local_2c._12_4_);
      }
      VariantClear((VARIANTARG *)&local_2c.n2);
    }
    local_8._0_1_ = 1;
    if (param_3 != (_union_2683 *)0x0) {
      (**(code **)(*(int *)param_3 + 8))(param_3);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
    VariantClear((VARIANTARG *)&local_3c.n2);
    return iVar4;
  }
  return -0x7ff8ffa9;
}


