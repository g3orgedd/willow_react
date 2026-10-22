// Source: CLCiffConversion_Data.dll @ 45019ad4; FUN_45019ad4

void __thiscall FUN_45019ad4(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0xc) < param_1) {
    iVar1 = (*(int *)((int)this + 4) - *(int *)this) / 0xc;
    if (0x15555555U - iVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45020fb5("vector<T> too long");
    }
    uVar2 = FUN_45019a26(this,iVar1 + param_1);
    FUN_45019a58(this,uVar2);
  }
  return;
}


