// Source: CiffMgr.dll @ 681161f3; FUN_681161f3

void __thiscall FUN_681161f3(void *this,uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((uint)(*(int *)((int)this + 8) - *(int *)((int)this + 4) >> 2) < param_1) {
    iVar2 = *(int *)((int)this + 4) - *(int *)this >> 2;
    if (0x3fffffffU - iVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_68130e66("vector<T> too long");
    }
    uVar1 = FUN_68116149(this,iVar2 + param_1);
    FUN_68116176(this,uVar1);
  }
  return;
}


