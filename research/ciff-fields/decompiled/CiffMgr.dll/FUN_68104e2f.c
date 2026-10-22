// Source: CiffMgr.dll @ 68104e2f; FUN_68104e2f

VARIANTARG * __thiscall FUN_68104e2f(void *this,int *param_1)

{
  if ((*(short *)this != 9) || (param_1 != *(int **)((int)this + 8))) {
    FUN_681024ee(this);
    *(undefined2 *)this = 9;
    *(int **)((int)this + 8) = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
  }
  return this;
}


