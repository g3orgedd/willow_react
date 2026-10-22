// Source: CLCiffConversion_Data.dll @ 450041c1; FUN_450041c1

void __thiscall FUN_450041c1(void *this,int param_1)

{
  FUN_4500363c(this);
  if (param_1 == -1) {
    param_1 = lstrlenW(*(LPCWSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return;
}


