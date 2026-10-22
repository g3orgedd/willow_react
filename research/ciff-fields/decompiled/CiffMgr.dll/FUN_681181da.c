// Source: CiffMgr.dll @ 681181da; FUN_681181da

int * __thiscall FUN_681181da(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


