// Source: CiffHelper.dll @ 4081d5ac; FUN_4081d5ac

void __thiscall FUN_4081d5ac(void *this,uint param_1)

{
  if (param_1 <= 0xaaaaaa9U - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4082ca95("list<T> too long");
}


