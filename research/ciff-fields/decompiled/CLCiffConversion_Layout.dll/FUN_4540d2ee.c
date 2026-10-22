// Source: CLCiffConversion_Layout.dll @ 4540d2ee; FUN_4540d2ee

void __thiscall FUN_4540d2ee(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)((int)this + 4);
  if ((uint)(*(int *)((int)this + 8) - iVar1) < param_1) {
    if ((*(int *)this - iVar1) - 1U < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar2 = FUN_4540cf31(this,(iVar1 - *(int *)this) + param_1);
    FUN_4540d011(this,uVar2);
  }
  return;
}


