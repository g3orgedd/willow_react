// Source: CLCiffConversion_Layout.dll @ 45422307; FUN_45422307

void __thiscall FUN_45422307(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 2) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 2;
    if (0x3fffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    uVar1 = FUN_45421f4d(this,iVar2 + param_1);
    FUN_4542223a(this,uVar1);
  }
  return;
}


