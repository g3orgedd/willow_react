// Source: CiffMgr.dll @ 68105d97; FUN_68105d97

void __thiscall FUN_68105d97(void *this,int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  FUN_6810578a(param_2);
  *param_1 = iVar1;
  return;
}


