// Source: CLCSSmallBarcode.dll @ 42004320; FUN_42004320

void __thiscall FUN_42004320(void *this,int param_1)

{
  FUN_42003b3e(this);
  if (param_1 == -1) {
    param_1 = lstrlenW(*(LPCWSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return;
}


