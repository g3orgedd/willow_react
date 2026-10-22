// Source: CLARiSOFT.exe @ 00e30971; FUN_00e30971

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_00e30971(int param_1)

{
  undefined1 *puVar1;
  HRESULT HVar2;
  code *pcVar3;
  uint local_4c [2];
  undefined4 *local_44;
  VARIANTARG local_3c;
  int local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  puVar1 = &LAB_00eeb849;
  local_8 = 0xe3097d;
  if ((*(int *)(param_1 + 0x160) != 0) && (*(int *)(param_1 + 0x23c) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x23c) + 0x30))
              (*(int **)(param_1 + 0x23c),*(undefined4 *)(param_1 + 0x1c));
    FUN_00e03b51(local_4c);
    local_8 = 0;
    (**(code **)(**(int **)(param_1 + 0x160) + 0x474))(*(int **)(param_1 + 0x160),local_4c);
    CComQIPtr<>(&local_28,local_44);
    local_24 = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*local_28 + 0x24))(local_28,&local_24);
    local_20 = 0;
    pcVar3 = VariantClear_exref;
    if (0 < local_24) {
      do {
        FUN_00e03b51((uint *)&local_3c);
        local_20 = local_20 + 1;
        local_8._0_1_ = 2;
        (**(code **)(*local_28 + 0x20))(local_28,local_20,&local_3c);
        CComQIPtr<>(&local_1c,(undefined4 *)local_3c.n1._8_4_);
        local_18 = (BSTR)0x0;
        local_8._0_1_ = 4;
        (**(code **)(*local_1c + 0x1c))(local_1c,&local_18);
        (**(code **)(**(int **)(param_1 + 0x23c) + 0x24))(*(int **)(param_1 + 0x23c),local_18);
        (**(code **)(*local_1c + 0x5c))(local_1c,&local_2c);
        pcVar3 = VariantClear_exref;
        if (local_2c == 1) {
          local_14[0] = (BSTR)0x0;
          local_8._0_1_ = 5;
          (**(code **)(*local_1c + 100))(local_1c,local_14);
          HVar2 = VarBstrCmp(local_18,local_14[0],0x400,0);
          if (HVar2 != 1) {
            (**(code **)(**(int **)(param_1 + 0x23c) + 0x24))
                      (*(int **)(param_1 + 0x23c),local_14[0]);
          }
          SysFreeString(local_14[0]);
        }
        SysFreeString(local_18);
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        VariantClear(&local_3c);
      } while (local_20 < local_24);
    }
    local_8 = local_8 & 0xffffff00;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
    puVar1 = (undefined1 *)(*pcVar3)(local_4c);
  }
  return puVar1;
}


