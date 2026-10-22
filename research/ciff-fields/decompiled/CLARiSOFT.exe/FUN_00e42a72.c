// Source: CLARiSOFT.exe @ 00e42a72; FUN_00e42a72

void __thiscall FUN_00e42a72(void *this,int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  FID_conflict__free(param_2);
  *param_1 = iVar1;
  return;
}


