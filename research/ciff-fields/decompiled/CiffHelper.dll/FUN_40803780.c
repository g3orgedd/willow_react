// Source: CiffHelper.dll @ 40803780; FUN_40803780

void __thiscall FUN_40803780(void *this,uint param_1)

{
  if (param_1 <= 0x15555554U - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4082ca95("list<T> too long");
}


