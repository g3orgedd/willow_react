// Source: CLCSBarcodeField.dll @ 4144b05d; FUN_4144b05d

undefined4 __fastcall FUN_4144b05d(int param_1)

{
  int *piVar1;
  undefined4 in_EAX;
  
  piVar1 = *(int **)(param_1 + 0xf4);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0xf4) = 0;
    in_EAX = (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xf8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0xf8) = 0;
    in_EAX = (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xfc);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0xfc) = 0;
    in_EAX = (**(code **)(*piVar1 + 8))(piVar1);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}


