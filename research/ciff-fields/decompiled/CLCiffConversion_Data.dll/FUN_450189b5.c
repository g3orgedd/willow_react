// Source: CLCiffConversion_Data.dll @ 450189b5; FUN_450189b5

undefined4 __cdecl FUN_450189b5(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_2;
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}


