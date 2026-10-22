// Source: CiffHelper.dll @ 408031c0; FUN_408031c0

void * __thiscall FUN_408031c0(void *this,LPCWSTR param_1)

{
  int iVar1;
  
  if (param_1 == (LPCWSTR)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = lstrlenW(param_1);
  }
  FUN_408032d1(this,iVar1,param_1);
  return this;
}


