// Source: CLCiffConversion_Layout.dll @ 45412128; FUN_45412128

void FUN_45412128(int *param_1)

{
  int *_Memory;
  int *piVar1;
  
  piVar1 = *(int **)*param_1;
  if (piVar1 != (int *)*param_1) {
    do {
      _Memory = (int *)piVar1[2];
      if (_Memory != (int *)0x0) {
        FUN_45412f4b(_Memory);
        FID_conflict__free(_Memory);
      }
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  FUN_454224ff(param_1);
  return;
}


