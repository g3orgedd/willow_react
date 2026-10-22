// Source: CLCSTextBasedField.dll @ 4241115f; FUN_4241115f

int * __thiscall FUN_4241115f(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


