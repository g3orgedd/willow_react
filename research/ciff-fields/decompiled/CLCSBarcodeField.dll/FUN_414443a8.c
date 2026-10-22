// Source: CLCSBarcodeField.dll @ 414443a8; FUN_414443a8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_414443a8(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  VARIANTARG local_2c;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x1c;
  local_8 = 0x414443b4;
  (**(code **)(*(int *)*param_1 + 0x6c))((int *)*param_1,L"Barcode");
  (**(code **)(*(int *)*piVar1 + 0xac))((int *)*piVar1,*(undefined4 *)((int)this + 0x40));
  param_1 = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*piVar1 + 0x5c))((int *)*piVar1,&param_1);
  if ((-1 < iVar3) && (param_1 != (int *)0x0)) {
    FUN_41460bf0((uint *)&local_2c,0,0x10);
    VariantInit(&local_2c);
    local_8._0_1_ = 1;
    (**(code **)(*param_1 + 0x28))(param_1,0,1,1,0,&local_2c);
    CComQIPtr<>(local_14,(undefined4 *)local_2c.n1._8_4_);
    piVar2 = local_14[0];
    local_8._0_1_ = 2;
    puVar4 = FUN_41402f15(&local_1c,L"01");
    local_8._0_1_ = 3;
    (**(code **)(*piVar2 + 0x5c))(piVar2,*puVar4);
    local_8._0_1_ = 2;
    SysFreeString(local_1c);
    (**(code **)(*local_14[0] + 0x54))(local_14[0],0);
    local_8._0_1_ = 1;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    VariantClear(&local_2c);
    FUN_41460bf0((uint *)&local_2c,0,0x10);
    VariantInit(&local_2c);
    local_8._0_1_ = 4;
    (**(code **)(*param_1 + 0x28))(param_1,0,2,1,0,&local_2c);
    CComQIPtr<>(local_14,(undefined4 *)local_2c.n1._8_4_);
    piVar2 = local_14[0];
    local_8._0_1_ = 5;
    puVar4 = FUN_41402f15(&local_1c,L"05012345123455");
    local_8._0_1_ = 6;
    (**(code **)(*piVar2 + 0x5c))(piVar2,*puVar4);
    local_8._0_1_ = 5;
    SysFreeString(local_1c);
    (**(code **)(*local_14[0] + 0x54))(local_14[0],0);
    local_8._0_1_ = 4;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    VariantClear(&local_2c);
  }
  (**(code **)(*(int *)*piVar1 + 0x114))((int *)*piVar1,0);
  (**(code **)(*(int *)*piVar1 + 0x11c))((int *)*piVar1,0);
  (**(code **)(*(int *)*piVar1 + 0x124))((int *)*piVar1,0);
  (**(code **)(*(int *)*piVar1 + 300))((int *)*piVar1,0);
  CComQIPtr<>(&local_18,(undefined4 *)*piVar1);
  local_8._0_1_ = 7;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 0x178))(local_18,4);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  uVar5 = 0;
  if (local_18 != (int *)0x0) {
    uVar5 = (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    uVar5 = (**(code **)(*param_1 + 8))(param_1);
  }
  return CONCAT31((int3)((uint)uVar5 >> 8),1);
}


