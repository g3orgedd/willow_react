// Source: CLCiffConversion_Layout.dll @ 4541f7b5; FUN_4541f7b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4541f7b5(void *this,undefined4 *param_1,BSTR param_2,BSTR param_3)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  _union_2683 local_2c;
  int *local_1c;
  void *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0;
  local_14[0] = param_2;
  pOVar2 = param_2;
  local_18 = this;
  if (param_2 != param_3) {
    do {
      piVar1 = *(int **)pOVar2;
      local_1c = piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      local_14[0] = (BSTR)0x0;
      local_8._0_1_ = 2;
      (**(code **)(*piVar1 + 0x1c))(piVar1,local_14);
      (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,local_14[0]);
      SysFreeString(local_14[0]);
      local_8 = (uint)local_8._1_3_ << 8;
      (**(code **)(*piVar1 + 8))(piVar1);
      pOVar2 = pOVar2 + 2;
    } while (pOVar2 != param_3);
    bVar3 = param_2 == param_3;
    local_14[0] = param_2;
    while (!bVar3) {
      piVar1 = *(int **)local_14[0];
      local_1c = piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      local_8._0_1_ = 3;
      local_2c.n2.vt = 9;
      local_2c._8_4_ = piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      local_8._0_1_ = 4;
      (**(code **)(*(int *)*param_1 + 0x7c))
                ((int *)*param_1,local_2c._0_4_,local_2c.decVal.Hi32,local_2c._8_4_,local_2c._12_4_)
      ;
      VariantClear((VARIANTARG *)&local_2c.n2);
      local_8 = (uint)local_8._1_3_ << 8;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      local_14[0] = local_14[0] + 2;
      bVar3 = local_14[0] == param_3;
    }
  }
  FUN_45412090(&param_2);
  FUN_45422483((int *)&param_2);
  return 0;
}


