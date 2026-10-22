// Source: CLCiffConversion_Layout.dll @ 4540d58f; FUN_4540d58f

void __thiscall FUN_4540d58f(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1;
  uVar3 = *(int *)((int)this + 4) - *(int *)this >> 2;
  if (param_1 < uVar3) {
    iVar2 = *(int *)((int)this + 4) + (param_1 - uVar3) * 4;
  }
  else {
    if (param_1 <= uVar3) {
      return;
    }
    FUN_45422307(this,param_1 - uVar3);
    param_1 = 0;
    FUN_4540a2b5(*(undefined4 **)((int)this + 4),
                 uVar1 - (*(int *)((int)this + 4) - *(int *)this >> 2),&param_1);
    iVar2 = *(int *)((int)this + 4) + (uVar1 - (*(int *)((int)this + 4) - *(int *)this >> 2)) * 4;
  }
  *(int *)((int)this + 4) = iVar2;
  return;
}


