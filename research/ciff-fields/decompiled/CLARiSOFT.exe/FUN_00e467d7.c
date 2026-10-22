// Source: CLARiSOFT.exe @ 00e467d7; FUN_00e467d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __cdecl FUN_00e467d7(int *param_1,BSTR param_2)

{
  BSTR pOVar1;
  int iVar2;
  uint uVar3;
  VARIANTARG local_34;
  _union_2683 local_24;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_2;
  uStack_4 = 0x24;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(**(int **)param_2 + 0x1c))(*(int **)param_2,local_14);
  (**(code **)(**(int **)pOVar1 + 0x20))(*(int **)pOVar1,&param_2);
  FUN_00e03b51((uint *)&local_24);
  local_8._0_1_ = 1;
  (**(code **)(**(int **)pOVar1 + 0x58))(*(int **)pOVar1,&local_24);
  FUN_00e03b51((uint *)&local_34);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_00e4640b(param_1,local_14,&local_34);
  if (-1 < iVar2) {
    uVar3 = FUN_00e46a5e(param_1,(undefined4 *)pOVar1,param_2,&local_34);
    if (-1 < (int)uVar3) goto LAB_00e468c6;
  }
  if ((param_2 == (BSTR)0x2) || (param_2 == (BSTR)0x4)) {
    if (local_24.n2.vt != 8) {
      VariantChangeType((VARIANTARG *)&local_24.n2,(VARIANTARG *)&local_24,0,8);
    }
    uVar3 = 2;
  }
  else {
    if ((param_2 != (BSTR)0x0) && (param_2 != (BSTR)0x1)) {
      uVar3 = 1;
      goto LAB_00e468c6;
    }
    if (local_24.n2.vt != 3) {
      VariantChangeType((VARIANTARG *)&local_24.n2,(VARIANTARG *)&local_24,0,3);
    }
    uVar3 = (uint)(param_2 != (BSTR)0x0);
  }
  uVar3 = FUN_00e4668d(param_1,local_14,uVar3,(LPVARIANT)&local_24.n2);
LAB_00e468c6:
  VariantClear(&local_34);
  VariantClear((VARIANTARG *)&local_24.n2);
  SysFreeString(local_14[0]);
  return uVar3;
}


