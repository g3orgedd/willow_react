// Source: CiffHelper.dll @ 408034e6; FUN_408034e6

void __thiscall FUN_408034e6(void *this,int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1 != 0) {
    pvVar1 = *(void **)this;
    if ((*(int *)((int)pvVar1 + -0xc) < 2) &&
       (*(int *)((int)pvVar1 + -8) + param_1 <= *(int *)((int)pvVar1 + -4))) {
      FUN_40803806((void *)((int)pvVar1 + *(int *)((int)pvVar1 + -8) * 2),
                   *(int *)((int)pvVar1 + -4) * 2 + 2,param_2,param_1 * 2);
      *(int *)(*(int *)this + -8) = *(int *)(*(int *)this + -8) + param_1;
      *(undefined2 *)(*(int *)this + *(int *)(*(int *)this + -8) * 2) = 0;
    }
    else {
      iVar2 = FUN_4080346d(this,*(int *)((int)pvVar1 + -8),pvVar1,param_1,param_2);
      if (iVar2 != 0) {
        FUN_408036fd((int *)((int)pvVar1 + -0xc));
      }
    }
  }
  return;
}


