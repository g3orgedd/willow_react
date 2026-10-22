// Source: CLCSBarcodeField.dll @ 41428660; FUN_41428660

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_41428660(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  VARIANTARG local_28;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0x18;
  local_8 = 0x4142866c;
  (**(code **)(*(int *)*param_1 + 0xac))((int *)*param_1,*(undefined4 *)((int)this + 0x14));
  param_1 = (int *)0x0;
  local_8 = 0;
  (**(code **)(*(int *)*piVar2 + 0x5c))((int *)*piVar2,&param_1);
  FUN_41460bf0((uint *)&local_28,0,0x10);
  VariantInit(&local_28);
  local_8._0_1_ = 1;
  (**(code **)(*param_1 + 0x28))(param_1,0,1,1,0,&local_28);
  CComQIPtr<>(local_14,(undefined4 *)local_28.n1._8_4_);
  piVar1 = local_14[0];
  local_8._0_1_ = 2;
  puVar3 = FUN_41402f15(&local_18,L"01");
  local_8._0_1_ = 3;
  (**(code **)(*piVar1 + 0x5c))(piVar1,*puVar3);
  local_8._0_1_ = 2;
  SysFreeString(local_18);
  (**(code **)(*local_14[0] + 0x54))(local_14[0],0);
  local_8._0_1_ = 1;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  VariantClear(&local_28);
  FUN_41460bf0((uint *)&local_28,0,0x10);
  VariantInit(&local_28);
  local_8._0_1_ = 4;
  (**(code **)(*param_1 + 0x28))(param_1,0,2,1,0,&local_28);
  CComQIPtr<>(local_14,(undefined4 *)local_28.n1._8_4_);
  piVar1 = local_14[0];
  local_8._0_1_ = 5;
  puVar3 = FUN_41402f15(&local_18,L"05012345123455");
  local_8._0_1_ = 6;
  (**(code **)(*piVar1 + 0x5c))(piVar1,*puVar3);
  local_8._0_1_ = 5;
  SysFreeString(local_18);
  (**(code **)(*local_14[0] + 0x54))(local_14[0],0);
  local_8 = CONCAT31(local_8._1_3_,4);
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  VariantClear(&local_28);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  piVar1 = (int *)*piVar2;
  puVar3 = FUN_41402f15(&local_18,L"OCRB");
  local_8 = 7;
  (**(code **)(*piVar1 + 0xd4))(piVar1,*puVar3);
  local_8 = 0xffffffff;
  SysFreeString(local_18);
  (**(code **)(*(int *)*piVar2 + 0xdc))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0xe4))((int *)*piVar2,0x14);
  (**(code **)(*(int *)*piVar2 + 0x28))((int *)*piVar2,1);
  (**(code **)(*(int *)*piVar2 + 0x48))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x50))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x40))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x58))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x94))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0xcc))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x104))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x10c))((int *)*piVar2,1);
  (**(code **)(*(int *)*piVar2 + 0x11c))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x124))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 300))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0xc4))((int *)*piVar2,1);
  (**(code **)(*(int *)*piVar2 + 0xbc))((int *)*piVar2,0x9c4);
  uVar4 = (**(code **)(*(int *)*piVar2 + 0xb4))((int *)*piVar2,500);
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}


