// Source: CLCiffConversion_Layout.dll @ 454066f3; FUN_454066f3

int * __thiscall FUN_454066f3(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


