// Source: CiffHelper.dll @ 4080be61; FUN_4080be61

int * __thiscall FUN_4080be61(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


