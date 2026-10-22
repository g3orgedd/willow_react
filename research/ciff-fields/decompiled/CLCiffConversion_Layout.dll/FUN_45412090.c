// Source: CLCiffConversion_Layout.dll @ 45412090; FUN_45412090

/* WARNING: Removing unreachable block (ram,0x454120cd) */

void FUN_45412090(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)param_1[1]) {
    do {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = (int *)*piVar2;
      if ((piVar1 != (int *)0x0) && (*piVar2 = 0, piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != (int *)param_1[1]);
  }
  FUN_45421f2e((void *)*param_1,(void *)param_1[1]);
  param_1[1] = *param_1;
  return;
}


