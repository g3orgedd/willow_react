// Source: CiffHelper.dll @ 4081bb85; FUN_4081bb85

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * FUN_4081bb85(undefined4 *param_1,BSTR param_2,int *param_3)

{
  HRESULT HVar1;
  VARIANTARG local_34;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int *local_18;
  BSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 2;
  *param_1 = 0;
  local_20 = 0;
  local_24 = 1;
  (**(code **)(*param_3 + 0x1c))(param_3,&local_20);
  local_1c = 0;
  if (0 < local_20) {
    do {
      FUN_40802e76((uint *)&local_34);
      local_1c = local_1c + 1;
      local_8._0_1_ = 3;
      (**(code **)(*param_3 + 0x30))(param_3,local_1c,&local_34);
      CComQIPtr<>(&local_18,(undefined4 *)local_34.n1._8_4_);
      local_14[0] = (BSTR)0x0;
      local_8._0_1_ = 5;
      (**(code **)(*local_18 + 0x1c))(local_18,local_14);
      HVar1 = VarBstrCmp(local_14[0],param_2,0x400,0);
      if (HVar1 == 1) {
        *param_1 = local_18;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 4))(local_18);
        }
        SysFreeString(local_14[0]);
        local_8 = CONCAT31(local_8._1_3_,3);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        VariantClear(&local_34);
        break;
      }
      SysFreeString(local_14[0]);
      local_8 = CONCAT31(local_8._1_3_,3);
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      VariantClear(&local_34);
    } while (local_1c < local_20);
  }
  SysFreeString(param_2);
  local_8 = local_8 & 0xffffff00;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return param_1;
}


