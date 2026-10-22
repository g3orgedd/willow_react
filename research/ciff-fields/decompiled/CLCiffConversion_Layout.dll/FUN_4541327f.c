// Source: CLCiffConversion_Layout.dll @ 4541327f; FUN_4541327f

int * __thiscall FUN_4541327f(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


