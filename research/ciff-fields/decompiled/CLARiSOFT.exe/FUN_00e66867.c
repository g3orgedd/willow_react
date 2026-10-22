// Source: CLARiSOFT.exe @ 00e66867; FUN_00e66867

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_00e66867(void *param_1)

{
  int iVar1;
  UINT UVar2;
  BSTR extraout_ECX;
  int *piVar3;
  BSTR pOVar4;
  _union_2683 local_5c;
  _union_2683 local_4c;
  _union_2683 local_3c;
  int *local_28;
  int *local_24;
  BSTR local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_1c = (int *)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(**(int **)((int)param_1 + 0x38) + 0x20))();
  if ((-1 < iVar1) && (local_1c != (int *)0x0)) {
    local_20 = (BSTR)0x0;
    local_8._0_1_ = 1;
    (**(code **)(**(int **)((int)param_1 + 0x18) + 0x9c))(*(int **)((int)param_1 + 0x18));
    local_18 = (BSTR)0x0;
    local_8._0_1_ = 2;
    iVar1 = (**(code **)(**(int **)((int)param_1 + 0x18) + 0x4c))
                      (*(int **)((int)param_1 + 0x18),&local_18);
    if ((-1 < iVar1) &&
       ((UVar2 = SysStringLen(local_20), UVar2 != 0 && (UVar2 = SysStringLen(local_18), UVar2 != 0))
       )) {
      FUN_00e03b51((uint *)&local_5c);
      local_8._0_1_ = 3;
      iVar1 = (**(code **)(*local_1c + 0x3c))(local_1c);
      if ((-1 < iVar1) && (local_5c.n2.vt == 9)) {
        CComQIPtr<>(&local_28,(undefined4 *)local_5c._8_4_);
        if (local_28 != (int *)0x0) {
          FUN_00e03b51((uint *)&local_4c);
          local_8._0_1_ = 5;
          iVar1 = (**(code **)(*local_28 + 0x30))(local_28,local_20);
          if ((-1 < iVar1) && (local_4c.n2.vt == 9)) {
            CComQIPtr<>(local_14,(undefined4 *)local_4c._8_4_);
            local_8._0_1_ = 6;
            if (local_14[0] != (int *)0x0) {
              pOVar4 = extraout_ECX;
              FUN_00e03ab8(&stack0xffffff84,(int *)&local_18);
              piVar3 = local_14[0];
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 4))(local_14[0]);
              }
              iVar1 = FUN_00e66def(param_1,piVar3,pOVar4);
              if (-1 < iVar1) {
                FUN_00e03b51((uint *)&local_3c);
                local_8._0_1_ = 7;
                iVar1 = (**(code **)(*local_14[0] + 0x4c0))(local_14[0],local_18);
                if ((((-1 < iVar1) && (local_3c.n2.vt == 9)) &&
                    ((undefined4 *)local_3c._8_4_ != (undefined4 *)0x0)) &&
                   ((CComQIPtr<>(&local_24,(undefined4 *)local_3c._8_4_), local_24 != (int *)0x0 &&
                    (FUN_00e11de5((void *)((int)param_1 + 0x24),(int *)&local_24),
                    local_24 != (int *)0x0)))) {
                  (**(code **)(*local_24 + 8))();
                }
                piVar3 = *(int **)((int)param_1 + 0x1c);
                if (piVar3 != (int *)0x0) {
                  (**(code **)(*piVar3 + 4))(piVar3);
                }
                FUN_00e667a4(param_1,piVar3);
                VariantClear((VARIANTARG *)&local_3c.n2);
              }
            }
            local_8._0_1_ = 5;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))();
            }
          }
          VariantClear((VARIANTARG *)&local_4c.n2);
        }
        local_8._0_1_ = 3;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))();
        }
      }
      VariantClear((VARIANTARG *)&local_5c.n2);
    }
    SysFreeString(local_18);
    SysFreeString(local_20);
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))();
  }
  return iVar1;
}


