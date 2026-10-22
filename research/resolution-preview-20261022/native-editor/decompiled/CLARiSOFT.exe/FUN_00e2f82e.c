// Source: CLARiSOFT.exe @ 00e2f82e; FUN_00e2f82e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __fastcall FUN_00e2f82e(int param_1)

{
  int iVar1;
  _union_2683 local_24;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0xe2f83a;
  if (*(int *)(param_1 + 0x160) != 0) {
    FUN_00e03b51((uint *)&local_24);
    local_8 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x160) + 0x470))(*(int **)(param_1 + 0x160),&local_24)
    ;
    if (((-1 < iVar1) && (local_24.n2.vt == 9)) &&
       ((undefined4 *)local_24._8_4_ != (undefined4 *)0x0)) {
      CComQIPtr<>(local_14,(undefined4 *)local_24._8_4_);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      VariantClear((VARIANTARG *)&local_24.n2);
      return local_14[0];
    }
    VariantClear((VARIANTARG *)&local_24.n2);
  }
  return (int *)0x0;
}


