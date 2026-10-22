// Source: CLARiSOFT.exe @ 00e2e920; FUN_00e2e920

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_00e2e920(void *this,BSTR param_1,OLECHAR *param_2)

{
  int iVar1;
  int *piVar2;
  _union_2683 local_28;
  int *local_18;
  int *local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 1;
  uStack_7 = 0;
  iVar1 = FUN_00e050e5(*(void **)((int)this + 0x1e4),param_2);
  if (iVar1 != 0) {
    FUN_00e03b51((uint *)&local_28);
    local_8 = 2;
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x30) + 0x470))(*(int **)(iVar1 + 0x30),&local_28);
    if (((-1 < iVar1) && (local_28.n2.vt == 9)) &&
       ((undefined4 *)local_28._8_4_ != (undefined4 *)0x0)) {
      CComQIPtr<>(local_14,(undefined4 *)local_28._8_4_);
      if (local_14[0] != (int *)0x0) {
        local_18 = (int *)0x0;
        local_8 = 4;
        FUN_00e2f762((int *)local_14,&param_1,&local_18);
        piVar2 = local_18;
        local_8 = 3;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        local_8 = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        VariantClear((VARIANTARG *)&local_28.n2);
        goto LAB_00e2e9e2;
      }
    }
    VariantClear((VARIANTARG *)&local_28.n2);
  }
  piVar2 = (int *)0x0;
LAB_00e2e9e2:
  SysFreeString(param_1);
  SysFreeString(param_2);
  return piVar2;
}


