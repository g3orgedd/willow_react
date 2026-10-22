// Source: CLCiffConversion_Layout.dll @ 4540d44b; FUN_4540d44b

void __thiscall FUN_4540d44b(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0x18) < param_1) {
    iVar1 = (*(int *)((int)this + 4) - *(int *)this) / 0x18;
    if (0xaaaaaaaU - iVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar2 = FUN_4540cf85(this,iVar1 + param_1);
    FUN_4540d201(this,uVar2);
  }
  return;
}


