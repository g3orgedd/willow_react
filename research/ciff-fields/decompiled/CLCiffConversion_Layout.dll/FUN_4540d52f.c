// Source: CLCiffConversion_Layout.dll @ 4540d52f; FUN_4540d52f

void __thiscall FUN_4540d52f(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1;
  uVar3 = *(int *)((int)this + 4) - *(int *)this >> 1;
  if (param_1 < uVar3) {
    iVar2 = *(int *)((int)this + 4) + (param_1 - uVar3) * 2;
  }
  else {
    if (param_1 <= uVar3) {
      return;
    }
    FUN_4540d32e(this,param_1 - uVar3);
    param_1 = 0;
    FUN_4540a293(*(undefined2 **)((int)this + 4),
                 uVar1 - (*(int *)((int)this + 4) - *(int *)this >> 1),(undefined2 *)&param_1);
    iVar2 = *(int *)((int)this + 4) + (uVar1 - (*(int *)((int)this + 4) - *(int *)this >> 1)) * 2;
  }
  *(int *)((int)this + 4) = iVar2;
  return;
}


