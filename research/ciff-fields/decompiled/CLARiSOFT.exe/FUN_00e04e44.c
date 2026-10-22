// Source: CLARiSOFT.exe @ 00e04e44; FUN_00e04e44

int __thiscall FUN_00e04e44(void *this,int param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = param_1 + param_3;
  if ((iVar1 < param_1) || (iVar1 < param_3)) {
    iVar2 = 0;
  }
  else if (iVar1 != 0) {
    iVar2 = FUN_00e03f98(this,iVar1);
    if (iVar2 != 0) {
      FUN_00e06e7b(*(void **)this,iVar1 * 2 + 2,param_2,param_1 * 2);
      FUN_00e06e7b((void *)(*(int *)this + param_1 * 2),(iVar1 - param_1) * 2 + 2,param_4,
                   param_3 * 2);
    }
  }
  return iVar2;
}


