// Source: CiffMgr.dll @ 681047b5; FUN_681047b5

void __thiscall FUN_681047b5(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 4) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 4;
    if (0xfffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_68130e66("vector<T> too long");
    }
    uVar1 = FUN_681046fc(this,iVar2 + param_1);
    FUN_68104729(this,uVar1);
  }
  return;
}


