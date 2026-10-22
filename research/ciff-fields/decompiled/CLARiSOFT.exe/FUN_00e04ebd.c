// Source: CLARiSOFT.exe @ 00e04ebd; FUN_00e04ebd

void __thiscall FUN_00e04ebd(void *this,int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  
  if (param_1 != 0) {
    pvVar1 = *(void **)this;
    if ((*(int *)((int)pvVar1 + -0xc) < 2) &&
       (*(int *)((int)pvVar1 + -8) + param_1 <= *(int *)((int)pvVar1 + -4))) {
      FUN_00e06e7b((void *)((int)pvVar1 + *(int *)((int)pvVar1 + -8) * 2),
                   *(int *)((int)pvVar1 + -4) * 2 + 2,param_2,param_1 * 2);
      *(int *)(*(int *)this + -8) = *(int *)(*(int *)this + -8) + param_1;
      *(undefined2 *)(*(int *)this + *(int *)(*(int *)this + -8) * 2) = 0;
    }
    else {
      iVar2 = FUN_00e04e44(this,*(int *)((int)pvVar1 + -8),pvVar1,param_1,param_2);
      if (iVar2 != 0) {
        FUN_00e06141((int *)((int)pvVar1 + -0xc));
      }
    }
  }
  return;
}


