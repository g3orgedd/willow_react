// Source: CLCiffConversion_Data.dll @ 45020a02; FUN_45020a02

void __thiscall FUN_45020a02(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 3) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 3;
    if (0x1fffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45020fb5("vector<T> too long");
    }
    uVar1 = FUN_45020934(this,iVar2 + param_1);
    FUN_45020985(this,uVar1);
  }
  return;
}


