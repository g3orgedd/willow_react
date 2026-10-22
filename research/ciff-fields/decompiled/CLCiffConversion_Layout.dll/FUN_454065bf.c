// Source: CLCiffConversion_Layout.dll @ 454065bf; FUN_454065bf

void FUN_454065bf(int *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)*param_1;
  if (piVar2 != (int *)*param_1) {
    do {
      piVar1 = (int *)piVar2[2];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar2[2] = 0;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*param_1);
  }
  FUN_454224ff(param_1);
  return;
}


