// Source: CiffHelper.dll @ 4081a0e4; FUN_4081a0e4

void __thiscall FUN_4081a0e4(void *this,int *param_1,VARIANTARG *param_2)

{
  int iVar1;
  
  iVar1 = FUN_4081a042(param_1,(int *)param_1[1],param_2);
  FUN_4081d5ac(this,1);
  param_1[1] = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}


