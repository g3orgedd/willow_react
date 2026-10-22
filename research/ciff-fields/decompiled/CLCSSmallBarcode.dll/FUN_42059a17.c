// Source: CLCSSmallBarcode.dll @ 42059a17; FUN_42059a17

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_42059a17(int *param_1,undefined4 *param_2,int *param_3,BSTR param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  BSTR pOVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  undefined4 local_44 [2];
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  float local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x42059a23;
  FUN_42002e41(local_44);
  pOVar5 = param_4;
  piVar2 = param_1;
  local_8 = 0;
  piVar1 = param_1 + 1;
  (**(code **)(**(int **)param_4 + 0x80))();
  (**(code **)(**(int **)pOVar5 + 0x78))();
  if (*piVar1 == 0) {
    *piVar1 = 1;
  }
  if (*piVar2 == 0) {
    *piVar2 = 1;
  }
  local_1c = 1;
  (**(code **)(*(int *)*param_2 + 0x54))();
  if (local_1c == 0) {
    piVar13 = (int *)*param_3;
    if (piVar13 != (int *)0x0) {
      (**(code **)(*piVar13 + 4))();
    }
    iVar3 = FUN_42003ac3(*piVar1,0.0,piVar13);
    *piVar1 = iVar3;
  }
  else {
    (**(code **)(**(int **)pOVar5 + 0x80))();
  }
  (**(code **)(**(int **)pOVar5 + 0xb0))();
  local_18 = 0.0;
  (**(code **)(*(int *)*param_3 + 0x2c))();
  local_30 = (int)((double)(local_18 * _DAT_42093e98) + _DAT_42093e80);
  (**(code **)(*(int *)*param_3 + 0x34))();
  CComQIPtr<>(local_14,*(undefined4 **)pOVar5);
  local_8._0_1_ = 1;
  if (local_14[0] != (int *)0x0) {
    param_2 = (undefined4 *)0x0;
    (**(code **)(*local_14[0] + 0x18c))();
    (**(code **)(*local_14[0] + 0x184))();
    (**(code **)(*local_14[0] + 0x194))();
    local_24 = 0;
    (**(code **)(*local_14[0] + 0x174))();
    local_20 = 0;
    (**(code **)(*local_14[0] + 0x17c))();
    param_4 = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(*local_14[0] + 0x98))();
    param_1 = (int *)0x0;
    (**(code **)(*local_14[0] + 0x16c))(local_14[0],&param_1);
    param_3 = (int *)0x0;
    (**(code **)(*local_14[0] + 0x15c))(local_14[0],&param_3);
    if (local_1c == 0) {
      param_3 = (int *)(((int)param_3 * local_30 + 5000) / 10000);
    }
    local_28 = 1;
    if ((int)param_3 < 1) {
      param_3 = (int *)0x1;
    }
    (**(code **)(**(int **)pOVar5 + 0x108))(*(int **)pOVar5,&local_28);
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    piVar13 = &local_2c;
    piVar12 = &local_30;
    piVar11 = &local_34;
    uVar4 = (uint)(local_28 == 1);
    uVar6 = 1;
    pOVar5 = (BSTR)0x1;
    uVar7 = local_24;
    uVar8 = local_20;
    puVar9 = param_2;
    piVar10 = param_1;
    FUN_42002e4a(&stack0xffffff44,(int *)&param_4);
    FUN_42059ea5(pOVar5,uVar6,uVar4,uVar7,uVar8,local_3c,puVar9,local_38,(int)piVar10,piVar11,
                 piVar12,piVar13);
    *piVar2 = local_2c * (int)param_3;
    *piVar1 = local_30 * (int)param_3;
    SysFreeString(param_4);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  local_8 = 0xffffffff;
  FUN_420030e8(local_44);
  return 0;
}


