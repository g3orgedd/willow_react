// Source: CLCiffConversion_Layout.dll @ 4541613b; FUN_4541613b

void __fastcall FUN_4541613b(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x3c))(piVar1);
    piVar1 = *(int **)(param_1 + 0x20);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *(int **)(param_1 + 0x20);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x20) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined1 *)(param_1 + 0x1c) = 0;
    puVar2 = (undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x14) = 0;
    if (7 < *(uint *)(param_1 + 0x18)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    *(undefined2 *)puVar2 = 0;
  }
  return;
}


