// Source: CLARiSOFT.exe @ 00e06f2b; FUN_00e06f2b

int * __thiscall FUN_00e06f2b(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_00f35014;
    FUN_00e03eb1(this,(LPCWSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    LOCK();
    *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
    UNLOCK();
  }
  return this;
}


