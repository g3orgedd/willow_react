// Source: CLCSBarcodeField.dll @ 41407c9d; FUN_41407c9d

int * __thiscall FUN_41407c9d(void *this,int *param_1)

{
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    *(int *)this = *param_1;
    *param_1 = 0;
  }
  return this;
}


