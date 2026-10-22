// Source: CLCiffConversion_Layout.dll @ 45404047; FUN_45404047

void __thiscall FUN_45404047(void *this,int param_1)

{
  FUN_4540365a(this);
  if (param_1 == -1) {
    param_1 = lstrlenA(*(LPCSTR *)this);
  }
  *(int *)(*(int *)this + -8) = param_1;
  *(undefined1 *)(param_1 + *(int *)this) = 0;
  return;
}


