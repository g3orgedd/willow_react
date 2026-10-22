// Source: CLARiSOFT.exe @ 00e63686; FUN_00e63686

void * __thiscall FUN_00e63686(void *this,byte param_1)

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


