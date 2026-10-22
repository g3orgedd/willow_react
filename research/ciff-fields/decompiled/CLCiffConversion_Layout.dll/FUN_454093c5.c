// Source: CLCiffConversion_Layout.dll @ 454093c5; FUN_454093c5

void __thiscall FUN_454093c5(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((uint)((*(int *)((int)this + 8) - *(int *)((int)this + 4)) / 0x14) < param_1) {
    iVar1 = (*(int *)((int)this + 4) - *(int *)this) / 0x14;
    if (0xcccccccU - iVar1 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar2 = FUN_45409269(this,iVar1 + param_1);
    FUN_4540929b(this,uVar2);
  }
  return;
}


