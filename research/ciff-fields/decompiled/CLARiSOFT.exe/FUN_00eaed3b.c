// Source: CLARiSOFT.exe @ 00eaed3b; FUN_00eaed3b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_00eaed3b(int *param_1,undefined4 param_2)

{
  bool bVar1;
  bool bVar2;
  VARIANTARG local_3c;
  _union_2683 local_2c;
  int local_1c;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0;
  (**(code **)(*param_1 + 0x24))(param_1,&local_1c);
  local_14[0] = (BSTR)0x0;
  bVar2 = true;
  local_8._0_1_ = 1;
  (**(code **)(*param_1 + 0x3c))(param_1,local_14);
  if (local_1c != 0) {
    bVar1 = FUN_00e03edc(local_14,L"Free");
    if (!bVar1) {
      FUN_00e03b51((uint *)&local_3c);
      local_8._0_1_ = 2;
      (**(code **)(*param_1 + 0x7c))(param_1,&local_3c);
      CComQIPtr<>(&local_18,(undefined4 *)local_3c.n1._8_4_);
      FUN_00e03b51((uint *)&local_2c);
      local_8._0_1_ = 4;
      (**(code **)(*local_18 + 0x30))(local_18,param_2,&local_2c);
      bVar2 = local_2c.n2.vt != 0;
      VariantClear((VARIANTARG *)&local_2c.n2);
      local_8._0_1_ = 2;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      VariantClear(&local_3c);
    }
  }
  SysFreeString(local_14[0]);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return bVar2;
}


