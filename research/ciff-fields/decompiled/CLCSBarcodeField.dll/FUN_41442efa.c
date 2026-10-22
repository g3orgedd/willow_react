// Source: CLCSBarcodeField.dll @ 41442efa; FUN_41442efa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_41442efa(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  BSTR pOVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  BSTR local_1c;
  int local_18;
  float local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar12 = param_3;
  uStack_4 = 0x30;
  local_8 = 0x41442f06;
  local_14 = 0.0;
  local_30 = param_1[2] - *param_1;
  iVar4 = param_1[3] - param_1[1];
  (**(code **)(*(int *)*param_3 + 0x2c))();
  iVar1 = FUN_414426b9(local_14 * _DAT_41481060);
  (**(code **)(*(int *)*puVar12 + 0x34))();
  iVar2 = FUN_414426b9(local_14 * _DAT_41481060);
  (**(code **)(*(int *)*param_2 + 0x54))();
  iVar13 = local_30;
  if (local_34 == 0) {
    iVar4 = (iVar2 * iVar4 + 5000) / 10000;
    iVar13 = (iVar1 * local_30 + 5000) / 10000;
  }
  CComQIPtr<>(&param_1,(undefined4 *)*param_4);
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    local_24 = 0;
    (**(code **)(*param_1 + 0x18c))();
    (**(code **)(*param_1 + 0x184))();
    local_2c = 0;
    (**(code **)(*param_1 + 0x174))();
    local_28 = 0;
    (**(code **)(*param_1 + 0x17c))();
    local_1c = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*param_1 + 0x98))();
    param_2 = (undefined4 *)0x0;
    (**(code **)(*param_1 + 0x16c))();
    param_3 = (undefined4 *)0x0;
    (**(code **)(*param_1 + 0x15c))();
    if (local_34 == 0) {
      param_3 = (undefined4 *)(((int)param_3 * iVar1 + 5000) / 10000);
    }
    param_4 = (undefined4 *)0x0;
    (**(code **)(*param_1 + 0x108))();
    if ((int)param_3 < 1) {
      param_3 = (undefined4 *)0x1;
    }
    piVar16 = &local_20;
    piVar15 = &local_30;
    local_18 = 0;
    piVar14 = &local_18;
    local_30 = 0;
    local_20 = 0;
    uVar11 = 0;
    uVar3 = (uint)(param_4 == (undefined4 *)0x1);
    uVar6 = 0;
    pOVar5 = (BSTR)0x0;
    uVar8 = local_2c;
    uVar9 = local_28;
    uVar10 = local_38;
    uVar7 = local_24;
    puVar12 = param_2;
    FUN_41402eab(&stack0xffffff28,(int *)&local_1c);
    FUN_41442e16(pOVar5,uVar6,uVar3,uVar8,uVar9,uVar10,uVar7,uVar11,(int)puVar12,piVar14,piVar15,
                 piVar16);
    param_2 = (undefined4 *)0x1;
    param_3 = (undefined4 *)(iVar13 / local_20);
    if (iVar13 / local_20 < 1) {
      param_3 = (undefined4 *)0x1;
    }
    piVar16 = &local_20;
    piVar15 = &local_30;
    piVar14 = &local_18;
    iVar13 = 1;
    uVar6 = 0;
    uVar3 = (uint)(param_4 == (undefined4 *)0x1);
    uVar7 = 0;
    pOVar5 = (BSTR)0x1;
    uVar8 = local_2c;
    uVar9 = local_28;
    uVar10 = local_24;
    FUN_41402eab(&stack0xffffff28,(int *)&local_1c);
    FUN_41442e16(pOVar5,uVar7,uVar3,uVar8,uVar9,local_38,uVar10,uVar6,iVar13,piVar14,piVar15,piVar16
                );
    iVar13 = local_18;
    if (param_4 != (undefined4 *)0x0) {
      iVar13 = local_18 + -2;
    }
    iVar13 = local_30 - iVar13 * (int)param_2;
    param_2 = (undefined4 *)((iVar4 - iVar13 * (int)param_3) / ((local_30 - iVar13) * (int)param_3))
    ;
    if ((int)param_2 < 1) {
      param_2 = (undefined4 *)0x1;
    }
    if (10 < (int)param_2) {
      param_2 = (undefined4 *)0xa;
    }
    if (local_34 == 0) {
      param_3 = (undefined4 *)((iVar1 / 2 + (int)param_3 * 10000) / iVar1);
    }
    (**(code **)(*param_1 + 0x170))();
    (**(code **)(*param_1 + 0x160))();
    SysFreeString(local_1c);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  return 0;
}


