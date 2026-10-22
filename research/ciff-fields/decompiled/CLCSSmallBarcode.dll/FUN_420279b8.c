// Source: CLCSSmallBarcode.dll @ 420279b8; FUN_420279b8

undefined4 __fastcall FUN_420279b8(int param_1)

{
  int *piVar1;
  undefined4 in_EAX;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 4) = 0;
    in_EAX = (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    in_EAX = (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    in_EAX = (**(code **)(*piVar1 + 8))(piVar1);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}


