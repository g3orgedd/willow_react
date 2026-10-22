// Source: CLCiffConversion_Layout.dll @ 4540d49e; FUN_4540d49e

void __thiscall FUN_4540d49e(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 5) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 5;
    if (0x7ffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar1 = FUN_4540cfe4(this,iVar2 + param_1);
    FUN_4540d27d(this,uVar1);
  }
  return;
}


