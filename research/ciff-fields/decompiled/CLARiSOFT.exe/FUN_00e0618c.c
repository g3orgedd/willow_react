// Source: CLARiSOFT.exe @ 00e0618c; FUN_00e0618c

void __thiscall FUN_00e0618c(void *this,int param_1)

{
  FUN_00e04f37(this);
  if (param_1 == -1) {
    param_1 = lstrlenW(*(LPCWSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined2 *)(*(int *)this + param_1 * 2) = 0;
  return;
}


