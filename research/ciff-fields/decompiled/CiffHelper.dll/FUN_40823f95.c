// Source: CiffHelper.dll @ 40823f95; FUN_40823f95

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_40823f95(int *param_1)

{
  bool bVar1;
  int iVar2;
  _union_2683 local_4c;
  _union_2683 local_3c;
  _union_2683 local_2c;
  int local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x40823fa1;
  FUN_40802e40(&local_18,L"Speed");
  local_8 = 0;
  FUN_40802e76((uint *)&local_3c);
  local_8._0_1_ = 1;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x30))((int *)*param_1,local_18,&local_3c);
  if ((-1 < iVar2) && (local_3c.n2.vt == 9)) {
    param_1 = (int *)0x0;
    local_8._0_1_ = 2;
    iVar2 = (*(code *)**(undefined4 **)local_3c._8_4_)(local_3c._8_4_,&DAT_4084ab18,&param_1);
    if ((-1 < iVar2) &&
       (((param_1 != (int *)0x0 &&
         (iVar2 = (**(code **)(*param_1 + 0x24))(param_1,&local_1c), -1 < iVar2)) && (local_1c == 2)
        ))) {
      FUN_40802e76((uint *)&local_2c);
      local_8._0_1_ = 3;
      (**(code **)(*param_1 + 0x2c))(param_1,&local_2c);
      FUN_40802e40(local_14,L"HIGH");
      local_8._0_1_ = 4;
      local_4c._8_4_ = 0;
      if (local_2c.n2.vt == 8) {
        bVar1 = FUN_40803ed6(local_14,(OLECHAR *)local_2c._8_4_);
        if (bVar1) {
          local_4c._8_4_ = 1;
        }
      }
      local_4c.n2.vt = 3;
      local_8._0_1_ = 5;
      (**(code **)(*param_1 + 0x28))(param_1,0);
      (**(code **)(*param_1 + 0x30))
                (param_1,local_4c._0_4_,local_4c.decVal.Hi32,local_4c._8_4_,local_4c._12_4_);
      VariantClear((VARIANTARG *)&local_4c.n2);
      SysFreeString(local_14[0]);
      VariantClear((VARIANTARG *)&local_2c.n2);
    }
    local_8._0_1_ = 1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  VariantClear((VARIANTARG *)&local_3c.n2);
  SysFreeString(local_18);
  return iVar2;
}


