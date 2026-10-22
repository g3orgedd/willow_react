// Source: CLCiffConversion_Layout.dll @ 45407112; FUN_45407112

void __thiscall FUN_45407112(void *this,uint param_1)

{
  if (param_1 <= 0x15555554U - *(int *)((int)this + 4)) {
    *(uint *)((int)this + 4) = *(int *)((int)this + 4) + param_1;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45429486("list<T> too long");
}


