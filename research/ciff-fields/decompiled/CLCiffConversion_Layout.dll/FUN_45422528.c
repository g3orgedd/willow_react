// Source: CLCiffConversion_Layout.dll @ 45422528; FUN_45422528

void FUN_45422528(int *param_1,int *param_2)

{
  int *piVar1;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_2;
    *param_1 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  return;
}


