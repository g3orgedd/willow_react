// Source: CLCiffConversion_Layout.dll @ 45402a2f; FUN_45402a2f

int * __thiscall FUN_45402a2f(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_4545d110;
    FUN_45402cd0(this,(LPCSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    LOCK();
    *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
    UNLOCK();
  }
  return this;
}


