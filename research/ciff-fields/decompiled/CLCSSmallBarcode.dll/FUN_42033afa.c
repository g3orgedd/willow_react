// Source: CLCSSmallBarcode.dll @ 42033afa; FUN_42033afa

undefined4 __thiscall FUN_42033afa(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x20))();
  *param_1 = uVar1;
  uVar1 = (**(code **)(*(int *)this + 0x1c))();
  param_1[1] = uVar1;
  return 0;
}


