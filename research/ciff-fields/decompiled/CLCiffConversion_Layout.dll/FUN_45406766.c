// Source: CLCiffConversion_Layout.dll @ 45406766; FUN_45406766

void * __thiscall FUN_45406766(void *this,byte param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}


