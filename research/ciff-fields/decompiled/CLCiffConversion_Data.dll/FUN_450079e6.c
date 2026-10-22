// Source: CLCiffConversion_Data.dll @ 450079e6; FUN_450079e6

void __thiscall FUN_450079e6(void *this,uint param_1)

{
  if (param_1 <= 0x15555554U - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45020fb5("list<T> too long");
}


