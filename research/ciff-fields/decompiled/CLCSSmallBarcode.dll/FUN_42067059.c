// Source: CLCSSmallBarcode.dll @ 42067059; FUN_42067059

undefined4 __thiscall FUN_42067059(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)*param_1 + 0xac))((int *)*param_1,*(undefined4 *)((int)this + 0x14));
  (**(code **)(*(int *)*param_1 + 0xf4))((int *)*param_1,0x205);
  (**(code **)(*(int *)*param_1 + 0x114))((int *)*param_1,1);
  (**(code **)(*(int *)*param_1 + 0x11c))((int *)*param_1,0);
  (**(code **)(*(int *)*param_1 + 0x124))((int *)*param_1,0);
  uVar1 = (**(code **)(*(int *)*param_1 + 300))((int *)*param_1,0);
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


