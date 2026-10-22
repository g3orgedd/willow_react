// Source: CiffHelper.dll @ 40811e4c; FUN_40811e4c

void __thiscall FUN_40811e4c(void *this,int *param_1,undefined8 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40811df4(param_1,(int *)param_1[1],param_2);
  FUN_4081959b(this,1);
  param_1[1] = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}


