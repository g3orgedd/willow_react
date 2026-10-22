// Source: CiffHelper.dll @ 408035a4; FUN_408035a4

int __thiscall FUN_408035a4(void *this,int param_1)

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
    iVar3 = FUN_40803262(this,param_1);
    if (iVar3 == 0) {
      return 0;
    }
    FUN_40803806(*(void **)this,param_1 * 2 + 2,pvVar1,iVar2 * 2 + 2);
    *(int *)(*(int *)this + -8) = iVar2;
    FUN_408036fd((int *)((int)pvVar1 + -0xc));
  }
  return *(int *)this;
}


