// Source: CLCiffConversion_Layout.dll @ 454077ad; FUN_454077ad

int * __thiscall FUN_454077ad(void *this,int *param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  
  pvVar1 = *(void **)this;
  pvVar2 = (void *)*param_1;
  if (pvVar1 != pvVar2) {
    if (((*(int *)((int)pvVar1 + -0xc) < 0) &&
        ((undefined *)((int)pvVar1 + -0xc) != PTR_DAT_4545d10c)) ||
       (*(int *)((int)pvVar2 + -0xc) < 0)) {
      FUN_45402f40(this,*(rsize_t *)((int)pvVar2 + -8),pvVar2);
    }
    else {
      FUN_45403fc8(this);
      iVar3 = *param_1;
      *(int *)this = iVar3;
      piVar4 = (int *)(iVar3 + -0xc);
      LOCK();
      *piVar4 = *piVar4 + 1;
      UNLOCK();
    }
  }
  return this;
}


