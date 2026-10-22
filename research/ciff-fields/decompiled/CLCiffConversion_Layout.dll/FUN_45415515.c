// Source: CLCiffConversion_Layout.dll @ 45415515; FUN_45415515

int * __thiscall FUN_45415515(void *this,int *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 0xc);
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return param_1;
}


