// Source: CLCiffConversion_Layout.dll @ 454037db; FUN_454037db

int __thiscall FUN_454037db(void *this,int param_1)

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
    iVar3 = FUN_45402e54(this,param_1);
    if (iVar3 == 0) {
      return 0;
    }
    FUN_45404b24(*(void **)this,param_1 + 1,pvVar1,iVar2 + 1);
    *(int *)(*(int *)this + -8) = iVar2;
    FUN_45403ffc((int *)((int)pvVar1 + -0xc));
  }
  return *(int *)this;
}


