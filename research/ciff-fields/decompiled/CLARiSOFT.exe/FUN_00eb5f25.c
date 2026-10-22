// Source: CLARiSOFT.exe @ 00eb5f25; FUN_00eb5f25

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00eb5f25(int *param_1)

{
  int iVar1;
  int *piVar2;
  _union_2683 local_24;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  piVar2 = (int *)0x0;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    FUN_00e03b51((uint *)&local_24);
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = (**(code **)(*param_1 + 0x470))(param_1,&local_24);
    if (((-1 < iVar1) && (local_24.n2.vt == 9)) &&
       ((undefined4 *)local_24._8_4_ != (undefined4 *)0x0)) {
      CComQIPtr<>(local_14,(undefined4 *)local_24._8_4_);
      piVar2 = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    VariantClear((VARIANTARG *)&local_24.n2);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return piVar2;
}


