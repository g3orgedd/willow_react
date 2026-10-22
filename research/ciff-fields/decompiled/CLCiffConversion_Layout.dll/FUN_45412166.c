// Source: CLCiffConversion_Layout.dll @ 45412166; FUN_45412166

void FUN_45412166(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)*param_1;
  if (piVar1 != (int *)*param_1) {
    do {
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  FUN_454224ff(param_1);
  return;
}


