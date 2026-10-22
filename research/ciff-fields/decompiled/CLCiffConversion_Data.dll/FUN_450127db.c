// Source: CLCiffConversion_Data.dll @ 450127db; FUN_450127db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_450127db(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  _union_2683 local_48;
  _union_2683 local_38;
  int *local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x450127e7;
  iVar3 = 0;
  local_24 = param_1;
  FUN_45001f8d((uint *)&local_48);
  local_8 = 0;
  puVar1 = *(undefined4 **)(*(int *)(*param_1 + 4) + 0x34 + (int)param_1);
  if (puVar1 == (undefined4 *)0x0) {
    iVar3 = -0x7fffbffb;
  }
  else {
    CComQIPtr<>(&local_1c,puVar1);
    local_8._0_1_ = 1;
    if ((local_1c == (int *)0x0) ||
       ((**(code **)(*local_1c + 0xb4))(local_1c,&local_48), local_48.n2.vt == 0)) {
      iVar3 = -0x7fffbffb;
    }
    else {
      CComQIPtr<>(&local_18,(undefined4 *)local_48._8_4_);
      local_8._0_1_ = 2;
      if (local_18 == (int *)0x0) {
        iVar3 = -0x7fffbffb;
      }
      else {
        local_20 = 0;
        (**(code **)(*local_18 + 0x1c))(local_18,&local_20);
        iVar2 = 0;
        if (0 < local_20) {
          do {
            FUN_45001f8d((uint *)&local_38);
            iVar2 = iVar2 + 1;
            local_8._0_1_ = 3;
            (**(code **)(*local_18 + 0x30))(local_18,iVar2,&local_38);
            if (local_38.n2.vt != 0) {
              CComQIPtr<>(local_14,(undefined4 *)local_38._8_4_);
              local_8._0_1_ = 4;
              if (local_14[0] != (int *)0x0) {
                piVar4 = local_14[0];
                if (local_14[0] != (int *)0x0) {
                  (**(code **)(*local_14[0] + 4))(local_14[0]);
                }
                iVar3 = FUN_4500d13b(local_24,piVar4);
                if (iVar3 < 0) {
                  FUN_4500274d(0x4503f1cc);
                  local_8._0_1_ = 3;
                  if (local_14[0] != (int *)0x0) {
                    (**(code **)(*local_14[0] + 8))(local_14[0]);
                  }
                  VariantClear((VARIANTARG *)&local_38.n2);
                  iVar3 = -0x7fffbffb;
                  goto LAB_45012906;
                }
                local_8._0_1_ = 3;
                if (local_14[0] != (int *)0x0) {
                  (**(code **)(*local_14[0] + 8))(local_14[0]);
                }
              }
            }
            local_8._0_1_ = 2;
            VariantClear((VARIANTARG *)&local_38.n2);
          } while (iVar2 < local_20);
        }
        VariantClear((VARIANTARG *)&local_48.n2);
        FUN_4500aeef(&local_48,0);
      }
LAB_45012906:
      local_8._0_1_ = 1;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  VariantClear((VARIANTARG *)&local_48.n2);
  return iVar3;
}


