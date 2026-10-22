// Source: CiffMgr.dll @ 68104866; FUN_68104866

void __thiscall FUN_68104866(void *this,VARIANTARG *param_1)

{
  VARIANTARG *pVVar1;
  int iVar2;
  
  pVVar1 = *(VARIANTARG **)((int)this + 4);
  if ((param_1 < pVVar1) && (*(VARIANTARG **)this <= param_1)) {
    iVar2 = *(int *)this;
    if (pVVar1 == *(VARIANTARG **)((int)this + 8)) {
      FUN_681047b5(this,1);
    }
    FUN_68103bfb(*(undefined2 **)((int)this + 4),
                 (VARIANTARG *)(((int)param_1 - iVar2 & 0xfffffff0U) + *(int *)this));
  }
  else {
    if (pVVar1 == *(VARIANTARG **)((int)this + 8)) {
      FUN_681047b5(this,1);
    }
    FUN_68103bfb(*(undefined2 **)((int)this + 4),param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x10;
  return;
}


