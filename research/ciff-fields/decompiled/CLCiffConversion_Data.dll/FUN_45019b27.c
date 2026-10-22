// Source: CLCiffConversion_Data.dll @ 45019b27; FUN_45019b27

void __thiscall FUN_45019b27(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar1) && (*(undefined4 **)this <= param_1)) {
    iVar2 = *(int *)this;
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_45019ad4(this,1);
    }
    param_1 = (undefined4 *)((((int)param_1 - iVar2) / 0xc) * 0xc + *(int *)this);
  }
  else if (puVar1 == *(undefined4 **)((int)this + 8)) {
    FUN_45019ad4(this,1);
  }
  puVar1 = *(undefined4 **)((int)this + 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0xc;
  return;
}


