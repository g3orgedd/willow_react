// Source: CiffHelper.dll @ 4080e73f; FUN_4080e73f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

BSTR __cdecl FUN_4080e73f(BSTR param_1,int *param_2,int *param_3)

{
  bool bVar1;
  BSTR pOVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined1 local_20 [24];
  uint local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_1;
  uStack_4 = 0x10;
  bVar1 = false;
  local_8 = 1;
  param_1[2] = L'\0';
  param_1[3] = L'\0';
  param_1[0] = L'\0';
  param_1[1] = L'\0';
  if (param_2 != (int *)0x0) {
    FUN_40802e76((uint *)local_20);
    local_8._0_1_ = 2;
    FUN_40802e40(&param_1,L"StartOfDay");
    local_8._0_1_ = 3;
    iVar3 = FUN_40808052((int *)&param_2,&param_1,(VARIANTARG *)&((_union_2683 *)local_20)->n2);
    SysFreeString(param_1);
    if ((-1 < iVar3) && (local_20._0_2_ == 3)) {
      if (0x1517f < (int)local_20._8_4_) {
        local_20._8_4_ = 0x1517f;
      }
      if ((int)local_20._8_4_ < -0x1517f) {
        local_20._8_4_ = -0x1517f;
      }
      bVar1 = true;
      *(undefined4 *)pOVar2 = local_20._8_4_;
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_20)->n2);
    local_8 = CONCAT31(local_8._1_3_,1);
    VariantClear((VARIANTARG *)&((_union_2683 *)local_20)->n2);
    if (bVar1) goto LAB_4080e811;
  }
  piVar5 = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  puVar4 = FUN_4081660d(&(((_union_2683 *)local_20)->n2).n3.lVal,piVar5);
  *(undefined4 *)pOVar2 = *puVar4;
  *(undefined4 *)(pOVar2 + 2) = puVar4[1];
LAB_4080e811:
  local_8 = local_8 & 0xffffff00;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return pOVar2;
}


