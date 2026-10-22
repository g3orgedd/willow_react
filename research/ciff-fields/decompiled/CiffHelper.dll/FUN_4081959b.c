// Source: CiffHelper.dll @ 4081959b; FUN_4081959b

void __thiscall FUN_4081959b(void *this,uint param_1)

{
  if (param_1 <= 0x7fffffeU - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4082ca95("list<T> too long");
}


