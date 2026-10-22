// Source: CLCiffConversion_Data.dll @ 45004f24; FUN_45004f24

void FUN_45004f24(int *param_1)

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
  FUN_4501423d(param_1);
  return;
}


