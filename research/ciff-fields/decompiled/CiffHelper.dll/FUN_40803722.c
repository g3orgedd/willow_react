// Source: CiffHelper.dll @ 40803722; FUN_40803722

void __thiscall FUN_40803722(void *this,int param_1)

{
  FUN_40803560(this);
  if (param_1 == -1) {
    param_1 = lstrlenW(*(LPCWSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return;
}


