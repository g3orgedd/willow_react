// Source: CLCiffConversion_Data.dll @ 45004f58; FUN_45004f58

void FUN_45004f58(int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)*param_1;
  if (piVar1 != (int *)*param_1) {
    do {
      if ((void *)piVar1[2] != (void *)0x0) {
        FUN_45005a15((void *)piVar1[2],1);
      }
      piVar1[2] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*param_1);
  }
  FUN_4501423d(param_1);
  return;
}


