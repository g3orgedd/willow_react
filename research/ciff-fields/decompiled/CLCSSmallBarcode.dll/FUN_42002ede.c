// Source: CLCSSmallBarcode.dll @ 42002ede; FUN_42002ede

int * __thiscall FUN_42002ede(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_420b7110;
    FUN_420031e5(this,(LPCWSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    LOCK();
    *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
    UNLOCK();
  }
  return this;
}


