// Source: CLCSRichTextBlockField.dll @ 41804fa4; FUN_41804fa4

int * __thiscall FUN_41804fa4(void *this,int *param_1)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  
  pvVar1 = *(void **)this;
  pvVar2 = (void *)*param_1;
  if (pvVar1 != pvVar2) {
    if (((*(int *)((int)pvVar1 + -0xc) < 0) &&
        ((undefined *)((int)pvVar1 + -0xc) != PTR_DAT_4184d10c)) ||
       (*(int *)((int)pvVar2 + -0xc) < 0)) {
      FUN_41801856(this,*(int *)((int)pvVar2 + -8),pvVar2);
    }
    else {
      FUN_4180235b(this);
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


