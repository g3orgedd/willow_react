// Source: CiffHelper.dll @ 4081d62b; FUN_4081d62b

void __thiscall FUN_4081d62b(void *this,int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  FUN_4081d58f(param_2);
  *param_1 = iVar1;
  return;
}


