// Source: CLCSTextBasedField.dll @ 42405efb; FUN_42405efb

void __thiscall FUN_42405efb(void *this,int param_1)

{
  FUN_42405009(this);
  if (param_1 == -1) {
    param_1 = lstrlenW(*(LPCWSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return;
}


