// Source: CLCiffConversion_Layout.dll @ 454065f3; FUN_454065f3

void FUN_454065f3(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)*param_1;
  if (piVar1 != (int *)*param_1) {
    do {
      if ((void *)piVar1[2] != (void *)0x0) {
        FUN_45406766((void *)piVar1[2],1);
      }
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  FUN_454224ff(param_1);
  return;
}


