// Source: CiffMgr.dll @ 68104bc6; FUN_68104bc6

void __thiscall FUN_68104bc6(void *this,int *param_1,undefined8 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_68104aed(param_1,(int *)param_1[1],param_2);
  FUN_68105811(this,1);
  param_1[1] = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}


