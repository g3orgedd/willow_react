// Source: CLCSTextBasedField.dll @ 42405325; FUN_42405325

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_42405325(BSTR param_1,BSTR param_2)

{
  int *piVar1;
  HRESULT HVar2;
  code *pcVar3;
  int *piVar4;
  VARIANTARG local_48;
  VARIANTARG local_38;
  int *local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0;
  piVar4 = (int *)0x0;
  local_28 = (int *)0x0;
  CComQIPtr<>(&local_24,(undefined4 *)param_1);
  pcVar3 = SysFreeString_exref;
  if (local_24 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    FUN_42403802((uint *)&local_48);
    local_8._0_1_ = 3;
    (**(code **)(*local_24 + 0xb4))(local_24,&local_48);
    CComQIPtr<>(&local_20,(undefined4 *)local_48.n1._8_4_);
    local_1c = 0;
    local_8 = CONCAT31(local_8._1_3_,4);
    (**(code **)(*local_20 + 0x1c))(local_20,&local_1c);
    local_18 = 0;
    if (0 < local_1c) {
      do {
        FUN_42403802((uint *)&local_38);
        local_18 = local_18 + 1;
        local_8._0_1_ = 5;
        (**(code **)(*local_20 + 0x30))(local_20,local_18,&local_38);
        CComQIPtr<>(local_14,(undefined4 *)local_38.n1._8_4_);
        param_1 = (BSTR)0x0;
        local_8._0_1_ = 7;
        (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1);
        HVar2 = VarBstrCmp(param_1,param_2,0x400,0);
        piVar1 = local_14[0];
        pcVar3 = SysFreeString_exref;
        if (HVar2 == 1) {
          local_28 = local_14[0];
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 4))(local_14[0]);
          }
          SysFreeString(param_1);
          local_8 = CONCAT31(local_8._1_3_,5);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          VariantClear(&local_38);
          piVar4 = piVar1;
          break;
        }
        SysFreeString(param_1);
        local_8 = CONCAT31(local_8._1_3_,5);
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        VariantClear(&local_38);
      } while (local_18 < local_1c);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    VariantClear(&local_48);
  }
  local_8._0_1_ = 1;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  (*pcVar3)(param_2);
  return piVar4;
}


