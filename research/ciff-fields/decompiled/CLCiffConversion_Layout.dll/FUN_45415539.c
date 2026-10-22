// Source: CLCiffConversion_Layout.dll @ 45415539; FUN_45415539

int * __thiscall FUN_45415539(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 4);
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return param_1;
}


