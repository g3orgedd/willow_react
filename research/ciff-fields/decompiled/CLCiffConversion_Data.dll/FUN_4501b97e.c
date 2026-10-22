// Source: CLCiffConversion_Data.dll @ 4501b97e; FUN_4501b97e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4501b97e(void *this,undefined4 *param_1,int *param_2)

{
  _union_2683 local_44;
  _union_2683 local_34;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x4501b98a;
  local_24 = 0;
  CComQIPtr<>(&local_1c,*(undefined4 **)this);
  if (local_1c != (int *)0x0) {
    local_18 = (BSTR)0x0;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    (**(code **)(*local_1c + 0x140))(local_1c,&local_18);
    CComQIPtr<>(local_14,(undefined4 *)*param_2);
    if (local_14[0] != (int *)0x0) {
      FUN_45001f8d((uint *)&local_44);
      local_8._0_1_ = 3;
      (**(code **)(*local_14[0] + 0xb4))(local_14[0],&local_44);
      if (local_44.n2.vt == 0) {
        FUN_45005aac(0x45040720);
      }
      else {
        CComQIPtr<>(&param_2,(undefined4 *)local_44._8_4_);
        if (param_2 != (int *)0x0) {
          FUN_45001f8d((uint *)&local_34);
          local_8._0_1_ = 5;
          (**(code **)(*param_2 + 0x28))(param_2,local_18,&local_34);
          if (local_34.n2.vt != 0) {
            CComQIPtr<>(&local_20,(undefined4 *)local_34._8_4_);
            *param_1 = local_20;
            if ((local_20 != (int *)0x0) &&
               ((**(code **)(*local_20 + 4))(local_20), local_20 != (int *)0x0)) {
              (**(code **)(*local_20 + 8))(local_20);
            }
            VariantClear((VARIANTARG *)&local_34.n2);
            local_8._0_1_ = 3;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))(param_2);
            }
            VariantClear((VARIANTARG *)&local_44.n2);
            local_8 = CONCAT31(local_8._1_3_,1);
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            SysFreeString(local_18);
            local_8 = 0xffffffff;
            if (local_1c == (int *)0x0) {
              return param_1;
            }
            (**(code **)(*local_1c + 8))(local_1c);
            return param_1;
          }
          VariantClear((VARIANTARG *)&local_34.n2);
        }
        local_8._0_1_ = 3;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
      }
      VariantClear((VARIANTARG *)&local_44.n2);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    SysFreeString(local_18);
  }
  local_8 = 0xffffffff;
  *param_1 = 0;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return param_1;
}


