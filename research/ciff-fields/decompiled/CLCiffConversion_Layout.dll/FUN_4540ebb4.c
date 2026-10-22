// Source: CLCiffConversion_Layout.dll @ 4540ebb4; FUN_4540ebb4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540ebb4(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *in_stack_0000001c;
  undefined4 *in_stack_0000002c;
  BSTR pOVar7;
  int *piVar8;
  BSTR pOVar9;
  undefined4 local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  void *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x4540ebc0;
  local_18 = this;
  CComQIPtr<>(&local_34,param_3);
  local_8 = 0;
  local_1c = (int *)0x0;
  FUN_4541a358(&local_34,(int *)&local_1c);
  piVar3 = local_1c;
  CComQIPtr<>(local_14,local_1c);
  local_8._0_1_ = 2;
  if (local_14[0] != (int *)0x0) {
    SysFreeString(*(BSTR *)((int)this + 0x38));
    *(undefined4 *)((int)this + 0x38) = 0;
    puVar6 = (undefined4 *)((int)local_18 + 0x34);
    SysFreeString((BSTR)*puVar6);
    pvVar4 = local_18;
    *puVar6 = 0;
    (**(code **)(*local_14[0] + 0xc0))();
    (**(code **)(*local_14[0] + 200))(local_14[0],(int)pvVar4 + 0x10);
    (**(code **)(*local_14[0] + 0x54))(local_14[0],(int)pvVar4 + 0x40);
    (**(code **)(*local_14[0] + 0x44))(local_14[0],(int)pvVar4 + 0x14);
    (**(code **)(*local_14[0] + 0x4c))(local_14[0],(int)pvVar4 + 0x18);
    (**(code **)(*local_14[0] + 0x140))(local_14[0],(int)pvVar4 + 0x3c);
    (**(code **)(*local_14[0] + 0x3c))(local_14[0],(int)pvVar4 + 0x20);
    (**(code **)(*local_14[0] + 0x158))(local_14[0],(int)pvVar4 + 0x24);
    (**(code **)(*local_14[0] + 0x150))(local_14[0],(int)pvVar4 + 0x28);
    (**(code **)(*local_14[0] + 0x134))(local_14[0],(int)pvVar4 + 0x1c);
    (**(code **)(*local_14[0] + 0xa8))(local_14[0],(int)pvVar4 + 0x38);
    (**(code **)(*local_14[0] + 0x98))(local_14[0],puVar6);
    (**(code **)(*local_14[0] + 0x148))(local_14[0],(int)pvVar4 + 0x30);
  }
  CComQIPtr<>(&local_30,piVar3);
  local_8._0_1_ = 3;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_30 + 0x160))();
  }
  local_24 = (int *)0x0;
  CComQIPtr<>(&local_2c,in_stack_0000001c);
  FUN_4541a358(&local_2c,(int *)&local_24);
  local_20 = (int *)0x0;
  CComQIPtr<>(&local_28,in_stack_0000002c);
  local_8._0_1_ = 7;
  FUN_4541a358(&local_28,(int *)&local_20);
  piVar2 = local_20;
  piVar1 = local_24;
  if (((local_20 != (int *)0x0) && ((**(code **)(*local_20 + 0x54))(), local_38 == 0)) &&
     (*(int *)((int)local_18 + 0x28) != -0x80000000)) {
    FUN_45402881(&local_3c);
    local_8._0_1_ = 8;
    piVar8 = piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
    }
    iVar5 = FUN_454035df(*(int *)((int)local_18 + 0x28),1.4013e-45,piVar8);
    local_8._0_1_ = 7;
    *(int *)((int)local_18 + 0x28) = iVar5;
    FUN_45402c42(&local_3c);
  }
  pOVar7 = (BSTR)((int)local_18 + 0x28);
  if (*(int *)pOVar7 == -0x80000000) {
    pOVar9 = pOVar7;
    FUN_4540288a(&stack0xffffffa8,(int *)((int)local_18 + 0x38));
    FUN_4540e6d9(local_18,pOVar7,(uint *)pOVar9);
  }
  local_8._0_1_ = 6;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))();
  }
  local_8._0_1_ = 5;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))();
  }
  local_8._0_1_ = 4;
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))();
  }
  local_8._0_1_ = 3;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  local_8._0_1_ = 2;
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))();
  }
  local_8._0_1_ = 1;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
  local_8 = 0xffffffff;
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))();
  }
  return;
}


