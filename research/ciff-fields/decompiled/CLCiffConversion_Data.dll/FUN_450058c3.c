// Source: CLCiffConversion_Data.dll @ 450058c3; FUN_450058c3

int * __thiscall FUN_450058c3(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


