// Source: CLCSBarcodeField.dll @ 414424ac; FUN_414424ac

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_414424ac(int *param_1,undefined4 *param_2,BSTR param_3,undefined4 *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  BSTR pOVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  undefined4 **ppuVar14;
  undefined4 local_44 [2];
  undefined4 local_3c;
  int local_38;
  int local_34 [8];
  float local_14;
  int local_8;
  undefined4 uStack_4;
  
  puVar3 = param_4;
  piVar2 = param_1;
  uStack_4 = 0x38;
  local_8 = 0x414424b8;
  (**(code **)(*(int *)*param_4 + 0x78))();
  piVar1 = piVar2 + 1;
  (**(code **)(*(int *)*puVar3 + 0x80))();
  if (*piVar2 == 0) {
    *piVar2 = 1;
  }
  if (*piVar1 == 0) {
    *piVar1 = 1;
  }
  local_34[1] = 1;
  (**(code **)(*(int *)*param_2 + 0x54))();
  pOVar5 = param_3;
  local_14 = 0.0;
  (**(code **)(**(int **)param_3 + 0x2c))();
  local_34[2] = FUN_414426fc((double)local_14 * _DAT_41484218);
  (**(code **)(**(int **)pOVar5 + 0x34))();
  CComQIPtr<>(&param_1,(undefined4 *)*param_4);
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    FUN_4144c328(local_44);
    local_34[6] = 0;
    local_8._0_1_ = 1;
    (**(code **)(*param_1 + 0x18c))();
    (**(code **)(*param_1 + 0x184))();
    local_34[4] = 0;
    (**(code **)(*param_1 + 0x174))();
    local_34[5] = 0;
    (**(code **)(*param_1 + 0x17c))();
    param_3 = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(*param_1 + 0x98))();
    local_34[7] = 0;
    (**(code **)(*param_1 + 0x16c))();
    local_34[3] = 0;
    (**(code **)(*param_1 + 0x108))(param_1,local_34 + 3);
    param_4 = (undefined4 *)0x0;
    (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,local_34);
    (**(code **)(*param_1 + 0x15c))(param_1,&param_4);
    if (local_34[0] == 0) {
      param_4 = (undefined4 *)(((int)param_4 * local_34[2] + 5000) / 10000);
    }
    if ((int)param_4 < 1) {
      param_4 = (undefined4 *)0x1;
    }
    ppuVar14 = &param_2;
    piVar13 = local_34 + 2;
    local_38 = 0;
    piVar12 = &local_38;
    local_34[2] = 0;
    param_2 = (undefined4 *)0x0;
    uVar10 = 0;
    uVar4 = (uint)(local_34[3] == 1);
    uVar6 = 0;
    pOVar5 = (BSTR)0x0;
    iVar7 = local_34[4];
    iVar8 = local_34[5];
    iVar9 = local_34[6];
    iVar11 = local_34[7];
    FUN_41402eab(&stack0xffffff50,(int *)&param_3);
    FUN_41442e16(pOVar5,uVar6,uVar4,iVar7,iVar8,local_3c,iVar9,uVar10,iVar11,piVar12,piVar13,
                 (int *)ppuVar14);
    *piVar2 = (int)param_2 * (int)param_4;
    *piVar1 = local_34[2] * (int)param_4;
    SysFreeString(param_3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_4144c348(local_44);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  return 0;
}


