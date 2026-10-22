// Source: CLCiffConversion_Data.dll @ 4500201a; FUN_4500201a

int * __thiscall FUN_4500201a(void *this,int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + -0xc) < 0) {
    *(undefined **)this = PTR_DAT_4505101c;
    FUN_45002365(this,(LPCWSTR)*param_1);
  }
  else {
    *(int *)this = iVar1;
    LOCK();
    *(int *)(iVar1 + -0xc) = *(int *)(iVar1 + -0xc) + 1;
    UNLOCK();
  }
  return this;
}


