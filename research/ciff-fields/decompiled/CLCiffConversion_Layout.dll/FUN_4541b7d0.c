// Source: CLCiffConversion_Layout.dll @ 4541b7d0; FUN_4541b7d0

void __fastcall FUN_4541b7d0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


