// Source: CLCSTextBasedField.dll @ 42468f57; FUN_42468f57

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_42468f57(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *in_stack_0000001c;
  undefined4 *in_stack_0000002c;
  BSTR pOVar6;
  int *piVar7;
  BSTR pOVar8;
  undefined4 local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x42468f63;
  local_18 = this;
  CComQIPtr<>(&local_28,param_3);
  piVar1 = local_28;
  local_8 = 1;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 4))();
  }
  CComQIPtr<>(local_14,piVar1);
  local_8._0_1_ = 2;
  if (local_14[0] != (int *)0x0) {
    SysFreeString(*(BSTR *)((int)this + 0x38));
    *(undefined4 *)((int)this + 0x38) = 0;
    pOVar6 = local_18 + 0x1a;
    SysFreeString(*(BSTR *)pOVar6);
    pOVar8 = local_18;
    pOVar6[0] = L'\0';
    pOVar6[1] = L'\0';
    (**(code **)(*local_14[0] + 0xc0))();
    (**(code **)(*local_14[0] + 200))(local_14[0],pOVar8 + 8);
    (**(code **)(*local_14[0] + 0x54))(local_14[0],pOVar8 + 0x20);
    (**(code **)(*local_14[0] + 0x44))(local_14[0],pOVar8 + 10);
    (**(code **)(*local_14[0] + 0x4c))(local_14[0],pOVar8 + 0xc);
    (**(code **)(*local_14[0] + 0x140))(local_14[0],pOVar8 + 0x1e);
    (**(code **)(*local_14[0] + 0x3c))(local_14[0],pOVar8 + 0x10);
    (**(code **)(*local_14[0] + 0x158))(local_14[0],pOVar8 + 0x12);
    (**(code **)(*local_14[0] + 0x150))(local_14[0],pOVar8 + 0x14);
    (**(code **)(*local_14[0] + 0x134))(local_14[0],pOVar8 + 0xe);
    (**(code **)(*local_14[0] + 0xa8))(local_14[0],pOVar8 + 0x1c);
    (**(code **)(*local_14[0] + 0x98))(local_14[0],pOVar6);
    (**(code **)(*local_14[0] + 0x148))(local_14[0],pOVar8 + 0x18);
  }
  CComQIPtr<>(&local_24,piVar1);
  local_8._0_1_ = 3;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_24 + 0x160))();
  }
  CComQIPtr<>(&local_20,in_stack_0000001c);
  piVar2 = local_20;
  local_8._0_1_ = 5;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 4))();
  }
  CComQIPtr<>(&local_1c,in_stack_0000002c);
  piVar3 = local_1c;
  local_8._0_1_ = 7;
  uVar4 = (undefined1)local_8;
  local_8._0_1_ = 7;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 4))();
    (**(code **)(*piVar3 + 0x54))(piVar3);
    uVar4 = (undefined1)local_8;
    if ((local_2c == 0) && (*(int *)(local_18 + 0x14) != -0x80000000)) {
      FUN_42458671(&local_30);
      local_8._0_1_ = 8;
      piVar7 = piVar2;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))();
      }
      iVar5 = FUN_424589da(*(int *)(local_18 + 0x14),1.4013e-45,piVar7);
      local_8._0_1_ = 7;
      *(int *)(local_18 + 0x14) = iVar5;
      FUN_42458752(&local_30);
      uVar4 = (undefined1)local_8;
    }
  }
  local_8._0_1_ = uVar4;
  pOVar8 = local_18 + 0x14;
  if (*(int *)pOVar8 == -0x80000000) {
    pOVar6 = local_18;
    FUN_42403768(&stack0xffffffa8,(int *)(local_18 + 0x1c));
    FUN_42467f17(local_18,pOVar6,(uint *)pOVar8);
  }
  local_8._0_1_ = 6;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))();
  }
  local_8._0_1_ = 5;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
  local_8._0_1_ = 4;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  local_8._0_1_ = 3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))();
  }
  local_8._0_1_ = 2;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))();
  }
  local_8._0_1_ = 1;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  local_8 = 0xffffffff;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))();
  }
  return;
}


