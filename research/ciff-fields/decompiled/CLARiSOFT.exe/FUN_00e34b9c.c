// Source: CLARiSOFT.exe @ 00e34b9c; FUN_00e34b9c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_00e34b9c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  _union_2683 local_64;
  _union_2683 local_54;
  _union_2683 local_44;
  int local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0xe34ba8;
  local_24 = 0;
  local_34 = param_1;
  (**(code **)(**(int **)(param_1 + 0x19c) + 0x1c))(*(int **)(param_1 + 0x19c),&local_24);
  iVar1 = 0;
  if (0 < local_24) {
    do {
      FUN_00e03b51((uint *)&local_64);
      local_8 = 0;
      iVar1 = iVar1 + 1;
      (**(code **)(**(int **)(param_1 + 0x19c) + 0x24))(*(int **)(param_1 + 0x19c),iVar1,&local_64);
      if (local_64.n2.vt != 0) {
        CComQIPtr<>(&local_20,(undefined4 *)local_64._8_4_);
        local_8._0_1_ = 1;
        (**(code **)(*local_20 + 0x1c))(local_20,&local_30);
        iVar2 = 0;
        if (0 < local_30) {
          do {
            FUN_00e03b51((uint *)&local_54);
            iVar2 = iVar2 + 1;
            local_8._0_1_ = 2;
            (**(code **)(*local_20 + 0x24))(local_20,iVar2,&local_54);
            if (local_54.n2.vt != 0) {
              CComQIPtr<>(&local_2c,(undefined4 *)local_54._8_4_);
              local_18 = (int *)0x0;
              local_8._0_1_ = 4;
              (**(code **)(*local_2c + 0x5c))(local_2c,&local_18);
              local_1c = 0;
              (**(code **)(*local_18 + 0x1c))(local_18,&local_1c);
              iVar3 = 0;
              if (0 < local_1c) {
                do {
                  FUN_00e03b51((uint *)&local_44);
                  iVar3 = iVar3 + 1;
                  local_8._0_1_ = 5;
                  (**(code **)(*local_18 + 0x24))(local_18,iVar3,&local_44);
                  if (local_44.n2.vt != 0) {
                    CComQIPtr<>(local_14,(undefined4 *)local_44._8_4_);
                    local_8._0_1_ = 6;
                    if (local_14[0] != (int *)0x0) {
                      local_28 = 0;
                      (**(code **)(*local_14[0] + 0x28))(local_14[0],&local_28);
                      if (local_28 == 5) {
                        (**(code **)(*local_14[0] + 0x184))(local_14[0],0);
                      }
                    }
                    local_8._0_1_ = 5;
                    if (local_14[0] != (int *)0x0) {
                      (**(code **)(*local_14[0] + 8))(local_14[0]);
                    }
                  }
                  VariantClear((VARIANTARG *)&local_44.n2);
                } while (iVar3 < local_1c);
              }
              local_8._0_1_ = 3;
              if (local_18 != (int *)0x0) {
                (**(code **)(*local_18 + 8))(local_18);
              }
              local_8._0_1_ = 2;
              if (local_2c != (int *)0x0) {
                (**(code **)(*local_2c + 8))(local_2c);
              }
            }
            VariantClear((VARIANTARG *)&local_54.n2);
          } while (iVar2 < local_30);
        }
        local_8 = (uint)local_8._1_3_ << 8;
        param_1 = local_34;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
          param_1 = local_34;
        }
      }
      local_8 = 0xffffffff;
      VariantClear((VARIANTARG *)&local_64.n2);
    } while (iVar1 < local_24);
  }
  return;
}


