// Source: CLCSBarcodeField.dll @ 414431c3; FUN_414431c3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_414431c3(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 4;
  local_8 = 0x414431cf;
  (**(code **)(*(int *)*param_1 + 0xac))((int *)*param_1,*(undefined4 *)((int)this + 0x14));
  piVar1 = (int *)*piVar2;
  puVar3 = FUN_41402f15(local_14,L"OCRB");
  local_8 = 0;
  (**(code **)(*piVar1 + 0xd4))(piVar1,*puVar3);
  local_8 = 0xffffffff;
  SysFreeString(local_14[0]);
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
  (**(code **)(*(int *)*piVar2 + 0x10c))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0xf4))((int *)*piVar2,0x205);
  (**(code **)(*(int *)*piVar2 + 0x11c))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 300))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0x124))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0xc4))((int *)*piVar2,0);
  (**(code **)(*(int *)*piVar2 + 0xbc))((int *)*piVar2,0x9c4);
  (**(code **)(*(int *)*piVar2 + 0xb4))((int *)*piVar2,0x294);
  CComQIPtr<>(&param_1,(undefined4 *)*piVar2);
  local_8 = 1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x178))(param_1,2);
    (**(code **)(*param_1 + 0x180))(param_1,3);
    (**(code **)(*param_1 + 0x170))(param_1,3);
    (**(code **)(*param_1 + 400))(param_1,0);
    (**(code **)(*param_1 + 0x188))(param_1,9);
    (**(code **)(*param_1 + 0x160))(param_1,0x32);
  }
  local_8 = 0xffffffff;
  uVar4 = 0;
  if (param_1 != (int *)0x0) {
    uVar4 = (**(code **)(*param_1 + 8))(param_1);
  }
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}


