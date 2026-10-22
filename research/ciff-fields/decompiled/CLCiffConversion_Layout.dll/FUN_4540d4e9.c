// Source: CLCiffConversion_Layout.dll @ 4540d4e9; FUN_4540d4e9

void __thiscall FUN_4540d4e9(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)this;
  uVar2 = *(int *)((int)this + 4) - iVar1;
  if (uVar2 <= param_1) {
    if (param_1 <= uVar2) {
      return;
    }
    FUN_4540d2ee(this,(iVar1 - *(int *)((int)this + 4)) + param_1);
    FUN_45429f70(*(uint **)((int)this + 4),0,(*(int *)this - *(int *)((int)this + 4)) + param_1);
    iVar1 = *(int *)this;
  }
  *(uint *)((int)this + 4) = iVar1 + param_1;
  return;
}


