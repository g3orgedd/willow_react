// Source: CLCiffConversion_Data.dll @ 45005a5b; FUN_45005a5b

int * __thiscall FUN_45005a5b(void *this,byte param_1)

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


