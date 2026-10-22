// Source: CLCSSmallBarcode.dll @ 42033b1d; FUN_42033b1d

void __thiscall FUN_42033b1d(void *this,int param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_10;
  
  iVar6 = 0;
  bVar2 = true;
  uVar5 = *(uint *)((int)this + 0xac) & 0x1f;
  param_3 = (uint *)(*(int *)((int)this + 0x2c) +
                    (((*(int *)((int)this + 0x20) - *(uint *)((int)this + 0xac)) + -1) *
                     *(int *)((int)this + 0x14) +
                    ((int)((int)param_3 + ((int)param_3 >> 0x1f & 0x1fU)) >> 5)) * 4);
  iVar3 = FUN_4202c062(this,param_4);
  if (iVar3 != 0) {
    FUN_42027a20(this,param_3,uVar5,param_4,param_2);
    uVar5 = uVar5 + iVar3;
    if (0x1f < (int)uVar5) {
      iVar4 = uVar5 + ((int)uVar5 >> 0x1f & 0x1fU);
      uVar5 = uVar5 & 0x1f;
      param_3 = param_3 + (iVar4 >> 5);
    }
  }
  uVar1 = param_4 - iVar3;
  local_10 = 0;
  if (0 < param_2) {
    do {
      if ((*(uint *)(param_1 + ((int)(local_10 + (local_10 >> 0x1f & 0x1fU)) >> 5) * 4) &
          0x80000000U >> ((byte)local_10 & 0x1f)) == 0) {
        if ((bVar2) && (iVar6 != 0)) {
          FUN_42027a20(this,param_3,uVar5,uVar1,iVar6);
          param_3 = param_3 + -(*(int *)((int)this + 0x14) * iVar6);
          iVar6 = 0;
        }
        bVar2 = false;
      }
      else {
        if ((!bVar2) && (iVar6 != 0)) {
          FUN_42027531(this,param_3,uVar5,uVar1,iVar6);
          param_3 = param_3 + -(*(int *)((int)this + 0x14) * iVar6);
          iVar6 = 0;
        }
        bVar2 = true;
      }
      iVar6 = iVar6 + 1;
      local_10 = local_10 + 1;
    } while (local_10 < param_2);
    if (iVar6 != 0) {
      if (bVar2) {
        FUN_42027a20(this,param_3,uVar5,uVar1,iVar6);
      }
      else {
        FUN_42027531(this,param_3,uVar5,uVar1,iVar6);
      }
    }
  }
  return;
}


