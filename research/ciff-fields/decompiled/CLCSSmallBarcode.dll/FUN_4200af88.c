// Source: CLCSSmallBarcode.dll @ 4200af88; FUN_4200af88

int * __thiscall FUN_4200af88(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


