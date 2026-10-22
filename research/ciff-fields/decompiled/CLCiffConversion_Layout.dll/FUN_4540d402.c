// Source: CLCiffConversion_Layout.dll @ 4540d402; FUN_4540d402

void __thiscall FUN_4540d402(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 1) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 1;
    if (0x7fffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar1 = FUN_4540cf59(this,iVar2 + param_1);
    FUN_4540d191(this,uVar1);
  }
  return;
}


