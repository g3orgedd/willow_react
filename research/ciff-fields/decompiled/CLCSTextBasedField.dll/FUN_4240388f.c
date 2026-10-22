// Source: CLCSTextBasedField.dll @ 4240388f; FUN_4240388f

int * __thiscall FUN_4240388f(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_424b9014;
    FUN_42403baf(this,(LPCWSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    LOCK();
    *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
    UNLOCK();
  }
  return this;
}


