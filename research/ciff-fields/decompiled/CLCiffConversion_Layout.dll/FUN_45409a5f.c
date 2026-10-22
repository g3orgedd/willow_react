// Source: CLCiffConversion_Layout.dll @ 45409a5f; FUN_45409a5f

uint __thiscall FUN_45409a5f(void *this,undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar2;
  
  bVar1 = FUN_45404d51(this,param_1);
  uVar2 = CONCAT31(extraout_var,bVar1);
  if (bVar1) {
LAB_45409a73:
    uVar2 = CONCAT31((int3)(uVar2 >> 8),1);
  }
  else {
    bVar1 = FUN_45409aa0(this,param_1);
    uVar2 = CONCAT31(extraout_var_00,bVar1);
    if (!bVar1) {
      uVar2 = param_1[1];
      if (*(int *)((int)this + 4) < (int)uVar2) goto LAB_45409a73;
      if (*(int *)((int)this + 4) <= (int)uVar2) {
        return CONCAT31((int3)((uint)*(int *)((int)this + 8) >> 8),
                        *(int *)((int)this + 8) < (int)param_1[2]);
      }
    }
    uVar2 = uVar2 & 0xffffff00;
  }
  return uVar2;
}


