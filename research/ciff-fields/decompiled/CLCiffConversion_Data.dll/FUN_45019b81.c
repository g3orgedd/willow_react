// Source: CLCiffConversion_Data.dll @ 45019b81; FUN_45019b81

void __thiscall FUN_45019b81(void *this,uint param_1)

{
  if (param_1 <= (uint)((*(int *)((int)this + 8) - *(int *)this) / 0xc)) {
    return;
  }
  if (param_1 < 0x15555556) {
    FUN_45019a58(this,param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45020fb5("vector<T> too long");
}


