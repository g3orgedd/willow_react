// Source: CLARiSOFT.exe @ 00e2f762; FUN_00e2f762

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_00e2f762(int *param_1,undefined4 *param_2,void *param_3)

{
  int *piVar1;
  int iVar2;
  _union_2683 local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0xe2f76e;
  FUN_00e03b51((uint *)&local_20);
  piVar1 = param_1;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x30))((int *)*param_1,*param_2,&local_20);
  if (((iVar2 < 0) || (local_20.n2.vt != 9)) || ((undefined4 *)local_20._8_4_ == (undefined4 *)0x0))
  {
    VariantClear((VARIANTARG *)&local_20.n2);
    iVar2 = (**(code **)(*(int *)*piVar1 + 0x20))((int *)*piVar1,1,&local_20);
    if (((iVar2 < 0) || (local_20.n2.vt != 9)) ||
       ((undefined4 *)local_20._8_4_ == (undefined4 *)0x0)) {
      iVar2 = -0x7fffbffb;
      goto LAB_00e2f81a;
    }
    CComQIPtr<>(&param_1,(undefined4 *)local_20._8_4_);
    if (param_1 == (int *)0x0) goto LAB_00e2f81a;
LAB_00e2f7fa:
    FUN_00e11de5(param_3,(int *)&param_1);
  }
  else {
    CComQIPtr<>(&param_1,(undefined4 *)local_20._8_4_);
    if (param_1 != (int *)0x0) goto LAB_00e2f7fa;
    iVar2 = -0x7fffbffb;
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
LAB_00e2f81a:
  VariantClear((VARIANTARG *)&local_20.n2);
  return iVar2;
}


