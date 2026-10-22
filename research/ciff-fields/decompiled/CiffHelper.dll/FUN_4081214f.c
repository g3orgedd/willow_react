// Source: CiffHelper.dll @ 4081214f; FUN_4081214f

VARIANTARG * __thiscall FUN_4081214f(void *this,int *param_1)

{
  if ((*(short *)this != 9) || (param_1 != *(int **)((int)this + 8))) {
    VariantClear(this);
    *(undefined2 *)this = 9;
    *(int **)((int)this + 8) = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return this;
}


