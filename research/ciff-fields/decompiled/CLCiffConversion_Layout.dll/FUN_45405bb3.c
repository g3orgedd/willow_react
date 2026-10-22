// Source: CLCiffConversion_Layout.dll @ 45405bb3; FUN_45405bb3

void __thiscall FUN_45405bb3(void *this,rsize_t param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1 != 0) {
    pvVar1 = *(void **)this;
    if ((*(int *)((int)pvVar1 + -0xc) < 2) &&
       ((int)(*(int *)((int)pvVar1 + -8) + param_1) <= *(int *)((int)pvVar1 + -4))) {
      FUN_45404b24((void *)(*(int *)((int)pvVar1 + -8) + (int)pvVar1),*(int *)((int)pvVar1 + -4) + 1
                   ,param_2,param_1);
      *(int *)(*(int *)this + -8) = *(int *)(*(int *)this + -8) + param_1;
      *(undefined1 *)(*(int *)this + *(int *)(*(int *)this + -8)) = 0;
    }
    else {
      iVar2 = FUN_45405b4a(this,*(rsize_t *)((int)pvVar1 + -8),pvVar1,param_1,param_2);
      if (iVar2 != 0) {
        FUN_45403ffc((int *)((int)pvVar1 + -0xc));
      }
    }
  }
  return;
}


