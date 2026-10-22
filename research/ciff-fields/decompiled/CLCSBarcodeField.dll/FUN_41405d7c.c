// Source: CLCSBarcodeField.dll @ 41405d7c; FUN_41405d7c

void __thiscall FUN_41405d7c(void *this,int param_1)

{
  FUN_41404888(this);
  if (param_1 == -1) {
    param_1 = lstrlenW(*(LPCWSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return;
}


