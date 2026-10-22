// Source: CLCiffConversion_Layout.dll @ 4540d377; FUN_4540d377

void __thiscall FUN_4540d377(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 3) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 3;
    if (0x1fffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar1 = FUN_4540cfb7(this,iVar2 + param_1);
    FUN_4540d0b3(this,uVar1);
  }
  return;
}


