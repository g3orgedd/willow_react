// Source: CiffMgr.dll @ 68105811; FUN_68105811

void __thiscall FUN_68105811(void *this,uint param_1)

{
  if (param_1 <= 0x7fffffeU - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_68130e66("list<T> too long");
}


