// Source: CiffMgr.dll @ 681136ca; FUN_681136ca

void __thiscall FUN_681136ca(void *this,uint param_1)

{
  if (param_1 <= (uint)(*(int *)((int)this + 8) - *(int *)this >> 4)) {
    return;
  }
  if (param_1 < 0x10000000) {
    FUN_68104729(this,param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_68130e66("vector<T> too long");
}


