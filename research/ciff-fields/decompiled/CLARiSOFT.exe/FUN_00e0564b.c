// Source: CLARiSOFT.exe @ 00e0564b; FUN_00e0564b

int __thiscall FUN_00e0564b(void *this,int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  pvVar1 = *(void **)this;
  if ((1 < *(int *)((int)pvVar1 + -0xc)) || (*(int *)((int)pvVar1 + -4) < param_1)) {
    iVar2 = *(int *)((int)pvVar1 + -8);
    if (param_1 < iVar2) {
      param_1 = iVar2;
    }
    iVar3 = FUN_00e03f98(this,param_1);
    if (iVar3 == 0) {
      return 0;
    }
    FUN_00e06e7b(*(void **)this,param_1 * 2 + 2,pvVar1,iVar2 * 2 + 2);
    *(int *)(*(int *)this + -8) = iVar2;
    FUN_00e06141((int *)((int)pvVar1 + -0xc));
  }
  return *(int *)this;
}


